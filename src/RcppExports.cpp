// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// matrixC
arma::mat matrixC(arma::vec v, int nrow, int ncol);
RcppExport SEXP cea_matrixC(SEXP vSEXP, SEXP nrowSEXP, SEXP ncolSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< arma::vec >::type v(vSEXP);
    Rcpp::traits::input_parameter< int >::type nrow(nrowSEXP);
    Rcpp::traits::input_parameter< int >::type ncol(ncolSEXP);
    __result = Rcpp::wrap(matrixC(v, nrow, ncol));
    return __result;
END_RCPP
}
// markovCohortC
List markovCohortC(arma::rowvec z0, int ncycles, double discount, int nsims, arma::cube P, arma::cube costs, arma::cube qol, arma::vec P_indx, arma::vec cost_indx, arma::vec qol_indx);
RcppExport SEXP cea_markovCohortC(SEXP z0SEXP, SEXP ncyclesSEXP, SEXP discountSEXP, SEXP nsimsSEXP, SEXP PSEXP, SEXP costsSEXP, SEXP qolSEXP, SEXP P_indxSEXP, SEXP cost_indxSEXP, SEXP qol_indxSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< arma::rowvec >::type z0(z0SEXP);
    Rcpp::traits::input_parameter< int >::type ncycles(ncyclesSEXP);
    Rcpp::traits::input_parameter< double >::type discount(discountSEXP);
    Rcpp::traits::input_parameter< int >::type nsims(nsimsSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type P(PSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type costs(costsSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type qol(qolSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type P_indx(P_indxSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type cost_indx(cost_indxSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type qol_indx(qol_indxSEXP);
    __result = Rcpp::wrap(markovCohortC(z0, ncycles, discount, nsims, P, costs, qol, P_indx, cost_indx, qol_indx));
    return __result;
END_RCPP
}
// factorialC
unsigned int factorialC(unsigned int n);
RcppExport SEXP cea_factorialC(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    __result = Rcpp::wrap(factorialC(n));
    return __result;
END_RCPP
}
// pv1
double pv1(double t1, double t2, double a, double r);
RcppExport SEXP cea_pv1(SEXP t1SEXP, SEXP t2SEXP, SEXP aSEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type t1(t1SEXP);
    Rcpp::traits::input_parameter< double >::type t2(t2SEXP);
    Rcpp::traits::input_parameter< double >::type a(aSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    __result = Rcpp::wrap(pv1(t1, t2, a, r));
    return __result;
END_RCPP
}
// exponent_int
double exponent_int(double r, unsigned int p, double t, double h);
RcppExport SEXP cea_exponent_int(SEXP rSEXP, SEXP pSEXP, SEXP tSEXP, SEXP hSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type t(tSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    __result = Rcpp::wrap(exponent_int(r, p, t, h));
    return __result;
END_RCPP
}
// poly_int
double poly_int(double r, unsigned int p, double t, double h, std::vector<double> a);
RcppExport SEXP cea_poly_int(SEXP rSEXP, SEXP pSEXP, SEXP tSEXP, SEXP hSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type t(tSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a(aSEXP);
    __result = Rcpp::wrap(poly_int(r, p, t, h, a));
    return __result;
END_RCPP
}
// pv_poly
double pv_poly(double r, unsigned int p, double t1, double t2, double h, std::vector<double> a);
RcppExport SEXP cea_pv_poly(SEXP rSEXP, SEXP pSEXP, SEXP t1SEXP, SEXP t2SEXP, SEXP hSEXP, SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type t1(t1SEXP);
    Rcpp::traits::input_parameter< double >::type t2(t2SEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a(aSEXP);
    __result = Rcpp::wrap(pv_poly(r, p, t1, t2, h, a));
    return __result;
END_RCPP
}
// qgompertzC
double qgompertzC(double p, double shape, double rate);
RcppExport SEXP cea_qgompertzC(SEXP pSEXP, SEXP shapeSEXP, SEXP rateSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type p(pSEXP);
    Rcpp::traits::input_parameter< double >::type shape(shapeSEXP);
    Rcpp::traits::input_parameter< double >::type rate(rateSEXP);
    __result = Rcpp::wrap(qgompertzC(p, shape, rate));
    return __result;
END_RCPP
}
// rgompertzC
double rgompertzC(double shape, double rate);
RcppExport SEXP cea_rgompertzC(SEXP shapeSEXP, SEXP rateSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type shape(shapeSEXP);
    Rcpp::traits::input_parameter< double >::type rate(rateSEXP);
    __result = Rcpp::wrap(rgompertzC(shape, rate));
    return __result;
END_RCPP
}
// rsurv
double rsurv(double location, double par2, std::string dist);
RcppExport SEXP cea_rsurv(SEXP locationSEXP, SEXP par2SEXP, SEXP distSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type location(locationSEXP);
    Rcpp::traits::input_parameter< double >::type par2(par2SEXP);
    Rcpp::traits::input_parameter< std::string >::type dist(distSEXP);
    __result = Rcpp::wrap(rsurv(location, par2, dist));
    return __result;
END_RCPP
}
// pv_splines
double pv_splines(double t1, double t2, int state, double r, arma::vec x, arma::vec beta, arma::vec poly_beta, arma::vec poly_deg, arma::vec knots);
RcppExport SEXP cea_pv_splines(SEXP t1SEXP, SEXP t2SEXP, SEXP stateSEXP, SEXP rSEXP, SEXP xSEXP, SEXP betaSEXP, SEXP poly_betaSEXP, SEXP poly_degSEXP, SEXP knotsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type t1(t1SEXP);
    Rcpp::traits::input_parameter< double >::type t2(t2SEXP);
    Rcpp::traits::input_parameter< int >::type state(stateSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type poly_beta(poly_betaSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type poly_deg(poly_degSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type knots(knotsSEXP);
    __result = Rcpp::wrap(pv_splines(t1, t2, state, r, x, beta, poly_beta, poly_deg, knots));
    return __result;
END_RCPP
}
// notinvec
bool notinvec(int item, std::vector<int> v);
RcppExport SEXP cea_notinvec(SEXP itemSEXP, SEXP vSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< int >::type item(itemSEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type v(vSEXP);
    __result = Rcpp::wrap(notinvec(item, v));
    return __result;
END_RCPP
}
// nxttime
double nxttime(double current_time, double time_jump, double maxt);
RcppExport SEXP cea_nxttime(SEXP current_timeSEXP, SEXP time_jumpSEXP, SEXP maxtSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< double >::type current_time(current_timeSEXP);
    Rcpp::traits::input_parameter< double >::type time_jump(time_jumpSEXP);
    Rcpp::traits::input_parameter< double >::type maxt(maxtSEXP);
    __result = Rcpp::wrap(nxttime(current_time, time_jump, maxt));
    return __result;
END_RCPP
}
// matS
arma::mat matS(int index, arma::cube cube, int ntrans, int k);
RcppExport SEXP cea_matS(SEXP indexSEXP, SEXP cubeSEXP, SEXP ntransSEXP, SEXP kSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< int >::type index(indexSEXP);
    Rcpp::traits::input_parameter< arma::cube >::type cube(cubeSEXP);
    Rcpp::traits::input_parameter< int >::type ntrans(ntransSEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    __result = Rcpp::wrap(matS(index, cube, ntrans, k));
    return __result;
END_RCPP
}
// updateAge
arma::vec updateAge(arma::vec x, double age, int col);
RcppExport SEXP cea_updateAge(SEXP xSEXP, SEXP ageSEXP, SEXP colSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< arma::vec >::type x(xSEXP);
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< int >::type col(colSEXP);
    __result = Rcpp::wrap(updateAge(x, age, col));
    return __result;
END_RCPP
}
// sim_msmC
List sim_msmC(arma::cube loc_beta, arma::mat loc_x, std::vector<std::string> dist, arma::mat tmat, arma::vec par2, std::vector<int> absorbing, int maxt, int agecol);
RcppExport SEXP cea_sim_msmC(SEXP loc_betaSEXP, SEXP loc_xSEXP, SEXP distSEXP, SEXP tmatSEXP, SEXP par2SEXP, SEXP absorbingSEXP, SEXP maxtSEXP, SEXP agecolSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< arma::cube >::type loc_beta(loc_betaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type loc_x(loc_xSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type dist(distSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type tmat(tmatSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par2(par2SEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type absorbing(absorbingSEXP);
    Rcpp::traits::input_parameter< int >::type maxt(maxtSEXP);
    Rcpp::traits::input_parameter< int >::type agecol(agecolSEXP);
    __result = Rcpp::wrap(sim_msmC(loc_beta, loc_x, dist, tmat, par2, absorbing, maxt, agecol));
    return __result;
END_RCPP
}
// sim_msm_pvC
arma::vec sim_msm_pvC(arma::vec id, arma::vec sim, arma::vec state, arma::vec time, double r, arma::mat x, int agecol, arma::mat beta, arma::mat poly_beta, arma::mat poly_deg, arma::mat knots);
RcppExport SEXP cea_sim_msm_pvC(SEXP idSEXP, SEXP simSEXP, SEXP stateSEXP, SEXP timeSEXP, SEXP rSEXP, SEXP xSEXP, SEXP agecolSEXP, SEXP betaSEXP, SEXP poly_betaSEXP, SEXP poly_degSEXP, SEXP knotsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< arma::vec >::type id(idSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sim(simSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type state(stateSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type time(timeSEXP);
    Rcpp::traits::input_parameter< double >::type r(rSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type agecol(agecolSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type poly_beta(poly_betaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type poly_deg(poly_degSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type knots(knotsSEXP);
    __result = Rcpp::wrap(sim_msm_pvC(id, sim, state, time, r, x, agecol, beta, poly_beta, poly_deg, knots));
    return __result;
END_RCPP
}
