#include "Actuator.h"

// ************************ CONSTRUCTORS ************************

Actuator::Actuator(double off, double min, double max, double ratio, unsigned int p)
    : pin(p), offset(off), ratio(ratio), min(min), max(max)
{
}

Actuator::Actuator(double min, double max, unsigned int p)
    : pin(p), min(min), max(max)
{
}

Actuator::Actuator(double off, unsigned int p)
    : pin(p), offset(off)
{
}

Actuator::Actuator(unsigned int p)
    : pin(p)
{
}

// **************************************************************

void Actuator::writeAngle(double const angle)
{
    double temp = angle;

    if (temp < min)
    {
        temp = min;
    }

    if (temp > max)
    {
        temp = max;
    }

    myAngle = temp;

    writeServo(RAD_TO_DEG * asin(sin(temp * DEG_TO_RAD) * ratio));
}