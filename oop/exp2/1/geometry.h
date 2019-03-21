#ifndef GEOMETRY_H
#define GEOMETRY_H
#define EPS 1e-6     // 浮点运算会产生误差
#define TANGENT 0
#define SEPARATE 1
#define INTERSECT -1
class Point {
private:
    float x, y;
public:
    Point();
    Point(float x, float y);
    Point(const Point &b);
    ~Point();
    float getX() const;
    float getY() const;
    float getDis(Point b) const;
    float getDis2(Point b) const;
};

class Circle {
private:
    Point center;
    float radius;
public:

    Circle();
    Circle(Point center, float radius);
    Circle(const Circle &b);
    ~Circle();
    int relationto(Circle b) const;
    Point getCenter() const;
    float getRadius() const;
};

#include "geometry.cpp"
#endif
