#include "Controller.h"

Controller::Controller(double Kp, double Ki, double Kd, Pair setPoint)
    : setPoint(setPoint), Kp(Kp), Ki(Ki), Kd(Kd)
{
}

Pair Controller::evaluate(Pair current, double dt)
{
    error.dError = (current - error.lastError) / dt;
    error.iError = error.iError + current;
    error.lastError = current;

    return current * Kp + error.iError * Ki + error.dError * Kd;
}