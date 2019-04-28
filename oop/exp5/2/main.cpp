#include "geometry.h"
#include <iostream>
#include <cstring>
#ifndef INITIAL
#define INITIAL 1, 2
#endif
using namespace std;


int main() {
    Point a;
    a = Point(INITIAL);
    cout << "Intial value is";
    a.output();
    cout << "a++ returns";
    (a++).output();
    cout << "Now a is";
    a.output();
    cout << "++a returns";
    (++a).output();
    cout << "Now a is";
    a.output();
    cout << "--a returns";
    (--a).output();
    cout << "Now a is";
    a.output();
    cout << "a-- returns";
    (a--).output();
    cout << "Now a is";
    a.output();
    return 0;
}
