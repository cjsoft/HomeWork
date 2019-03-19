#ifndef GEOMETRY_H
#define GEOMETRY_H
#define EPS 1e-6     // 浮点运算会产生误差
#define TANGENT 0
#define SEPARATE 1
#define INTERSECT -1
class Point {
public:
    float x, y;
    Point();
    Point(float x, float y);
    Point(const Point &b);
    ~Point();
    float getDis(Point b);
    float getDis2(Point b);
};

class Circle {
public:
    Point center;
    float radius;
    Circle();
    Circle(Point center, float radius);
    Circle(const Circle &b);
    ~Circle();
    int relationto(Circle b);
};

#include "geometry.cpp"
#endif
