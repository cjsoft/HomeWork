#ifndef GEOMETRY_H
#define GEOMETRY_H
#define EPS 1e-6     // 浮点运算会产生误差
#define TANGENT 0
#define SEPARATE 1
#define INTERSECT -1
class Point {
private:
    int x, y;
public:
    Point();
    Point(int x, int y);
    Point(const Point &b);
    ~Point();
    int getX() const;
    int getY() const;
    float getDis(Point b) const;
    int getDis2(Point b) const;

    Point &operator++();        // 前置
    Point &operator--();
    Point operator++(int);      // 后置
    Point operator--(int);
    Point &operator=(const Point &b); // 赋值
    void output() const;        // 输出
};


#endif
