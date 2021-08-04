#include <Arduino.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>

#include "Orientation/Orientation.h"
#include "core.h"

struct data
{
    sensors_event_t imu;
    Orientation orientation;
    EulerAngles gyro_f, orientation_e;
    Quaternion pos;
    double altitude, yVelo, dt; //dt in seconds
    unsigned int state, fairingState;
    Pair mountState;
    unsigned int lastMicros, thisMicros;
};

class Telemetry
{
public:
    Telemetry(double alpha, Adafruit_BNO055 &bno, Adafruit_BMP280 &bmp);

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

    Adafruit_BNO055 *bno;
    Adafruit_BMP280 *bmp;
};