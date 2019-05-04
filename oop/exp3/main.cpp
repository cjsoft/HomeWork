#include "shape.h"
#include <iostream>

using namespace std;


int main() {
    Shape *x;                               // 基类指针
    {
        Shape shp;                          // 派生类实例
        x = &shp;
        cout << x->getArea() << endl;       // 基类指针调用
        cout << (&shp)->getArea() << endl;  // 派生类指针调用
    }
    cout << "--------------------------------" << endl;
    {
        Square a1;                          // 同理
        a1.setSideLength(10);
        x = &a1;
        cout << x->getArea() << endl;
        cout << (&a1)->getArea() << endl;
    }
    cout << "--------------------------------" << endl;
    {
        Rectangle a2;
        a2.setWidth(10);
        a2.setHeight(20);
        x = &a2;
        cout << x->getArea() << endl;
        cout << (&a2)->getArea() << endl;
    }
    cout << "--------------------------------" << endl;
    {
        Circle cir;
        cir.setRadius(10);
        x = &cir;
        cout << x->getArea() << endl;
        cout << (&cir)->getArea() << endl;
    }
}
