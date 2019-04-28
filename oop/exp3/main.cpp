#include "shape.h"
#include <iostream>

using namespace std;


int main() {
    Shape *x;
    {
        Shape shp;
        x = &shp;
        cout << x->getArea() << endl;
        cout << (&shp)->getArea() << endl;
    }
    cout << "--------------------------------" << endl;
    {
        Square a1;
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
