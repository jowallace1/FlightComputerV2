#include "Flash.h"

Flash::Flash(unsigned int pin)
    : pin(pin)
{
    chip = new SPIFlash(pin);
}