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

Point::Point(int x, int y) : x(x), y(y) {
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

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

Point::~Point() {
    using std::cout;
    using std::endl;
    cout << "\033[31m" << this << "\033[0m Default destruction method for Point is called." << endl;
}


float Point::getDis(Point b) const {
    return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}

int Point::getDis2(Point b) const {
    return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
}

Point &Point::operator++() {
    x++;
    y++;
    return *this;
}

Point &Point::operator--() {
    x--;
    y--;
    return *this;
}

Point Point::operator++(int) {
    Point tmp = *this;
    x++;
    y++;
    return tmp;
}

Point Point::operator--(int) {
    Point tmp = *this;
    x--;
    y--;
    return tmp;
}

void Point::output() const {
    using std::cout;
    using std::endl;
    cout << "(" << x << "," << y << ")" << endl;
}


#endif
