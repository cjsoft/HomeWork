#ifndef SHAPE_H
#define SHAPE_H
class Shape {
public:
    Shape();
    ~Shape();
    virtual int getArea() const;
};

class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle();
    ~Rectangle();
    void setWidth(int w);
    void setHeight(int h);
    int getWidth() const;
    int getHeight() const;
    int getArea() const;
};

class Square : public Rectangle {
private:
    void setWidth(int w);
    void setHeight(int h);
public:
    Square();
    ~Square();
    void setSideLength(int d);
    int getSideLength() const;
    int getArea() const;
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle();
    ~Circle();
    void setRadius(int r);
    int getRadius() const;
};

#endif
