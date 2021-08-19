#pragma once

#include <Arduino.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>

#include "EulerAngles.h"
#include "Orientation.h"
#include "StateMachine.h"
#include "Fairing.h"
#include "Mount.h"
#include "core.h"

struct data
{
    sensors_event_t gyro, accel, mag, euler;
    Orientation orientation;
    EulerAngles gyro_f, orientation_e;
    Quaternion pos;
    double initPressure, pressure, altitude, temperature, yVelo, yAccel, dt; //dt in seconds
    unsigned int state, fairingState;
    Pair mountState;
    unsigned int lastMicros, thisMicros;
};

class Telemetry
{
public:
    Telemetry(double alpha, Adafruit_BNO055 &bno, Adafruit_BMP280 &bmp, StateMachine &sm, Fairing &fairing, Mount &mount);

    void clock(); // run this before every sensor event
    void oriEvent();
    void baroEvent();
    void sysEvent();

    String toString();
    inline data getData() { return myData; }
    inline void setData(data values) { myData = values; }

private:
    double alpha;
    data myData;

    StateMachine *state_machine;
    Adafruit_BNO055 *bno;
    Adafruit_BMP280 *bmp;
    Fairing *fairing;
    Mount *mount;
};