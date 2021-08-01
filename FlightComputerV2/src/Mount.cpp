#include "Mount.h"

Mount::Mount(double yawRatio, unsigned int yawOffset, unsigned int yawPin, double pitchRatio, unsigned int pitchOffset, unsigned int pitchPin)
    : yawRatio(yawRatio), pitchRatio(pitchRatio)
{
    yawServo.offset = yawOffset;
    yawServo.pin = yawPin;

    pitchServo.offset = pitchOffset;
    pitchServo.pin = pitchPin;
}

void Mount::attach()
{
    yawServo.attach();
    pitchServo.attach();
}

void Mount::detach()
{
    yawServo.detach();
    pitchServo.detach();
}