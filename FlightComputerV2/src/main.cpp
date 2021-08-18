#include <Arduino.h>
#include <vector>

#include "ClickButton.h"
#include "Adafruit_BNO055.h"
#include "Adafruit_BMP280.h"

#include "core.h"
#include "Actuator.h"
#include "Fairing.h"
#include "Mount.h"
#include "StateMachine.h"
#include "Flash.h"
#include "Telemetry.h"

#define CHIPSIZE MB32

double lim = 6.85;

// integrated devices
Flash chip(flashCS);
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);
Adafruit_BMP280 bmp;

// mechanical devices
Fairing fairing(0, 90, fairingServoPin);
Mount mount(3.13, 90, yawServoPin, 1.21, 90, pitchServoPin);

// virtual devices
StateMachine controller(0, 0);
Telemetry telem(0.9, bno, bmp, controller, fairing, mount);

void setup()
{
    Serial.begin(115200);
    chip.begin();
    bno.begin();
    bno.setExtCrystalUse(1);

    Serial.println("Device initialized.");
}

void loop()
{
    telem.clock();
    telem.oriEvent();

    delay(10);
}