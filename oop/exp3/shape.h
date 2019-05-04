#ifndef SHAPE_H
#define SHAPE_H
class Shape {
public:
    Shape();                                // 基类构造析构函数
    ~Shape();
    double getArea() const;                 // 基类方法
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle();
    ~Rectangle();
    void setWidth(double w);
    void setHeight(double h);
    double getWidth() const;
    double getHeight() const;
    double getArea() const;
};

class Square : public Rectangle {
private:
    void setWidth(double w);
    void setHeight(double h);
public:
    Square();
    ~Square();
    void setSideLength(double d);
    double getSideLength() const;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle();
    ~Circle();
    void setRadius(double r);
    double getRadius() const;
    double getArea() const;

};

#endif
