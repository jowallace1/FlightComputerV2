#pragma once

#include <vector>
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
    inline void readAnything(uint32_t thisAddr, T &target) { chip->readAnything(thisAddr, target); }

    inline void writeChar(uint32_t thisAddr, const char &v) { chip->writeChar(thisAddr, v); }
    inline char readChar(uint32_t thisAddr) { return chip->readChar(thisAddr); }

    // Reads from memory an array of T objects to an empty array target.
    template <typename T>
    void readArray(std::vector<T> &out)
    {
        uint32_t size = sizeof(T);

        for (uint32_t i = 0; i <= addr; i += size)
        {
            T single_out;
            readAnything(i, single_out);
            out.push_back(single_out);
        }
    }

    // Writes an object to the current cursor location and updates the cursor accordingly
    template <typename T>
    void writeAnything(const T &v)
    {
        chip->writeAnything(addr, v);
        addr += sizeof(T);
    }

private:
    unsigned int pin;
    uint32_t addr; // Cursor memory address

    SPIFlash *chip;
};