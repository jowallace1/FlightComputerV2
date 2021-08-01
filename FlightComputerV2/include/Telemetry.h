#include <Arduino.h>

#include "Orientation/Orientation.h"
#include "core.h"

struct data
{
    Orientation orientation;
    EulerAngles gyro, orientation_e;
    double altitude, yVelo;
    unsigned int state, fairingState;
    Pair mountState;
};

class Telemetry
{
public:
    void oriEvent();
    void baroEvent();
    void sysEvent();

    String toString();
    inline data getData() { return data; }
    inline void setData(data values) { data = values; }

private:
    data data;
};