#include "Telemetry.h"

String Telemetry::toString()
{
    String temp;

    temp += String(data.orientation.orientation.a) + ", " + String(data.orientation.orientation.b) + ", " + String(data.orientation.orientation.c) + ", " + String(data.orientation.orientation.d) + ", ";
    temp += String(data.gyro.yaw) + ", " + String(data.gyro.pitch) + ", " + String(data.gyro.roll) + ", ";
    temp += String(data.orientation_e.yaw) + ", " + String(data.orientation_e.pitch) + ", " + String(data.orientation_e.roll) + ", ";
    temp += String(data.altitude) + ", ";
    temp += String(data.yVelo) + ", ";
    temp += String(data.state) + ", ";
    temp += String(data.fairingState) + ", ";
    temp += String(data.mountState.yaw) + ", " + String(data.mountState.pitch);
}

void Telemetry::oriEvent()
{
}

void Telemetry::baroEvent()
{
}

void Telemetry::sysEvent()
{
}