#pragma once

class StateMachine
{
public:
    inline unsigned int getState() { return state; }
    void setState(unsigned int v) { state = v; }

    void run();

private:
    unsigned int state;
};