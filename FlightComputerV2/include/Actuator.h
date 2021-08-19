#pragma once

#include <Servo.h>
#include "core.h"

class Actuator
{
public:
    Actuator(double off, double min, double max, double ratio, unsigned int pin);
    Actuator(double min, double max, unsigned int pin);
    Actuator(double off, unsigned int pin);
    Actuator(unsigned int pin);
    inline Actuator(){};

    inline void writeServo(double const angle) { servo.writeMicroseconds(map(angle + offset, 0, 180, 400, 2400)); } // THIS FUNCTION HAS NO LIMIT PROTECTION
    void writeAngle(double const angle);                                                                            // THIS FUNCTION HAS LIMIT PROTECTION

    inline double readServo() { return servo.readMicroseconds(); }
    inline double readAngle() { return myAngle; }

    inline void attach() { servo.attach(pin); }
    inline void detach() { servo.detach(); }

    inline void setOffset(unsigned int angle) { offset = angle; }

private:
    unsigned int pin;
    double offset = 0;
    double ratio = 1;
    double myAngle;

    double min = 0;
    double max = 180;

    Servo servo;

    friend class Mount;
    friend class Fairing;
};