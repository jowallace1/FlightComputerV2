#pragma once

class UI
{
public:
    UI(unsigned int rLedPin, unsigned int gLedPin, unsigned int bLedPin, unsigned int buzzerPin);
    UI();

    void attach();
    void detach();

private:
    unsigned int rLedPin, gLedPin, bLedPin, buzzerPin;
};