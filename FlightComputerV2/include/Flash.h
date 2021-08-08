#pragma once

#include "SPIFlash.h"

class Flash
{
public:
    Flash(unsigned int pin);
    inline ~Flash() { delete chip; };

private:
    unsigned int pin;

    SPIFlash *chip;
};