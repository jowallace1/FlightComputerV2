#include "Actuator.h"

class Fairing
{
public:
    Fairing(unsigned int open, unsigned int closed, unsigned int pin);

    void open();
    void close();

    inline bool getState() { return state; }

    inline void attach() { servo.attach(); }
    inline void detach() { servo.detach(); }

private:
    unsigned int openPos, closedPos;

    bool state; // 0 is closed, 1 is open

    Actuator servo;

    friend class Actuator;
};