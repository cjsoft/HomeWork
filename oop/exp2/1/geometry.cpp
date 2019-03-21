#ifndef GEOMETRY_CPP
#define GEOMETRY_CPP
#include "geometry.h"

#include <iostream>
#include <cmath>
#include <cstdio>

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

float Point::getX() const {
    return this->x;
}

float Point::getY() const {
    return this->y;
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
    this->center = b.getCenter();
    this->radius = b.getRadius();
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Copy construction method for Circle is called." << endl;
}

Circle::Circle(Point center, float radius) : center(center), radius(radius) {
    using std::cout;
    using std::endl;
    char s[256];
    sprintf(s, "Construction method with parameter(Point(%f\t,%f\t), %f\t) for Circle is called.", center.getX(), center.getY(), radius);
    cout << "\033[31m" << this << "\033[0m " << s << endl;
}

Circle::~Circle() {
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Default destruction method for Circle is called." << endl;
}

float Point::getDis(Point b) const {
    return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}

float Point::getDis2(Point b) const {
    return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
}

int Circle::relationto(Circle b) const {
    float cmpresult = this->getCenter().getDis2(b.center);
    float dis2 = (this->getRadius() + b.getRadius()) * (this->getRadius() + b.getRadius());
    cmpresult -= dis2;
    if (cmpresult < -EPS) return INTERSECT;
    if (cmpresult > EPS) return SEPARATE;
    return TANGENT;
}

Point Circle::getCenter() const {
    return center;
}

float Circle::getRadius() const {
    return radius;
}

#endif

