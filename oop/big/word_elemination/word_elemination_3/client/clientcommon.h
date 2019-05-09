#pragma once

#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include <QPair>
#include <QLayout>
#include <QLineEdit>
#include <QDialog>
#include <QComboBox>
#include "QtAwesome/QtAwesome.h"
#include "QtAwesome/QtAwesomeAnim.h"
#include "localconnect.h"
#include "../utils/challenge.h"
#include "forms/playform.h"
#include "forms/userhomeform.h"
#include "forms/initialform.h"
#include "forms/addwordform.h"
#include "forms/listusersform.h"
class InitialForm;
class UserHomeForm;
class AddWordForm;
class PlayForm;
class ListUsersForm;
class QtAwesome;
class Challenge;
extern InitialForm *pInitialForm;
extern UserHomeForm *pUserHomeForm;
extern AddWordForm *pAddWordForm;
extern PlayForm *pPlayForm;
extern ListUsersForm *pListUsersForm;
extern QtAwesome* awesome;
extern QVariantMap ColorRed;
extern QVariantMap ColorGreen;
//#include "common.moc"
class LocalConnect;
extern LocalConnect lcc;

class tmpcls : public QObject {
Q_OBJECT;
public:
    QDialog *dlg;
    QGridLayout *glot;
    QLineEdit   *lb, *rb;
    QPushButton *btn, *cbtn;
    QString s;
    int l = 1;
    int r = 0;
    tmpcls(int lower = 0, int upper = 0);
    ~tmpcls();
public slots:
    void f();
    void x();
};
template <typename T1, typename T2, typename T3>
class trair {
public:
    T1 a;
    T2 b;
    T3 c;
    trair(T1 a = T1(), T2 b = T2(), T3 c = T3()) : a(a), b(b), c(c) {

    }
};
typedef int TPtime;

int calcScore(Challenge &cha, int puzzleseq, int timeused, int failurecnt);

QPair<int, int> RangeBox(QString content, QString title, int lower, int upper);
QString InputBox(const QString &content, const QString &title, const QString &text, bool *ok);
int MessageBox(QString content, QString title, QMessageBox::StandardButtons btns,
               QMessageBox::StandardButton defaultbtn);
double csigmoid(double t);
#endif // COMMON_H
