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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitialForm
{
public:
    QGroupBox *gb;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lblUserName;
    QLineEdit *inputUserName;
    QLabel *lblPassword;
    QLineEdit *inputPassword;
    QPushButton *btnRegister;
    QPushButton *btnLogin;
    QGroupBox *gb_2;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *lblUserName_2;
    QLineEdit *inputUserName_2;
    QLabel *lblPassword_2;
    QLineEdit *inputPassword_2;
    QLabel *lblPassword_3;
    QLineEdit *inputPassword_3;
    QRadioButton *rPlayer;
    QRadioButton *rDesigner;
    QPushButton *btnReturnToLogin;
    QPushButton *btnConfirmRegister;
    QLabel *label;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *lblIcon;
    QLabel *lblProject;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *InitialForm)
    {
        if (InitialForm->objectName().isEmpty())
            InitialForm->setObjectName(QString::fromUtf8("InitialForm"));
        InitialForm->resize(599, 485);
        gb = new QGroupBox(InitialForm);
        gb->setObjectName(QString::fromUtf8("gb"));
        gb->setGeometry(QRect(10, 59, 261, 111));
        widget = new QWidget(gb);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 241, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblUserName = new QLabel(widget);
        lblUserName->setObjectName(QString::fromUtf8("lblUserName"));

        gridLayout->addWidget(lblUserName, 0, 0, 1, 1);

        inputUserName = new QLineEdit(widget);
        inputUserName->setObjectName(QString::fromUtf8("inputUserName"));

        gridLayout->addWidget(inputUserName, 0, 1, 1, 2);

        lblPassword = new QLabel(widget);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));

        gridLayout->addWidget(lblPassword, 1, 0, 1, 1);

        inputPassword = new QLineEdit(widget);
        inputPassword->setObjectName(QString::fromUtf8("inputPassword"));
        inputPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(inputPassword, 1, 1, 1, 2);

        btnRegister = new QPushButton(widget);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setAutoDefault(false);

        gridLayout->addWidget(btnRegister, 2, 1, 1, 1);

        btnLogin = new QPushButton(widget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        gridLayout->addWidget(btnLogin, 2, 2, 1, 1);

        gb_2 = new QGroupBox(InitialForm);
        gb_2->setObjectName(QString::fromUtf8("gb_2"));
        gb_2->setGeometry(QRect(290, 10, 251, 161));
        widget1 = new QWidget(gb_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 20, 231, 131));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lblUserName_2 = new QLabel(widget1);
        lblUserName_2->setObjectName(QString::fromUtf8("lblUserName_2"));

        gridLayout_2->addWidget(lblUserName_2, 0, 0, 1, 1);

        inputUserName_2 = new QLineEdit(widget1);
        inputUserName_2->setObjectName(QString::fromUtf8("inputUserName_2"));

        gridLayout_2->addWidget(inputUserName_2, 0, 1, 1, 2);

        lblPassword_2 = new QLabel(widget1);
        lblPassword_2->setObjectName(QString::fromUtf8("lblPassword_2"));

        gridLayout_2->addWidget(lblPassword_2, 1, 0, 1, 1);

        inputPassword_2 = new QLineEdit(widget1);
        inputPassword_2->setObjectName(QString::fromUtf8("inputPassword_2"));
        inputPassword_2->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(inputPassword_2, 1, 1, 1, 2);

        lblPassword_3 = new QLabel(widget1);
        lblPassword_3->setObjectName(QString::fromUtf8("lblPassword_3"));

        gridLayout_2->addWidget(lblPassword_3, 2, 0, 1, 1);

        inputPassword_3 = new QLineEdit(widget1);
        inputPassword_3->setObjectName(QString::fromUtf8("inputPassword_3"));
        inputPassword_3->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(inputPassword_3, 2, 1, 1, 2);

        rPlayer = new QRadioButton(widget1);
        rPlayer->setObjectName(QString::fromUtf8("rPlayer"));
        rPlayer->setChecked(true);

        gridLayout_2->addWidget(rPlayer, 3, 1, 1, 1);

        rDesigner = new QRadioButton(widget1);
        rDesigner->setObjectName(QString::fromUtf8("rDesigner"));

        gridLayout_2->addWidget(rDesigner, 3, 2, 1, 1);

        btnReturnToLogin = new QPushButton(widget1);
        btnReturnToLogin->setObjectName(QString::fromUtf8("btnReturnToLogin"));
        btnReturnToLogin->setAutoDefault(false);

        gridLayout_2->addWidget(btnReturnToLogin, 4, 1, 1, 1);

        btnConfirmRegister = new QPushButton(widget1);
        btnConfirmRegister->setObjectName(QString::fromUtf8("btnConfirmRegister"));

        gridLayout_2->addWidget(btnConfirmRegister, 4, 2, 1, 1);

        label = new QLabel(InitialForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 40, 271, 20));
        label->setAlignment(Qt::AlignCenter);
        widget2 = new QWidget(InitialForm);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(0, 0, 271, 41));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblIcon = new QLabel(widget2);
        lblIcon->setObjectName(QString::fromUtf8("lblIcon"));

        horizontalLayout->addWidget(lblIcon);

        lblProject = new QLabel(widget2);
        lblProject->setObjectName(QString::fromUtf8("lblProject"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        lblProject->setFont(font);
        lblProject->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lblProject);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

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
        lblPassword_3->setText(QApplication::translate("InitialForm", "\351\207\215\345\244\215\345\257\206\347\240\201", nullptr));
        rPlayer->setText(QApplication::translate("InitialForm", "Player", nullptr));
        rDesigner->setText(QApplication::translate("InitialForm", "Designer", nullptr));
        btnReturnToLogin->setText(QApplication::translate("InitialForm", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        btnConfirmRegister->setText(QApplication::translate("InitialForm", "\347\241\256\350\256\244\346\263\250\345\206\214", nullptr));
        label->setText(QApplication::translate("InitialForm", "By CJSoft", nullptr));
        lblIcon->setText(QString());
        lblProject->setText(QApplication::translate("InitialForm", "Word Elemination", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitialForm: public Ui_InitialForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALFORM_H
