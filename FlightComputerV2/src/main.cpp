#include <Arduino.h>

#include "Actuator.h"
#include "StateMachine.h"

StateMachine controller(0);

void setup()
{
    // put your setup code here, to run once:
}

void loop()
{
    controller.run();
}

void StateMachine::run()
{
}