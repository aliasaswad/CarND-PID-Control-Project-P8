#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

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
  
  errorSum = 0.0;
  minError = std::numeric_limits<double>::max();
  maxError = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return 0.0;  // TODO: Add your total error calc here!
}