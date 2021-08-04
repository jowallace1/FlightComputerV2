#pragma once

struct EulerAngles
{
    double yaw;
    double pitch;
    double roll;

    EulerAngles();
    EulerAngles(double yaw, double pitch, double roll);

    EulerAngles operator*(const double &v);
    EulerAngles operator/(const double &v);
    EulerAngles operator+(const double &v);
    EulerAngles operator-(const double &v);

    inline EulerAngles operator*=(const double &v) { return *this * v; }
    inline EulerAngles operator/=(const double &v) { return *this / v; }
    inline EulerAngles operator+=(const double &v) { return *this + v; }
    inline EulerAngles operator-=(const double &v) { return *this - v; }

    EulerAngles operator+(const EulerAngles &v);
    EulerAngles operator-(const EulerAngles &v);
};