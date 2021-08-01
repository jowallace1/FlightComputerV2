#include "core.h"

struct Error
{
    Pair lastError;
    Pair error, dError, iError;
};

class Controller
{
public:
    Controller(double Kp, double Ki, double Kd, Pair setPoint);

    Pair evaluate(Pair current, double dt);

private:
    Pair setPoint;
    Error error;

    double Kp, Ki, Kd;
};