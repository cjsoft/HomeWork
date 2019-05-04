#include "geometry.h"

#include <iostream>
#include <cmath>
#include <cstdio>

Point::Point() : x(0), y(0) {
    using std::cout;
    using std::endl;
    #ifdef DEBUG                        // 加编译开关输出各种构造函数析构函数的调用信息
    cout << "\033[31m" << this << "\033[0m Default construction method for Point is called." << endl;
    #endif
}

Point::Point(int x, int y) : x(x), y(y) {
    using std::cout;
    using std::endl;
    #ifdef DEBUG
    cout << "\033[31m" << this << "\033[0m Construction method with parameter(" << x << "\t," << y << "\t) for Point is called." << endl;
    #endif
}

Point::Point(const Point &b) {
    x = b.x;
    y = b.y;
    using std::cout;
    using std::endl;
    #ifdef DEBUG
    cout << "\033[31m" << this << "\033[0m Copy construction method for Point is called." << endl;
    #endif
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
    #ifdef DEBUG
    cout << "\033[31m" << this << "\033[0m Default destruction method for Point is called." << endl;
    #endif
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

Point &Point::operator=(const Point &b) {
    x = b.x;
    y = b.y;
    return (*this);
}