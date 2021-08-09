#include <Arduino.h>

#include "ClickButton.h"

#include "core.h"
#include "Actuator.h"
#include "StateMachine.h"

double lim = 6.85;

StateMachine controller(0, 0);
Actuator yawActuator(90, -lim, lim, 3.13, yawServoPin);
Actuator pitchActuator(90, -lim, lim, 1.21, pitchServoPin);

ClickButton controlButton(buttonPin, true);

void setup()
{
    yawActuator.attach();
    pitchActuator.attach();

    Serial.begin(115200);
    // put your setup code here, to run once:
}

void loop()
{
    controller.run();

    // yawActuator.writeAngle(0);
    // pitchActuator.writeAngle(0);
}

void StateMachine::states()
{
    switch (state)
    {
    case 0:
    {
        break;
    }
    case 1:
    {
        for (unsigned int i = 0; i < 360; i++)
        {
            double yawAngle = lim * cos(i * DEG_TO_RAD);
            double pitchAngle = lim * sin(i * DEG_TO_RAD);

            yawActuator.writeAngle(yawAngle);
            pitchActuator.writeAngle(pitchAngle);

            delay(10);
        }
        break;
    }
    }
}