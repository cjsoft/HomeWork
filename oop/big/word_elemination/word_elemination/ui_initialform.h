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
#include <QtWidgets/QRadioButton>

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
    QGroupBox *gb_2;
    QLineEdit *inputPassword_2;
    QLineEdit *inputUserName_2;
    QLabel *lblUserName_2;
    QLabel *lblPassword_2;
    QPushButton *btnReturnToLogin;
    QPushButton *btnConfirmRegister;
    QLabel *lblPassword_3;
    QLineEdit *inputPassword_3;
    QRadioButton *rPlayer;
    QRadioButton *rDesigner;

    void setupUi(QDialog *InitialForm)
    {
        if (InitialForm->objectName().isEmpty())
            InitialForm->setObjectName(QString::fromUtf8("InitialForm"));
        InitialForm->resize(599, 485);
        gb = new QGroupBox(InitialForm);
        gb->setObjectName(QString::fromUtf8("gb"));
        gb->setGeometry(QRect(10, 10, 251, 121));
        inputPassword = new QLineEdit(gb);
        inputPassword->setObjectName(QString::fromUtf8("inputPassword"));
        inputPassword->setGeometry(QRect(60, 60, 181, 21));
        inputPassword->setEchoMode(QLineEdit::Password);
        inputUserName = new QLineEdit(gb);
        inputUserName->setObjectName(QString::fromUtf8("inputUserName"));
        inputUserName->setGeometry(QRect(60, 30, 181, 21));
        lblUserName = new QLabel(gb);
        lblUserName->setObjectName(QString::fromUtf8("lblUserName"));
        lblUserName->setGeometry(QRect(10, 30, 41, 21));
        lblPassword = new QLabel(gb);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));
        lblPassword->setGeometry(QRect(10, 60, 31, 21));
        btnRegister = new QPushButton(gb);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setGeometry(QRect(60, 90, 80, 20));
        btnRegister->setAutoDefault(false);
        btnLogin = new QPushButton(gb);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(160, 90, 80, 20));
        gb_2 = new QGroupBox(InitialForm);
        gb_2->setObjectName(QString::fromUtf8("gb_2"));
        gb_2->setGeometry(QRect(290, 10, 251, 171));
        inputPassword_2 = new QLineEdit(gb_2);
        inputPassword_2->setObjectName(QString::fromUtf8("inputPassword_2"));
        inputPassword_2->setGeometry(QRect(60, 60, 181, 21));
        inputPassword_2->setEchoMode(QLineEdit::Password);
        inputUserName_2 = new QLineEdit(gb_2);
        inputUserName_2->setObjectName(QString::fromUtf8("inputUserName_2"));
        inputUserName_2->setGeometry(QRect(60, 30, 181, 21));
        lblUserName_2 = new QLabel(gb_2);
        lblUserName_2->setObjectName(QString::fromUtf8("lblUserName_2"));
        lblUserName_2->setGeometry(QRect(10, 30, 41, 21));
        lblPassword_2 = new QLabel(gb_2);
        lblPassword_2->setObjectName(QString::fromUtf8("lblPassword_2"));
        lblPassword_2->setGeometry(QRect(10, 60, 31, 21));
        btnReturnToLogin = new QPushButton(gb_2);
        btnReturnToLogin->setObjectName(QString::fromUtf8("btnReturnToLogin"));
        btnReturnToLogin->setGeometry(QRect(60, 140, 80, 20));
        btnReturnToLogin->setAutoDefault(false);
        btnConfirmRegister = new QPushButton(gb_2);
        btnConfirmRegister->setObjectName(QString::fromUtf8("btnConfirmRegister"));
        btnConfirmRegister->setGeometry(QRect(160, 140, 80, 20));
        lblPassword_3 = new QLabel(gb_2);
        lblPassword_3->setObjectName(QString::fromUtf8("lblPassword_3"));
        lblPassword_3->setGeometry(QRect(10, 90, 51, 21));
        inputPassword_3 = new QLineEdit(gb_2);
        inputPassword_3->setObjectName(QString::fromUtf8("inputPassword_3"));
        inputPassword_3->setGeometry(QRect(60, 90, 181, 21));
        inputPassword_3->setEchoMode(QLineEdit::Password);
        rPlayer = new QRadioButton(gb_2);
        rPlayer->setObjectName(QString::fromUtf8("rPlayer"));
        rPlayer->setGeometry(QRect(60, 120, 61, 18));
        rPlayer->setChecked(true);
        rDesigner = new QRadioButton(gb_2);
        rDesigner->setObjectName(QString::fromUtf8("rDesigner"));
        rDesigner->setGeometry(QRect(170, 120, 71, 20));
#ifndef QT_NO_SHORTCUT
        lblUserName->setBuddy(inputUserName);
        lblPassword->setBuddy(inputPassword);
        lblUserName_2->setBuddy(inputUserName_2);
        lblPassword_2->setBuddy(inputPassword_2);
        lblPassword_3->setBuddy(inputPassword_3);
#endif // QT_NO_SHORTCUT

        retranslateUi(InitialForm);

        QMetaObject::connectSlotsByName(InitialForm);
    } // setupUi

    void retranslateUi(QDialog *InitialForm)
    {
        InitialForm->setWindowTitle(QApplication::translate("InitialForm", "Word Elemination", nullptr));
        gb->setTitle(QString());
        lblUserName->setText(QApplication::translate("InitialForm", "\347\224\250\346\210\267\345\220\215", nullptr));
        lblPassword->setText(QApplication::translate("InitialForm", "\345\257\206\347\240\201", nullptr));
        btnRegister->setText(QApplication::translate("InitialForm", "\346\263\250\345\206\214", nullptr));
        btnLogin->setText(QApplication::translate("InitialForm", "\347\231\273\345\275\225", nullptr));
        gb_2->setTitle(QString());
        lblUserName_2->setText(QApplication::translate("InitialForm", "\347\224\250\346\210\267\345\220\215", nullptr));
        lblPassword_2->setText(QApplication::translate("InitialForm", "\345\257\206\347\240\201", nullptr));
        btnReturnToLogin->setText(QApplication::translate("InitialForm", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        btnConfirmRegister->setText(QApplication::translate("InitialForm", "\347\241\256\350\256\244\346\263\250\345\206\214", nullptr));
        lblPassword_3->setText(QApplication::translate("InitialForm", "\351\207\215\345\244\215\345\257\206\347\240\201", nullptr));
        rPlayer->setText(QApplication::translate("InitialForm", "Player", nullptr));
        rDesigner->setText(QApplication::translate("InitialForm", "Designer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitialForm: public Ui_InitialForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALFORM_H
