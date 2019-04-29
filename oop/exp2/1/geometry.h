#ifndef GEOMETRY_H
#define GEOMETRY_H
#define EPS 1e-6                            // 浮点运算会产生误差，设定EPS来规避计算精度误差
#define INTERSECTS 0
#define NOTINTERSECTS 1
class Point {
private:
    float x, y;
public:
    Point();
    Point(float x, float y);                // 构造函数
    Point(const Point &b);                  // 拷贝构造函数
    ~Point();                               // 析构函数
    float getX() const;                     // X的getter
    float getY() const;                     // Y的getter
    float getDis(Point b) const;            // 获取两点间的欧氏距离
    float getDis2(Point b) const;           // 获取两点间的欧氏距离的平方
};

class Circle {
private:
    Point center;
    float radius;
public:

    Circle();
    Circle(Point center, float radius);     // 构造函数
    Circle(const Circle &b);                // 拷贝构造函数
    ~Circle();                              // 析构函数
    int relationto(Circle b) const;         // 判断两圆关系函数
    Point getCenter() const;                // 圆心的getter
    float getRadius() const;                // 半径的getter
};

#endif
