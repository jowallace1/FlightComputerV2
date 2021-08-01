#include <Servo.h>
#include "core.h"

class Actuator
{
public:
    Actuator(unsigned int off, unsigned int pin);
    Actuator();

    inline void writeAngle(double angle) { servo.writeMicroseconds(map(angle, 0, 180, 400, 2400)); }
    inline double readAngle() { servo.readMicroseconds(); }

    inline void attach() { servo.attach(pin); }
    inline void detach() { servo.detach(); }

private:
    unsigned int offset = 0;
    unsigned int pin;

    Servo servo;

    friend class Mount;
    friend class Fairing;
};