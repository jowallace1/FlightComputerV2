#pragma once

class StateMachine
{
public:
    StateMachine(unsigned int init_state) { state = init_state; }

    inline unsigned int getState() { return state; }
    void setState(unsigned int v) { state = v; }

    void run();

private:
    unsigned int state;
};