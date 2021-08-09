#include "StateMachine.h"

StateMachine::StateMachine(unsigned int state, double dt)
    : state(state), dt(dt)
{
}

void StateMachine::run()
{
    states();

    // TODO: add data logging here

    delay(dt);
}