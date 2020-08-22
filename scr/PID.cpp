#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

double PID::AverageError() {
  return sum_error/counter;
}

double PID::MinError() {
  return min_error;
}

double PID::MaxError() {
  return max_error;
}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  // Prev.
  prev_cte = 0.0;
  
  counter = 0;
  
  sum_error = 0.0;
  min_error = std::numeric_limits<double>::max();
  max_error = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // Integ. Err.
  i_error += cte;

  // Diff. Err.
  d_error = cte - prev_cte;
  prev_cte = cte;

  sum_error += cte;
  counter++;
  if ( cte > max_error ) {
    max_error = cte;
  }
  if ( cte < min_error ) {
    min_error = cte;
  }
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // return 0.0;  // TODO: Add your total error calc here!
  return p_error*Kp+i_error*Ki+d_error*Kd;
}