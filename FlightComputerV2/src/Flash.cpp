#include "Flash.h"

Flash::Flash(unsigned int pin)
    : pin(pin), addr(0)
{
    chip = new SPIFlash(pin);
}

Flash::~Flash()
{
    delete chip;
}