#include "common.h"
#include <QInputDialog>
#include <QDialog>
#include <QLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QObject>
#include <QValidator>
#include <QDebug>
#include <QLabel>
#include <QSizePolicy>
#include <cmath>
int MessageBox(QString content, QString title, QMessageBox::StandardButtons btns,
               QMessageBox::StandardButton defaultbtn) {
    QMessageBox *box = new QMessageBox;
    box->setWindowTitle(title);
    box->setText(content);
    box->setStandardButtons(btns);
    box->setDefaultButton(defaultbtn);
    return box->exec();
}

QString InputBox(const QString &content, const QString &title, const QString &text, bool *ok) {
    return QInputDialog::getText(nullptr, title, content, QLineEdit::Normal, text, ok);
}

QPair<int, int> RangeBox(QString content, QString title, int lower, int upper) {
    tmpcls tmp(upper, lower);
    tmp.dlg->setWindowTitle(title);
    QLabel *lbl = new QLabel(content);
    lbl->setWordWrap(true);
    lbl->setAlignment(Qt::AlignTop);
    tmp.glot->addWidget(lbl, 0, 0, 1, 5);
    tmp.dlg->exec();
    qDebug() << tmp.l << tmp.r;
    return QPair<int, int>(tmp.l, tmp.r);
}

double csigmoid(double t) {
    t /= 100;
    return t / (1 + fabs(t));
}

int calcScore(Challenge &cha, int puzzleseq, int timeused, int failurecnt) {
    if (cha.getQzlist().size() <= 0)
        return 0;
    int rtn = puzzleseq * 100 + 100;
    rtn += cha.getQzlist().size() * 10;
    rtn = rtn * (1 - csigmoid(timeused / (double)cha.getQzlist().size()) / 20.);
    return rtn;
}

LocalConnect lcc;

void tmpcls::f()  {
    if (lb->text().toInt() > rb->text().toInt()) {
        MessageBox("范围不合法", "提示", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    if (lb->text().trimmed().length() == 0 || rb->text().trimmed().length() == 0) {
        MessageBox("输入为空", "提示", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    l = lb->text().toInt();
    r = rb->text().toInt();
    dlg->close();
}

tmpcls::~tmpcls()  {
    delete dlg;
}

tmpcls::tmpcls(int upper, int lower)  {
    dlg = new QDialog;
    dlg->setWindowFlags(dlg->windowFlags()& ~Qt::WindowContextHelpButtonHint);
    dlg->setWindowFlags(dlg->windowFlags()& ~Qt::WindowMaximizeButtonHint);
    glot = new QGridLayout(dlg);
    glot->setColumnStretch(0, 1);
    glot->setColumnStretch(1, 1);
    glot->setColumnStretch(3, 1);
    glot->setColumnStretch(4, 1);
    glot->setContentsMargins(5, 5, 5, 5);
    lb = new QLineEdit;
    rb = new QLineEdit;
    btn = new QPushButton;
    btn->setText("Ok");
    cbtn = new QPushButton;
    cbtn->setText("Cancel");
    lb->setValidator(new QIntValidator(lower, upper, lb));
    rb->setValidator(new QIntValidator(lower, upper, rb));
    glot->addWidget(lb, 1, 0, 1, 2);
    glot->addWidget(rb, 1, 3, 1, 2);
    glot->addWidget(new QLabel("~"), 1, 2, 1, 1);
    glot->addWidget(btn, 2, 0, 1, 2);
    glot->addWidget(cbtn, 2, 3, 1, 2);
    dlg->setLayout(glot);
    l = 1;
    r = 0;
    connect(btn, SIGNAL(clicked()), this, SLOT(f()));
    connect(cbtn, SIGNAL(clicked()), this, SLOT(x()));

}

void tmpcls::x() {
    l = 1;
    r = 0;
    dlg->close();
}
