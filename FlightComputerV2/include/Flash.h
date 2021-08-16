#pragma once

#include <Arduino.h>

#include "SPIFlash.h"

class Flash
{
public:
    Flash(unsigned int pin);
    ~Flash();

    inline void begin() { chip->begin(); }
    inline void erase() { chip->eraseChip(); }

    template <typename T>
    inline void writeAnything(uint32_t thisAddr, const T &v) { chip->writeAnything(thisAddr, v); }

    template <typename T>
    inline void readAnything(uint32_t thisAddr, const T &target) { chip->readAnything(thisAddr, target); }

    inline void writeChar(uint32_t thisAddr, const char &v) { chip->writeChar(thisAddr, v); }
    inline char readChar(uint32_t thisAddr) { return chip->readChar(thisAddr); }

private:
    unsigned int pin;
    uint32_t addr;

    SPIFlash *chip;
};