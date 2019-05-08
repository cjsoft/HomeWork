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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserHomeForm
{
public:
    QWidget *centralwidget;
    QWidget *cnterD;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *lblDPuzzleMade;
    QLabel *lblDName;
    QLabel *lblDLevel;
    QLabel *lblDTag;
    QLineEdit *txtDName;
    QLineEdit *txtDTag;
    QLineEdit *txtDPuzzleMade;
    QLineEdit *txtDLevel;
    QWidget *cnterP;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lblPExp;
    QLineEdit *txtPName;
    QLabel *lblPLevel;
    QLabel *lblPName;
    QLabel *lblPuzzlePassed;
    QLabel *lblPTag;
    QLineEdit *txtPTag;
    QLineEdit *txtPPuzzlePassed;
    QLineEdit *txtPExp;
    QLineEdit *txtPLevel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAddWord;
    QPushButton *btnPlay;
    QPushButton *btnAll;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnEditName;
    QPushButton *btnEditTag;
    QPushButton *btnLogout;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *lblUserName;
    QLabel *lblType;
    QLineEdit *txtUserName;
    QLineEdit *txtType;

    void setupUi(QMainWindow *UserHomeForm)
    {
        if (UserHomeForm->objectName().isEmpty())
            UserHomeForm->setObjectName(QString::fromUtf8("UserHomeForm"));
        UserHomeForm->resize(597, 604);
        centralwidget = new QWidget(UserHomeForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cnterD = new QWidget(centralwidget);
        cnterD->setObjectName(QString::fromUtf8("cnterD"));
        cnterD->setGeometry(QRect(10, 300, 281, 121));
        gridLayoutWidget_2 = new QWidget(cnterD);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(1, 1, 271, 108));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lblDPuzzleMade = new QLabel(gridLayoutWidget_2);
        lblDPuzzleMade->setObjectName(QString::fromUtf8("lblDPuzzleMade"));

        gridLayout_2->addWidget(lblDPuzzleMade, 2, 0, 1, 1);

        lblDName = new QLabel(gridLayoutWidget_2);
        lblDName->setObjectName(QString::fromUtf8("lblDName"));

        gridLayout_2->addWidget(lblDName, 0, 0, 1, 1);

        lblDLevel = new QLabel(gridLayoutWidget_2);
        lblDLevel->setObjectName(QString::fromUtf8("lblDLevel"));

        gridLayout_2->addWidget(lblDLevel, 3, 0, 1, 1);

        lblDTag = new QLabel(gridLayoutWidget_2);
        lblDTag->setObjectName(QString::fromUtf8("lblDTag"));

        gridLayout_2->addWidget(lblDTag, 1, 0, 1, 1);

        txtDName = new QLineEdit(gridLayoutWidget_2);
        txtDName->setObjectName(QString::fromUtf8("txtDName"));
        txtDName->setReadOnly(true);

        gridLayout_2->addWidget(txtDName, 0, 1, 1, 1);

        txtDTag = new QLineEdit(gridLayoutWidget_2);
        txtDTag->setObjectName(QString::fromUtf8("txtDTag"));
        txtDTag->setReadOnly(true);

        gridLayout_2->addWidget(txtDTag, 1, 1, 1, 1);

        txtDPuzzleMade = new QLineEdit(gridLayoutWidget_2);
        txtDPuzzleMade->setObjectName(QString::fromUtf8("txtDPuzzleMade"));
        txtDPuzzleMade->setReadOnly(true);

        gridLayout_2->addWidget(txtDPuzzleMade, 2, 1, 1, 1);

        txtDLevel = new QLineEdit(gridLayoutWidget_2);
        txtDLevel->setObjectName(QString::fromUtf8("txtDLevel"));
        txtDLevel->setReadOnly(true);

        gridLayout_2->addWidget(txtDLevel, 3, 1, 1, 1);

        cnterP = new QWidget(centralwidget);
        cnterP->setObjectName(QString::fromUtf8("cnterP"));
        cnterP->setGeometry(QRect(10, 150, 281, 151));
        gridLayoutWidget = new QWidget(cnterP);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 271, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lblPExp = new QLabel(gridLayoutWidget);
        lblPExp->setObjectName(QString::fromUtf8("lblPExp"));

        gridLayout->addWidget(lblPExp, 3, 0, 1, 1);

        txtPName = new QLineEdit(gridLayoutWidget);
        txtPName->setObjectName(QString::fromUtf8("txtPName"));
        txtPName->setReadOnly(true);

        gridLayout->addWidget(txtPName, 0, 1, 1, 1);

        lblPLevel = new QLabel(gridLayoutWidget);
        lblPLevel->setObjectName(QString::fromUtf8("lblPLevel"));

        gridLayout->addWidget(lblPLevel, 4, 0, 1, 1);

        lblPName = new QLabel(gridLayoutWidget);
        lblPName->setObjectName(QString::fromUtf8("lblPName"));

        gridLayout->addWidget(lblPName, 0, 0, 1, 1);

        lblPuzzlePassed = new QLabel(gridLayoutWidget);
        lblPuzzlePassed->setObjectName(QString::fromUtf8("lblPuzzlePassed"));

        gridLayout->addWidget(lblPuzzlePassed, 2, 0, 1, 1);

        lblPTag = new QLabel(gridLayoutWidget);
        lblPTag->setObjectName(QString::fromUtf8("lblPTag"));

        gridLayout->addWidget(lblPTag, 1, 0, 1, 1);

        txtPTag = new QLineEdit(gridLayoutWidget);
        txtPTag->setObjectName(QString::fromUtf8("txtPTag"));
        txtPTag->setReadOnly(true);

        gridLayout->addWidget(txtPTag, 1, 1, 1, 1);

        txtPPuzzlePassed = new QLineEdit(gridLayoutWidget);
        txtPPuzzlePassed->setObjectName(QString::fromUtf8("txtPPuzzlePassed"));
        txtPPuzzlePassed->setReadOnly(true);

        gridLayout->addWidget(txtPPuzzlePassed, 2, 1, 1, 1);

        txtPExp = new QLineEdit(gridLayoutWidget);
        txtPExp->setObjectName(QString::fromUtf8("txtPExp"));
        txtPExp->setReadOnly(true);

        gridLayout->addWidget(txtPExp, 3, 1, 1, 1);

        txtPLevel = new QLineEdit(gridLayoutWidget);
        txtPLevel->setObjectName(QString::fromUtf8("txtPLevel"));
        txtPLevel->setReadOnly(true);

        gridLayout->addWidget(txtPLevel, 4, 1, 1, 1);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 271, 61));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnAddWord = new QPushButton(verticalLayoutWidget);
        btnAddWord->setObjectName(QString::fromUtf8("btnAddWord"));

        horizontalLayout_2->addWidget(btnAddWord);

        btnPlay = new QPushButton(verticalLayoutWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));

        horizontalLayout_2->addWidget(btnPlay);

        btnAll = new QPushButton(verticalLayoutWidget);
        btnAll->setObjectName(QString::fromUtf8("btnAll"));

        horizontalLayout_2->addWidget(btnAll);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnEditName = new QPushButton(verticalLayoutWidget);
        btnEditName->setObjectName(QString::fromUtf8("btnEditName"));

        horizontalLayout_3->addWidget(btnEditName);

        btnEditTag = new QPushButton(verticalLayoutWidget);
        btnEditTag->setObjectName(QString::fromUtf8("btnEditTag"));

        horizontalLayout_3->addWidget(btnEditTag);

        btnLogout = new QPushButton(verticalLayoutWidget);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));

        horizontalLayout_3->addWidget(btnLogout);


        verticalLayout_7->addLayout(horizontalLayout_3);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 79, 271, 61));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lblUserName = new QLabel(gridLayoutWidget_3);
        lblUserName->setObjectName(QString::fromUtf8("lblUserName"));

        gridLayout_3->addWidget(lblUserName, 0, 0, 1, 1);

        lblType = new QLabel(gridLayoutWidget_3);
        lblType->setObjectName(QString::fromUtf8("lblType"));

        gridLayout_3->addWidget(lblType, 1, 0, 1, 1);

        txtUserName = new QLineEdit(gridLayoutWidget_3);
        txtUserName->setObjectName(QString::fromUtf8("txtUserName"));
        txtUserName->setReadOnly(true);

        gridLayout_3->addWidget(txtUserName, 0, 1, 1, 1);

        txtType = new QLineEdit(gridLayoutWidget_3);
        txtType->setObjectName(QString::fromUtf8("txtType"));
        txtType->setReadOnly(true);

        gridLayout_3->addWidget(txtType, 1, 1, 1, 1);

        UserHomeForm->setCentralWidget(centralwidget);
        cnterP->raise();
        cnterD->raise();
        verticalLayoutWidget->raise();
        gridLayoutWidget_3->raise();
        QWidget::setTabOrder(btnAddWord, btnPlay);
        QWidget::setTabOrder(btnPlay, btnAll);
        QWidget::setTabOrder(btnAll, btnEditName);
        QWidget::setTabOrder(btnEditName, btnEditTag);
        QWidget::setTabOrder(btnEditTag, btnLogout);
        QWidget::setTabOrder(btnLogout, txtPName);
        QWidget::setTabOrder(txtPName, txtPTag);
        QWidget::setTabOrder(txtPTag, txtPPuzzlePassed);
        QWidget::setTabOrder(txtPPuzzlePassed, txtPExp);
        QWidget::setTabOrder(txtPExp, txtPLevel);

        retranslateUi(UserHomeForm);

        QMetaObject::connectSlotsByName(UserHomeForm);
    } // setupUi

    void retranslateUi(QMainWindow *UserHomeForm)
    {
        UserHomeForm->setWindowTitle(QApplication::translate("UserHomeForm", "\347\224\250\346\210\267\344\270\255\345\277\203", nullptr));
        lblDPuzzleMade->setText(QApplication::translate("UserHomeForm", "\345\207\272\351\242\230\346\225\260\347\233\256", nullptr));
        lblDName->setText(QApplication::translate("UserHomeForm", "\345\247\223\345\220\215", nullptr));
        lblDLevel->setText(QApplication::translate("UserHomeForm", "\347\255\211\347\272\247", nullptr));
        lblDTag->setText(QApplication::translate("UserHomeForm", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        lblPExp->setText(QApplication::translate("UserHomeForm", "\347\273\217\351\252\214\345\200\274", nullptr));
        lblPLevel->setText(QApplication::translate("UserHomeForm", "\347\255\211\347\272\247", nullptr));
        lblPName->setText(QApplication::translate("UserHomeForm", "\345\247\223\345\220\215", nullptr));
        lblPuzzlePassed->setText(QApplication::translate("UserHomeForm", "\351\227\257\345\205\263\346\225\260", nullptr));
        lblPTag->setText(QApplication::translate("UserHomeForm", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        btnAddWord->setText(QApplication::translate("UserHomeForm", "\345\207\272\351\242\230", nullptr));
        btnPlay->setText(QApplication::translate("UserHomeForm", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        btnAll->setText(QApplication::translate("UserHomeForm", "\346\211\200\346\234\211\347\224\250\346\210\267", nullptr));
        btnEditName->setText(QApplication::translate("UserHomeForm", "\344\277\256\346\224\271\345\247\223\345\220\215", nullptr));
        btnEditTag->setText(QApplication::translate("UserHomeForm", "\344\277\256\346\224\271\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        btnLogout->setText(QApplication::translate("UserHomeForm", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        lblUserName->setText(QApplication::translate("UserHomeForm", "\347\224\250\346\210\267\345\220\215", nullptr));
        lblType->setText(QApplication::translate("UserHomeForm", "\347\224\250\346\210\267\347\261\273\345\210\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserHomeForm: public Ui_UserHomeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERHOMEFORM_H
