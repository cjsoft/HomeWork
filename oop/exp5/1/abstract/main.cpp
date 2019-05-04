#include "shape.h"
#include <iostream>

using namespace std;


int main() {
    Shape *x;
    Square *psq;
    Rectangle *prct;
    Circle *pcir;               // 准备基类和各种派生类指针
    {
        Square a1;
        a1.setSideLength(10);
        x = &a1;
        psq = &a1;
        cout << x->getArea() << endl;       // 用基类和派生类指针分别调用虚函数
        cout << psq->getArea() << endl;
    }
    cout << "---------------------------------------------" << endl;
    {
        Rectangle a2;
        a2.setWidth(10);
        a2.setHeight(20);
        x = &a2;
        prct = &a2;
        cout << x->getArea() << endl;
        cout << prct->getArea() << endl;
    }
    cout << "---------------------------------------------" << endl;
    {
        Circle cir;
        cir.setRadius(10);
        x = &cir;
        pcir = &cir;
        cout << x->getArea() << endl;
        cout << pcir->getArea() << endl;
    }
    #ifdef TEST                 // 加-DTEST编译参数无法编译，因为抽象类无法被实例化
    Shape a;
    #endif
}
