#include <Arduino.h>
#include <vector>

#include "ClickButton.h"

#include "core.h"
#include "Actuator.h"
#include "StateMachine.h"
#include "Flash.h"

#define CHIPSIZE MB32

double lim = 6.85;

StateMachine controller(0, 0);

//SPIFlash chip(flashCS);
Flash chip(flashCS);

std::vector<int> out;

void setup()
{
    Serial.begin(115200);
    chip.begin();
    Serial.println("Chip initialized.");
    chip.erase();
    Serial.println("Chip erased.");

    chip.writeAnything(1);
    chip.writeAnything(2);
    chip.writeAnything(3);

    chip.readArray(out);
}

void loop()
{
    //controller.run();
    Serial.print("Test values: ");
    Serial.print(out[0]);
    Serial.print(',');
    Serial.print(out[1]);
    Serial.print(',');
    Serial.println(out[2]);

    delay(200);
}