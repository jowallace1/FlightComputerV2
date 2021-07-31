#include <Servo.h>
#include "core.h"

class Actuator
{
public:
    Actuator(unsigned int off, unsigned int pin);

    inline void writeAngle(double angle) { servo.writeMicroseconds(map(angle, 0, 180, 400, 2400)); }
    inline void attach() { servo.attach(pin); }
    inline void detach() { servo.detach(); }

private:
    unsigned int offset, pin;

    Servo servo;
};