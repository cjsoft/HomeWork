//
// Created by egwcy on 2019/5/9.
//
#include <cmath>
#include "servercommon.h"
double csigmoid(double t) {
    t /= 100;
    return t / (1 + fabs(t));
}