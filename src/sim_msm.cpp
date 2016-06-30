// [[Rcpp::depends(RcppArmadillo)]]

#include <algorithm>
#include <RcppArmadillo.h>
#include "rand.h"
#include "pv.h"
using namespace Rcpp;

// Random times to next states
arma::vec rtjumps(arma::mat lb, arma::vec loc_x, arma::vec anc1,
                    arma::vec trans, std::vector<std::string> d,
                    int nstates){
  arma::vec time_jumps(nstates);
  for (int j = 0; j < nstates; ++j){
    if (trans(j) == 0){
      time_jumps(j) = NAN;
    }
    else{
      double loc = dot(loc_x, lb.row(trans(j) - 1));
      time_jumps(j) = rsurv(loc, anc1(trans(j) - 1), d[trans(j) - 1]);
    }
  }
  return time_jumps;
}

// Return Polynomial Constants
std::vector<double> poly_const(std::vector<double> &a, double xb,
                                  arma::vec coef, int start, int p){
  a.push_back(xb + coef(start));
  for (int j = start + 1; j <= start + p; ++j){
    a.push_back(coef(j));
  }
  return a;
}

// Calculate Present Value from t1 to t2 With Piecewise Polynomials
// [[Rcpp::export]]
double pv_splines(double t1, double t2, int state, double r,
               arma::vec x, arma::vec beta, arma::vec poly_beta,
               arma::vec poly_deg, arma::vec knots){

  int n = poly_deg.n_elem;
  knots = knots + t1;
  knots(n) = t2;
  knots = sort(knots);
  double xb = dot(beta, x);
  std::vector<double> a;
  double pv = 0;
  int coef_start = 0;
  for (int i = 0; i < n; ++i){
    if (knots(i + 1) > t2){
      break;
    }
    a = poly_const(a, xb, poly_beta, coef_start, poly_deg(i));
    pv += pv_poly(r, poly_deg(i), knots(i), knots(i + 1),
                 knots(i), a);
    a.clear();
    coef_start = coef_start + poly_deg(i) + 1;
  }
  return pv;
}

// [[Rcpp::export]]
bool notinvec(int item, std::vector<int> v){
  return std::find(v.begin(), v.end(), item) == v.end();
}

// [[Rcpp::export]]
double nxttime(double current_time, double time_jump, double maxt){
  double next_time;
  if (current_time + time_jump > maxt){
    next_time = maxt;
  }
  else {
    next_time = current_time + time_jump;
  }
  return next_time;
}

// [[Rcpp::export]]
arma::mat matS(int index, arma::cube cube, int ntrans, int k){
  arma::mat par(ntrans, k);
  for (int i = 0; i < ntrans; ++i){
    par.row(i) = cube.slice(i).row(index);
  }
  return par;
}

// [[Rcpp::export]]
arma::vec updateAge(arma::vec x, double age, int col){
  x(col) = age;
  return x;
}

//' @export
// [[Rcpp::export]]
List sim_msmC(arma::cube loc_beta, arma::mat loc_x,
              std::vector<std::string> dist, arma::mat tmat,
              arma::vec anc1, std::vector<int> absorbing,
              int maxt, int maxage, int agecol = -1) {
  // Initialize
  int N = loc_x.n_rows;
  int ntrans = loc_beta.n_slices;
  int k_lb = loc_beta.slice(0).n_cols;
  int nsims = loc_beta.slice(0).n_rows;
  int nstates = tmat.n_cols;

  // Storage vectors
  std::vector<int> id;
  std::vector<int> sim;
  std::vector<double> age;
  std::vector<int> state;
  std::vector<int> final;
  std::vector<double> time;

  // Begin simulation
  int counter = 0;

  // Simulate for parameter draws 1 to nsims
  for (int s = 0; s < nsims; ++s){
    arma::mat loc_beta_s = matS(s, loc_beta, ntrans, k_lb);

    // Simulate for individuals 1 to N
    for (int i = 0; i < N; ++i){
      // Values for time = 0
      id.push_back(i);
      sim.push_back(s);
      state.push_back(0);
      final.push_back(0);
      time.push_back(0.0);

      // Simulate for patient i
      arma::vec loc_xi = loc_x.row(i).t();
      if (agecol >= 0){
        age.push_back(loc_xi(agecol));
      }
      else{
        age.push_back(0);
      }
      while (notinvec(state[counter], absorbing) && time[counter] < maxt &&
             age[counter] < maxage){
        // Current iteration
        arma::vec time_jumps = rtjumps(loc_beta_s, loc_xi, anc1,
                                       tmat.row(state[counter]).t(),
                                       dist, nstates);
        arma::uword next_state;
        double time_jump = time_jumps.min(next_state);
        double newage = age[counter] + time_jump;
        double current_time = time[counter] + time_jump;
        if (current_time > maxt || newage > maxage){
          state.push_back(state[counter]);
          time_jump = std::min(time_jump, std::min(maxt - time[counter],
                                                   maxage - age[counter]));
          newage = age[counter] + time_jump;
        }
        else {
          state.push_back(next_state);
        }
        time.push_back(time[counter] + time_jump);
        id.push_back(i);
        sim.push_back(s);
        final.push_back(0);

        // Move to next iteration and update patient
        if (agecol >= 0){
          loc_xi(agecol) = newage;
        }
        age.push_back(newage);
        ++ counter;
      }
      final[counter] = 1;
      ++ counter;
    }
  }
  if (agecol >= 0){
    return List::create(id, sim, age, state, final, time);
  }
  else{
    return List::create(id, sim, state, final, time);
  }
}

//' @export
// [[Rcpp::export]]
arma::vec sim_msm_pvC(arma::vec id, arma::vec sim, arma::vec age, arma::vec state,
                      arma::vec final, arma::vec time, std::vector<int> absorbing,
                      double r, arma::mat x, int agecol,
                   arma::mat beta, arma::mat poly_beta, arma::mat poly_deg,
                   arma::mat knots) {
  // Initialize/store
  int N = time.n_elem;
  arma::vec pv(N);

  // Loop
  for (int i = 0; i < N; ++i){
    arma::vec xi = x.row(id(i)).t();
    if (agecol >= 0){
      xi(agecol) = age(i);
    }
    if (final(i) == 1){
      if (!notinvec(state(i), absorbing)){
        pv(i) = dot(beta.row(state(i)).t(), x.row(id(i)).t()) * exp(-r * time(i));
      }
      else{
        pv(i) = 0;
      }
    }
    else{
      pv(i) = pv_splines(time(i), time(i + 1), state(i), r,
         xi, beta.row(state(i)).t(),
         poly_beta.row(state(i)).t(),
         poly_deg.row(state(i)).t(), knots.row(state(i)).t());
    }
  }
  return pv;
}

// This function is for checking pmatrix
// [[Rcpp::export]]
std::vector<double> sim_state_t(std::vector<int> state, std::vector<double> time,
                                std::vector<int> final, double t,
                                int simindivs) {
  // Initialize
  int n = time.size();
  std::vector<double> state_t;
  state_t.reserve(simindivs);

  // State at time t
  for (int i = 0; i < n; ++i ){
    if (t > time[i] & t < time[i + 1]){
      state_t.push_back(state[i]);
    }
    else if (t > time[i] & final[i] == 1) {
      state_t.push_back(state[i]);
    }
  }

  // Return
  return state_t;
}

//' @export
// [[Rcpp::export]]
std::vector<double> sim_transprobC(std::vector<int> state, std::vector<double> time,
                                   std::vector<int> final, std::vector<double> t,
                                   int simindivs, int nstates) {
  // Initialize
  int n = time.size();
  int T = t.size();
  std::vector<double> state_prop(nstates * T, 0.0);

  for (int j = 0; j < T; ++j){
    int nj = j * nstates;
    // State at time t
    for (int i = 0; i < n; ++i ){
      if (t[j] > time[i] & t[j] < time[i + 1]){
        state_prop[nj + state[i]] = state_prop[nj + state[i]] + 1;
      }
      else if (t[j] > time[i] & final[i] == 1) {
        state_prop[nj + state[i]] = state_prop[nj + state[i]] + 1;
      }
    }
  }

  // Convert sum to proportion
  for (int i = 0; i < nstates * T; ++i){
    state_prop[i] = state_prop[i]/simindivs;
  }

  // Return
  return state_prop;
}
