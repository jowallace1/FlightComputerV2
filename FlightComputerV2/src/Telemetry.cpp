#include "Telemetry.h"
#include "EulerAngles.h"
#include "Orientation.h"

Telemetry::Telemetry(double alpha, Adafruit_BNO055 &bno, Adafruit_BMP280 &bmp, StateMachine &sm, Fairing &fairing, Mount &mount)
    : alpha(alpha), state_machine(&sm), bno(&bno), bmp(&bmp), fairing(&fairing), mount(&mount)
{
}

String Telemetry::toString()
{
    String temp;

    temp += String(myData.orientation.orientation.a) + ", " + String(myData.orientation.orientation.b) + ", " + String(myData.orientation.orientation.c) + ", " + String(myData.orientation.orientation.d) + ", ";
    temp += String(myData.imu.gyro.x) + ", " + String(myData.imu.gyro.y) + ", " + String(myData.imu.gyro.z) + ", ";
    temp += String(myData.orientation_e.yaw) + ", " + String(myData.orientation_e.pitch) + ", " + String(myData.orientation_e.roll) + ", ";
    temp += String(myData.altitude) + ", ";
    temp += String(myData.yVelo) + ", ";
    temp += String(myData.state) + ", ";
    temp += String(myData.fairingState) + ", ";
    temp += String(myData.mountState.yaw) + ", " + String(myData.mountState.pitch);

    return temp;
}

void Telemetry::clock()
{
    myData.thisMicros = micros();
    myData.dt = myData.thisMicros - myData.lastMicros / 1000000;
    myData.lastMicros = myData.thisMicros;
}

void Telemetry::oriEvent()
{
    EulerAngles lastGyro = myData.gyro_f;

    bno->getEvent(&myData.imu, Adafruit_BNO055::VECTOR_GYROSCOPE);
    bno->getEvent(&myData.imu, Adafruit_BNO055::VECTOR_ACCELEROMETER);
    bno->getEvent(&myData.imu, Adafruit_BNO055::VECTOR_MAGNETOMETER);
    bno->getEvent(&myData.imu, Adafruit_BNO055::VECTOR_EULER);

    EulerAngles gyro(myData.imu.gyro.z, myData.imu.gyro.y, myData.imu.gyro.x); //MAKE SURE THESE ARE ASSIGNED CORRECTLY
    myData.gyro_f = filter(gyro * DEG_TO_RAD, lastGyro, alpha);

    myData.orientation.update(myData.gyro_f, myData.dt);
    myData.orientation_e = myData.orientation.toEuler();
    myData.pos = myData.orientation.orientation.rotate(Quaternion(0, 0, 1));
}

void Telemetry::baroEvent()
{
    double lastAltitude = myData.altitude;
    double lastVelo = myData.yVelo;

    myData.altitude = bmp->readAltitude(myData.initPressure);
    myData.temperature = bmp->readTemperature();
    myData.pressure = bmp->readPressure();

    myData.yVelo = (myData.altitude - lastAltitude) / myData.dt;
    myData.yAccel = (myData.yVelo - lastVelo) / myData.dt;
}

void Telemetry::sysEvent()
{
    myData.state = state_machine->getState();
    myData.fairingState = fairing->getState();
    myData.mountState = mount->getState();
}