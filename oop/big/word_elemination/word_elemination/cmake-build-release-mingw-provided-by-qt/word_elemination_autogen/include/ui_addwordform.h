/********************************************************************************
** Form generated from reading UI file 'addwordform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWORDFORM_H
#define UI_ADDWORDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWordForm
{
public:
    QAction *actionfanhui;
    QAction *actReturn;
    QWidget *centralwidget;
    QLineEdit *inputWord;
    QPushButton *pushButton;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *AddWordForm)
    {
        if (AddWordForm->objectName().isEmpty())
            AddWordForm->setObjectName(QString::fromUtf8("AddWordForm"));
        AddWordForm->resize(800, 600);
        actionfanhui = new QAction(AddWordForm);
        actionfanhui->setObjectName(QString::fromUtf8("actionfanhui"));
        actReturn = new QAction(AddWordForm);
        actReturn->setObjectName(QString::fromUtf8("actReturn"));
        centralwidget = new QWidget(AddWordForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        inputWord = new QLineEdit(centralwidget);
        inputWord->setObjectName(QString::fromUtf8("inputWord"));
        inputWord->setGeometry(QRect(130, 110, 291, 61));
        QFont font;
        font.setPointSize(20);
        inputWord->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 110, 101, 61));
        pushButton->setFont(font);
        AddWordForm->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(AddWordForm);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        AddWordForm->setMenuBar(menuBar);

        retranslateUi(AddWordForm);

        QMetaObject::connectSlotsByName(AddWordForm);
    } // setupUi

    void retranslateUi(QMainWindow *AddWordForm)
    {
        AddWordForm->setWindowTitle(QApplication::translate("AddWordForm", "MainWindow", nullptr));
        actionfanhui->setText(QApplication::translate("AddWordForm", "fanhui", nullptr));
        actReturn->setText(QApplication::translate("AddWordForm", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", nullptr));
        inputWord->setPlaceholderText(QApplication::translate("AddWordForm", "\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\345\215\225\350\257\215", nullptr));
        pushButton->setText(QApplication::translate("AddWordForm", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWordForm: public Ui_AddWordForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWORDFORM_H
