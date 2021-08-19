#include "EulerAngles.h"

EulerAngles::EulerAngles(double yaw, double pitch, double roll)
    : yaw(yaw), pitch(pitch), roll(roll)
{
}

EulerAngles EulerAngles::operator*(const double &v)
{
    EulerAngles temp;
    temp.yaw = yaw * v;
    temp.pitch = pitch * v;
    temp.roll = roll * v;

    return temp;
}

EulerAngles EulerAngles::operator/(const double &v)
{
    return *this * 1 / v;
}

EulerAngles EulerAngles::operator+(const double &v)
{
    EulerAngles temp;
    temp.yaw = yaw + v;
    temp.pitch = pitch + v;
    temp.roll = roll + v;

    return temp;
}

EulerAngles EulerAngles::operator-(const double &v)
{
    return *this + -v;
}

EulerAngles EulerAngles::operator+(const EulerAngles &v)
{
    EulerAngles temp;
    temp.yaw = yaw + v.yaw;
    temp.pitch = pitch + v.pitch;
    temp.roll = roll + v.roll;

    return temp;
}

EulerAngles EulerAngles::operator-(const EulerAngles &v)
{
    EulerAngles temp;
    temp.yaw = yaw - v.yaw;
    temp.pitch = pitch - v.pitch;
    temp.roll = roll - v.roll;

    return temp;
}