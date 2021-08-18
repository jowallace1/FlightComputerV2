#include "Fairing.h"
#include "Actuator.h"

Fairing::Fairing(unsigned int open, unsigned int closed, unsigned int pin)
    : openPos(open), closedPos(closed)
{
    servo.pin = pin;
}

void Fairing::open()
{
    servo.writeAngle(openPos);
    state = 1;
};

void Fairing::close()
{
    servo.writeAngle(closedPos);
    state = 0;
};