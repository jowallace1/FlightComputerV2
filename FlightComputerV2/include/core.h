#pragma once

#include "EulerAngles/EulerAngles.h"

struct Pair
{
    double yaw, pitch;

    Pair operator+(const Pair &p)
    {
        Pair temp;
        temp.yaw = yaw + p.yaw;
        temp.pitch = pitch + p.pitch;
        return temp;
    }

    Pair operator-(const Pair &p)
    {
        Pair temp;
        temp.yaw = yaw - p.yaw;
        temp.pitch = pitch - p.pitch;
        return temp;
    }

    Pair operator*(const double &d)
    {
        Pair temp;
        temp.yaw = yaw * d;
        temp.pitch = pitch * d;
        return temp;
    }

    Pair operator/(const double &d)
    {
        Pair temp;
        temp.yaw = yaw / d;
        temp.pitch = pitch / d;
        return temp;
    }
};

inline double map(double x, double in_min, double in_max, double out_min, double out_max) { return (double)(x - in_min) * (out_max - out_min) / (double)(in_max - in_min) + out_min; }
inline EulerAngles filter(EulerAngles current, EulerAngles last, double alpha) { return current * alpha + current * (1 - alpha); }