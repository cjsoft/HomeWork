#include "common.h"
#include <QInputDialog>
#include <QMessageBox>
int MessageBox(QString content, QString title, QMessageBox::StandardButtons btns,
               QMessageBox::StandardButton defaultbtn) {
    QMessageBox *box = new QMessageBox;
    box->setWindowTitle(title);
    box->setText(content);
    box->setStandardButtons(btns);
    box->setDefaultButton(defaultbtn);
    return box->exec();
}

QString InputBox(QString content, QString title) {
    return QInputDialog::getText(nullptr, title, content);
}

LocalConnect lcc;
