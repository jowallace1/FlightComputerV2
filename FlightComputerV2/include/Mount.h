#pragma once

#include "Actuator.h"

class Mount
{
public:
    Mount(double yawRatio, unsigned int yawOffset, unsigned int yawPin, double pitchRatio, unsigned int pitchOffset, unsigned int pitchPin);

    void attach();
    void detach();

    void update(double yawAngle, double pitchAngle); //TODO: Define this in Mount.cpp

    Pair getState();

private:
    double yawRatio, pitchRatio;

    Actuator yawServo, pitchServo;

    friend class Actuator;
};