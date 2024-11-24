#include "C:\Users\kelly\OneDrive\Desktop\gheeseLem\gheese-lem\include\gheese\PID.hpp"
#include "C:\Users\kelly\OneDrive\Desktop\gheeseLem\gheese-lem\include\gheese\util.hpp"
#include <cmath>

PID::PID(double _p, double _i, double _d, double _startI) 
    : kP(_p), kI(_i), kD(_d), startI(_startI) {}

void PID::setExitCondition(int _smallExitTime, double _smallError, int _bigExitTime, double _bigError, int _veloExitTime, int _mATimeout) {
  exit.smallExitTime = _smallExitTime;
  exit.smallError = _smallError;
  exit.bigExitTime = _bigExitTime;
  exit.bigError = _bigError;
  exit.veloExitTime = _veloExitTime;
  exit.mATimeout = _mATimeout;
}

double PID::compute(double _error) {
    error = _error;
    derivative = error - prevError;
    if (kI != 0) {
        if (fabs(error) < startI) {
            integral += error;
        }

        if (gheese::sgn(error) != gheese::sgn(prevError)) integral = 0;
    }

    output = (error * kP) + (integral * kI) + (derivative * kD);
    prevError = error;
    return output;
}

void PID::resetTimers() {
    i = 0; 
    j = 0;
    k = 0;
    l = 0;
    is_mA = false;
}
