#include "pid.hpp"
#include ""

PID::PID(double _p, double _i, double _d, double _startI) 
    : kP(_p), kI(_i), kD(_d), startI(_startI) {}

void PID::set_exit_condition(int p_small_exit_time, double p_small_error, int p_big_exit_time, double p_big_error, int p_velocity_exit_time, int p_mA_timeout) {
  exit.small_exit_time = p_small_exit_time;
  exit.small_error = p_small_error;
  exit.big_exit_time = p_big_exit_time;
  exit.big_error = p_big_error;
  exit.velocity_exit_time = p_velocity_exit_time;
  exit.mA_timeout = p_mA_timeout;
}

void PID::compute(double _error) {
    error = _error;
    derivative = error - prevError;
    if (kI != 0) {
        if (fabs(error) < startI) {
            integral += error;
        }
    }
}
