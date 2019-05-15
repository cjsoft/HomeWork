//
// Created by egwcy on 2019/5/9.
//
#ifndef WORD_ELEMINATION_3_SERVERCOMMON_H
#define WORD_ELEMINATION_3_SERVERCOMMON_H
#include <QString>
#include <QVector>
#include <QDebug>
#include <QPair>
#include <QObject>
#include <cmath>
#include <QTextStream>
#include <cstdio>
#include <iostream>
#include "../utils/challenge.h"
double csigmoid(double t);
using std::cin;
using std::cout;
using std::cerr;

template <typename T>
void writeObj(FILE *f, T obj) {
    fwrite(&obj, sizeof(T), 1, f);
}

template <typename T>
void writeObjArray(FILE *f, T pobj[], int n) {
    fwrite(pobj, sizeof(T), n, f);
}

template <typename T>
void readObj(FILE *f, T &obj) {
    fread(&obj, sizeof(T), 1, f);
}

template <typename T>
void readObjArray(FILE *f, T pobj[], int n) {
    fread(pobj, sizeof(T), n, f);
}



#endif //WORD_ELEMINATION_3_SERVERCOMMON_H
