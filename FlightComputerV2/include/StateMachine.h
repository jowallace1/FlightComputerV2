#pragma once

#include <Arduino.h>
class StateMachine
{
public:
    StateMachine(unsigned int init_state, double dt);
    inline unsigned int getState() { return state; }
    void setState(unsigned int v) { state = v; }

    void states(); // DEFINE THIS IN MAIN FILE
    void run();

private:
    unsigned int state;
    double dt;
};