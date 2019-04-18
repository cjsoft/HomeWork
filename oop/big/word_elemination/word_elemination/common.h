#pragma once

#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include "auth.h"
#include "localconnect.h"

extern LocalConnect lcc;


typedef int TPtime;
typedef QPair<QString, TPtime> Quiz;
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

int MessageBox(QString content, QString title, QMessageBox::StandardButtons btns,
               QMessageBox::StandardButton defaultbtn);
QString InputBox(QString content, QString title);
#endif // COMMON_H
