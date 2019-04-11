/********************************************************************************
** Form generated from reading UI file 'initialform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIALFORM_H
#define UI_INITIALFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InitialForm
{
public:
    QGroupBox *gb;
    QLineEdit *inputPassword;
    QLineEdit *inputUserName;
    QLabel *lblUserName;
    QLabel *lblPassword;
    QPushButton *btnRegister;
    QPushButton *btnLogin;

    void setupUi(QDialog *InitialForm)
    {
        if (InitialForm->objectName().isEmpty())
            InitialForm->setObjectName(QString::fromUtf8("InitialForm"));
        InitialForm->resize(291, 165);
        gb = new QGroupBox(InitialForm);
        gb->setObjectName(QString::fromUtf8("gb"));
        gb->setGeometry(QRect(20, 10, 251, 121));
        inputPassword = new QLineEdit(gb);
        inputPassword->setObjectName(QString::fromUtf8("inputPassword"));
        inputPassword->setGeometry(QRect(60, 60, 181, 21));
        inputUserName = new QLineEdit(gb);
        inputUserName->setObjectName(QString::fromUtf8("inputUserName"));
        inputUserName->setGeometry(QRect(60, 30, 181, 21));
        lblUserName = new QLabel(gb);
        lblUserName->setObjectName(QString::fromUtf8("lblUserName"));
        lblUserName->setGeometry(QRect(10, 30, 41, 21));
        lblPassword = new QLabel(gb);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));
        lblPassword->setGeometry(QRect(10, 50, 31, 21));
        btnRegister = new QPushButton(gb);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setGeometry(QRect(70, 90, 80, 20));
        btnLogin = new QPushButton(gb);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(160, 90, 80, 20));
#ifndef QT_NO_SHORTCUT
        lblUserName->setBuddy(inputUserName);
        lblPassword->setBuddy(inputPassword);
#endif // QT_NO_SHORTCUT

        retranslateUi(InitialForm);

        QMetaObject::connectSlotsByName(InitialForm);
    } // setupUi

    void retranslateUi(QDialog *InitialForm)
    {
        InitialForm->setWindowTitle(QApplication::translate("InitialForm", "InitialForm", nullptr));
        gb->setTitle(QString());
        lblUserName->setText(QApplication::translate("InitialForm", "\347\224\250\346\210\267\345\220\215", nullptr));
        lblPassword->setText(QApplication::translate("InitialForm", "\345\257\206\347\240\201", nullptr));
        btnRegister->setText(QApplication::translate("InitialForm", "\346\263\250\345\206\214", nullptr));
        btnLogin->setText(QApplication::translate("InitialForm", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitialForm: public Ui_InitialForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALFORM_H
