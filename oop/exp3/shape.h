#ifndef SHAPE_H
#define SHAPE_H
class Shape {
public:
    Shape();
    ~Shape();
    virtual int getArea() = 0;
};

class Rectangle : public Shape {
public:
    int width, height;
    Rectangle();
    ~Rectangle();
    void setWidth(int w);
    void setHeight(int h);
    virtual int getArea();
};

class Square : public Rectangle {
private:
    void setWidth(int w);
    void setHeight(int h);
public:
    Square();
    ~Square();
    void setSideLength(int d); 
    virtual int getArea();
};

class Circle : public Shape {
public:
    int radius;
    Circle();
    ~Circle();
    void setRadius(int r);
};

#include "shape.cpp"
#endif
