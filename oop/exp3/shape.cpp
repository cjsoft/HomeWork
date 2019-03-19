#ifndef SHAPE_CPP
#define SHAPE_CPP
#include "shape.h"

#include <iostream>
Shape::Shape() {
    using std::cout;
    using std::endl;
    cout << "Shape constructed" << endl;
}


Shape::~Shape() {
    using std::cout;
    using std::endl;
    cout << "Shape destructed" << endl;
}

Rectangle::Rectangle() {
    using std::cout;
    using std::endl;
    cout << "Rectangle constructed" << endl;
}


Rectangle::~Rectangle() {
    using std::cout;
    using std::endl;
    cout << "Rectangle destructed" << endl;
}

Square::Square() {
    using std::cout;
    using std::endl;
    cout << "Square constructed" << endl;
}


Square::~Square() {
    using std::cout;
    using std::endl;
    cout << "Square destructed" << endl;
}


Circle::Circle() {
    using std::cout;
    using std::endl;
    cout << "Circle constructed" << endl;
}


Circle::~Circle() {
    using std::cout;
    using std::endl;
    cout << "Circle destructed" << endl;
}



void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

int Rectangle::getArea() {
    using namespace std;
    cout << "RctgA" << endl;
    return width * height;
}

void Square::setSideLength(int d) {
    Rectangle::setWidth(d);
    Rectangle::setHeight(d);
}

int Square::getArea() {
    using namespace std;
    cout << "SqgA" << endl;
    return width * width;
}

void Circle::setRadius(int r) {
    radius = r;
}
#endif
