# ifndef HESIM_INDIV_CTSTM_H
# define HESIM_INDIV_CTSTM_H
#include <hesim/ctstm/ctstm.h>

namespace hesim {

namespace ctstm {

/***************************************************************************//** 
 * Simulate disease progression for individual patient.
 * A class that randomly samples paths through a multi-state model for
 * an individual patient.
 ******************************************************************************/ 
class patient {
public:
  transmod * transmod_;
  double age_;
  double time_;
  int state_;
  int death_state_;
  double max_age_;
  double max_t_;
  
/** 
   * The constructor.
   * Instantiates an individual patient. 
   */  
  patient(transmod * transmod, double age, double time, int state,
          double max_age, double max_t, int death_state) 
    : transmod_(transmod) {
    age_ = age;
    time_ = time;
    state_ = state;
    max_age_ = max_age;
    max_t_ = max_t;
    death_state_ = death_state;
  }
  
  /** 
   * Jump between health states.
   * A patient moves to a new health states based on random samples to each
   * possible state given their current state. patient::age_, patient::time_,
   * and patient::state_ are updated.
   * @param[in] sample A randomly sampled parameter set. 
   * @return None.
   */  
  void jump(int sample) {
    // Randomly sample times to each transition
    std::vector<int> trans_ids = transmod_->trans_mat_.trans_id(state_);
    int n_trans = trans_ids.size();
    std::vector<double> random_times(n_trans);
    for (int i = 0; i < n_trans; ++i){
      random_times[i] = transmod_->random(trans_ids[i], sample);
    }
    
    // State with the minimum randomly sampled time
    auto random_it = std::min_element(random_times.begin(), random_times.end());
    
    // New time based on the 3 scenarios: (1) randomly sampled time, 
    // (2) maximum time, (3) time based on maximum age
    double new_age = std::min(age_ + *random_it, max_age_);
    std::vector<double> scenario_times = {time_ + *random_it, max_t_, time_ + new_age - age_};
    auto scenarios_it = std::min_element(scenario_times.begin(), scenario_times.end());
    time_ = *scenarios_it;
    age_ = new_age; 
    
    // New states under under the 3 scenarios
    int min_pos = scenarios_it - scenario_times.begin();
    if (min_pos == 0) { // (1) Use randomly sampled time and state at that time
      int state_pos = random_it - random_times.begin();
      state_ = transmod_->trans_mat_.to(state_)[state_pos];
    }
    else if (min_pos == 1){ // Use maximum time so state does not change
      // keep state_ the same
    }
    else { // Patient dies at maximum age
      state_ = death_state_;
    }
     
    
    // Rcpp::Rcout << "random_it: " << *random_it << std::endl;
    // Rcpp::Rcout << "scenarios_it: " << *scenarios_it << std::endl;
    
        
        
 
    
    // New states under under 3 scenarios
    // switch(scenarios_it - scenario_times.begin()){
    // case 0 : {// (1) elapsed time
    //     int state_pos = random_it - random_times.begin();
    //     state_ = transmod_->trans_mat_.to(state_)[state_pos];
    //     break;
    // }
    //   case 1 : // maximum time
    //     break;
    //     // Do nothing
    //   case 2 :
    //     state_ = death_state_;
    //     break;
    // }
    
    // 
    // auto scenario_it = std::min_element({time_ + *it, max_t_, time_ + new_age - age_});
    // 
    // 
    // time_ = std::min({time_ + *it, max_t_, time_ + new_age - age_});
    // 
    // 
    // int state_pos = it - random_times.begin();
    // state_ = transmod_->trans_mat_.to(state_)[state_pos];
  }
};

/***************************************************************************//** 
 * Disease progression container. 
 * A data container that stores simulated paths through a multi-state model (i.e.,
 * disease progression). Note that converting R indexes (to start from 1) to
 * C++ indexes (to start from 0) should be done at the R level. The reason for 
 * this is that this container will sometimes be used directly after a C++ call (
 * in which case indexes still begin at 0)
 * but othertimes will be used after the data has been transfered to R (so 
 * that indexes begin at 1). 
 ******************************************************************************/ 
struct disease_prog {
  std::vector<int> sample_; ///< A randomly sampled parameter set.
  std::vector<int> strategy_id_; ///< The strategy id.
  std::vector<int> line_; ///< The line of treatment.
  std::vector<int> patient_id_; ///< The patient id.
  std::vector<int> from_; ///< The state transitioned from.
  std::vector<int> to_; ///< The state transitioned to.
  std::vector<int> final_; ///< Equal to 1 if it is the final period for a given 
                          ///< patient and 0 otherwise.
  std::vector<double> time_start_; ///< Simulation time when starting in the state.
  std::vector<double> time_stop_; ///< Simulation time when transitioning to a new state.
  
  /** 
   * A default constructor.
   */ 
  disease_prog() {};  
  
  /** 
   * A constructor.
   * Instantiate given output passed from @c R. 
   */ 
  disease_prog(Rcpp::DataFrame R_disease_prog) {
    sample_ = Rcpp::as<std::vector<int> >(R_disease_prog["sample"]);
    strategy_id_ = Rcpp::as<std::vector<int> >(R_disease_prog["strategy_id"]);
    if(R_disease_prog.containsElementNamed("line")){
     line_ = Rcpp::as<std::vector<int> >(R_disease_prog["line"]); 
    }
    else{
      line_ = std::vector<int>(sample_.size(), 0);
    }
    patient_id_ = Rcpp::as<std::vector<int> >(R_disease_prog["patient_id"]);
    from_ = Rcpp::as<std::vector<int> >(R_disease_prog["from"]);
    to_ = Rcpp::as<std::vector<int> >(R_disease_prog["to"]);
    final_ = Rcpp::as<std::vector<int> >(R_disease_prog["final"]);
    time_start_ = Rcpp::as<std::vector<double> >(R_disease_prog["time_start"]);
    time_stop_ = Rcpp::as<std::vector<double> >(R_disease_prog["time_stop"]);
  };    
  
  /** 
   * Allocate memory to each member.
   * Allocate memory to each member but leve them uninitialized. 
   * @param n The size of each vector in the data container. 
   */    
  void reserve(int n) {
    sample_.reserve(n);
    strategy_id_.reserve(n);
    line_.reserve(n);
    patient_id_.reserve(n);
    from_.reserve(n);
    to_.reserve(n);
    final_.reserve(n);
    time_start_.reserve(n);
    time_stop_.reserve(n);
  }
};

} // end namespace ctstm

} // end namespace hesim

# endif