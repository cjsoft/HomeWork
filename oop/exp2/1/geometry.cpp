#ifndef GEOMETRY_CPP
#define GEOMETRY_CPP
#include "geometry.h"

#include <iostream>
#include <cmath>

Point::Point() : x(0), y(0) {
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Default construction method for Point is called." << endl;
}

Point::Point(float x, float y) : x(x), y(y) {
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Construction method with parameter(" << x << "\t," << y << "\t) for Point is called." << endl;
}

Point::Point(const Point &b) {
    x = b.x;
    y = b.y;
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Copy construction method for Point is called." << endl;
}

Point::~Point() {
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Default destruction method for Point is called." << endl;
}

Circle::Circle() : center(Point()), radius(0) {
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Default construction method for Point is called." << endl;
}

Circle::Circle(const Circle &b) {
    center = b.center;
    radius = b.radius;
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Copy construction method for Circle is called." << endl;
}

Circle::Circle(Point center, float radius) : center(center), radius(radius) {
    using std::cout;
    using std::endl;
    char s[256];
    sprintf(s, "Construction method with parameter(Point(%f\t,%f\t), %f\t) for Circle is called.", center.x, center.y, radius);
    cout << "\033[31m" << this << "\033[0m " << s << endl;
}

Circle::~Circle() {
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Default destruction method for Circle is called." << endl;
}

float Point::getDis(Point b) {
    return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}

float Point::getDis2(Point b) {
    return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
}

int Circle::relationto(Circle b) {
    float cmpresult = center.getDis2(b.center);
    float dis2 = (radius + b.radius) * (radius + b.radius);
    cmpresult -= dis2;
    if (cmpresult < -EPS) return INTERSECT;
    if (cmpresult > EPS) return SEPARATE;
    return TANGENT;
}
#endif
