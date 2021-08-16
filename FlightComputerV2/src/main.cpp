#include <Arduino.h>

#include "ClickButton.h"

#include "core.h"
#include "Actuator.h"
#include "StateMachine.h"
#include "Flash.h"
//#include "SPIFlash.h"

#define CHIPSIZE MB32

double lim = 6.85;

StateMachine controller(0, 0);

//SPIFlash chip(flashCS);
Flash chip(flashCS);

Actuator yawActuator(90, -lim, lim, 3.13, yawServoPin);
Actuator pitchActuator(90, -lim, lim, 1.21, pitchServoPin);

ClickButton controlButton(buttonPin, true);

struct vec2
{
    float x, y;
};

vec2 test;
vec2 out;

void setup()
{
    Serial.begin(115200);
    chip.begin();
    Serial.println("Chip initialized.");
    //chip.eraseChip();
    chip.erase();
    Serial.println("Chip erased.");

    yawActuator.attach();
    pitchActuator.attach();

    // put your setup code here, to run once:

    test.x = 12.52;
    test.y = 11.29;

    chip.writeAnything(0, test);
    chip.readAnything(0, out);
}

void loop()
{
    //controller.run();
    Serial.print("Test values: ");
    Serial.print(out.x);
    Serial.print(',');
    Serial.println(out.y);

    delay(200);
}

void StateMachine::states()
{
    switch (state)
    {
    case 0:
    {
        break;
    }
    case 1:
    {
        break;
    }
    }
}