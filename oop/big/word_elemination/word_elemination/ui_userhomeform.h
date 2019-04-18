/********************************************************************************
** Form generated from reading UI file 'userhomeform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERHOMEFORM_H
#define UI_USERHOMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserHomeForm
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblUserName;
    QLabel *lblType;
    QVBoxLayout *verticalLayout;
    QLineEdit *txtUserName;
    QLineEdit *txtType;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblPName;
    QLabel *lblPTag;
    QLabel *lblPuzzlePassed;
    QLabel *lblPExp;
    QLabel *lblPLevel;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *txtPName;
    QLineEdit *txtPTag;
    QLineEdit *txtPPuzzlePassed;
    QLineEdit *txtPExp;
    QLineEdit *txtPLevel;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblDName;
    QLabel *lblDTag;
    QLabel *lblDPuzzleMade;
    QLabel *lblDLevel;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *txtDName;
    QLineEdit *txtDTag;
    QLineEdit *txtDPuzzleMade;
    QLineEdit *txtDLevel;
    QPushButton *btnEditName;
    QPushButton *btnEditTag;
    QPushButton *btnLogout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserHomeForm)
    {
        if (UserHomeForm->objectName().isEmpty())
            UserHomeForm->setObjectName(QString::fromUtf8("UserHomeForm"));
        UserHomeForm->resize(591, 410);
        centralwidget = new QWidget(UserHomeForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 191, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblUserName = new QLabel(horizontalLayoutWidget);
        lblUserName->setObjectName(QString::fromUtf8("lblUserName"));

        verticalLayout_2->addWidget(lblUserName);

        lblType = new QLabel(horizontalLayoutWidget);
        lblType->setObjectName(QString::fromUtf8("lblType"));

        verticalLayout_2->addWidget(lblType);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtUserName = new QLineEdit(horizontalLayoutWidget);
        txtUserName->setObjectName(QString::fromUtf8("txtUserName"));
        txtUserName->setReadOnly(true);

        verticalLayout->addWidget(txtUserName);

        txtType = new QLineEdit(horizontalLayoutWidget);
        txtType->setObjectName(QString::fromUtf8("txtType"));
        txtType->setReadOnly(true);

        verticalLayout->addWidget(txtType);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 130, 160, 138));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lblPName = new QLabel(horizontalLayoutWidget_2);
        lblPName->setObjectName(QString::fromUtf8("lblPName"));

        verticalLayout_4->addWidget(lblPName);

        lblPTag = new QLabel(horizontalLayoutWidget_2);
        lblPTag->setObjectName(QString::fromUtf8("lblPTag"));

        verticalLayout_4->addWidget(lblPTag);

        lblPuzzlePassed = new QLabel(horizontalLayoutWidget_2);
        lblPuzzlePassed->setObjectName(QString::fromUtf8("lblPuzzlePassed"));

        verticalLayout_4->addWidget(lblPuzzlePassed);

        lblPExp = new QLabel(horizontalLayoutWidget_2);
        lblPExp->setObjectName(QString::fromUtf8("lblPExp"));

        verticalLayout_4->addWidget(lblPExp);

        lblPLevel = new QLabel(horizontalLayoutWidget_2);
        lblPLevel->setObjectName(QString::fromUtf8("lblPLevel"));

        verticalLayout_4->addWidget(lblPLevel);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        txtPName = new QLineEdit(horizontalLayoutWidget_2);
        txtPName->setObjectName(QString::fromUtf8("txtPName"));
        txtPName->setReadOnly(true);

        verticalLayout_3->addWidget(txtPName);

        txtPTag = new QLineEdit(horizontalLayoutWidget_2);
        txtPTag->setObjectName(QString::fromUtf8("txtPTag"));
        txtPTag->setReadOnly(true);

        verticalLayout_3->addWidget(txtPTag);

        txtPPuzzlePassed = new QLineEdit(horizontalLayoutWidget_2);
        txtPPuzzlePassed->setObjectName(QString::fromUtf8("txtPPuzzlePassed"));
        txtPPuzzlePassed->setReadOnly(true);

        verticalLayout_3->addWidget(txtPPuzzlePassed);

        txtPExp = new QLineEdit(horizontalLayoutWidget_2);
        txtPExp->setObjectName(QString::fromUtf8("txtPExp"));
        txtPExp->setReadOnly(true);

        verticalLayout_3->addWidget(txtPExp);

        txtPLevel = new QLineEdit(horizontalLayoutWidget_2);
        txtPLevel->setObjectName(QString::fromUtf8("txtPLevel"));
        txtPLevel->setReadOnly(true);

        verticalLayout_3->addWidget(txtPLevel);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(250, 200, 160, 110));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lblDName = new QLabel(horizontalLayoutWidget_3);
        lblDName->setObjectName(QString::fromUtf8("lblDName"));

        verticalLayout_5->addWidget(lblDName);

        lblDTag = new QLabel(horizontalLayoutWidget_3);
        lblDTag->setObjectName(QString::fromUtf8("lblDTag"));

        verticalLayout_5->addWidget(lblDTag);

        lblDPuzzleMade = new QLabel(horizontalLayoutWidget_3);
        lblDPuzzleMade->setObjectName(QString::fromUtf8("lblDPuzzleMade"));

        verticalLayout_5->addWidget(lblDPuzzleMade);

        lblDLevel = new QLabel(horizontalLayoutWidget_3);
        lblDLevel->setObjectName(QString::fromUtf8("lblDLevel"));

        verticalLayout_5->addWidget(lblDLevel);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        txtDName = new QLineEdit(horizontalLayoutWidget_3);
        txtDName->setObjectName(QString::fromUtf8("txtDName"));
        txtDName->setReadOnly(true);

        verticalLayout_6->addWidget(txtDName);

        txtDTag = new QLineEdit(horizontalLayoutWidget_3);
        txtDTag->setObjectName(QString::fromUtf8("txtDTag"));
        txtDTag->setReadOnly(true);

        verticalLayout_6->addWidget(txtDTag);

        txtDPuzzleMade = new QLineEdit(horizontalLayoutWidget_3);
        txtDPuzzleMade->setObjectName(QString::fromUtf8("txtDPuzzleMade"));
        txtDPuzzleMade->setReadOnly(true);

        verticalLayout_6->addWidget(txtDPuzzleMade);

        txtDLevel = new QLineEdit(horizontalLayoutWidget_3);
        txtDLevel->setObjectName(QString::fromUtf8("txtDLevel"));
        txtDLevel->setReadOnly(true);

        verticalLayout_6->addWidget(txtDLevel);


        horizontalLayout_3->addLayout(verticalLayout_6);

        btnEditName = new QPushButton(centralwidget);
        btnEditName->setObjectName(QString::fromUtf8("btnEditName"));
        btnEditName->setGeometry(QRect(270, 130, 91, 23));
        btnEditTag = new QPushButton(centralwidget);
        btnEditTag->setObjectName(QString::fromUtf8("btnEditTag"));
        btnEditTag->setGeometry(QRect(270, 160, 91, 23));
        btnLogout = new QPushButton(centralwidget);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));
        btnLogout->setGeometry(QRect(270, 100, 91, 21));
        UserHomeForm->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UserHomeForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserHomeForm->setStatusBar(statusbar);

        retranslateUi(UserHomeForm);

        QMetaObject::connectSlotsByName(UserHomeForm);
    } // setupUi

    void retranslateUi(QMainWindow *UserHomeForm)
    {
        UserHomeForm->setWindowTitle(QApplication::translate("UserHomeForm", "MainWindow", nullptr));
        lblUserName->setText(QApplication::translate("UserHomeForm", "\347\224\250\346\210\267\345\220\215", nullptr));
        lblType->setText(QApplication::translate("UserHomeForm", "\347\224\250\346\210\267\347\261\273\345\210\253", nullptr));
        lblPName->setText(QApplication::translate("UserHomeForm", "\345\247\223\345\220\215", nullptr));
        lblPTag->setText(QApplication::translate("UserHomeForm", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        lblPuzzlePassed->setText(QApplication::translate("UserHomeForm", "\351\227\257\345\205\263\346\225\260", nullptr));
        lblPExp->setText(QApplication::translate("UserHomeForm", "\347\273\217\351\252\214\345\200\274", nullptr));
        lblPLevel->setText(QApplication::translate("UserHomeForm", "\347\255\211\347\272\247", nullptr));
        lblDName->setText(QApplication::translate("UserHomeForm", "\345\247\223\345\220\215", nullptr));
        lblDTag->setText(QApplication::translate("UserHomeForm", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        lblDPuzzleMade->setText(QApplication::translate("UserHomeForm", "\345\207\272\351\242\230\346\225\260\347\233\256", nullptr));
        lblDLevel->setText(QApplication::translate("UserHomeForm", "\347\255\211\347\272\247", nullptr));
        btnEditName->setText(QApplication::translate("UserHomeForm", "\344\277\256\346\224\271\345\247\223\345\220\215", nullptr));
        btnEditTag->setText(QApplication::translate("UserHomeForm", "\344\277\256\346\224\271\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        btnLogout->setText(QApplication::translate("UserHomeForm", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserHomeForm: public Ui_UserHomeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERHOMEFORM_H
