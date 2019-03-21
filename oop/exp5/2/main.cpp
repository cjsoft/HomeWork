#include "geometry.h"
#include <iostream>
#include <cstring>

using namespace std;


int main() {
    Point a;
    (a++).output();
    (++a).output();
    (--a).output();
    (a--).output();
    return 0;
}
