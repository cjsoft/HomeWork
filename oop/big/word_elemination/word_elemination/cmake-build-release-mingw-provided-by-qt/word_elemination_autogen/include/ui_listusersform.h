/********************************************************************************
** Form generated from reading UI file 'listusersform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTUSERSFORM_H
#define UI_LISTUSERSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListUsersForm
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabP;
    QGridLayout *gridLayout;
    QGridLayout *gLotP;
    QTableWidget *tblP;
    QWidget *tabD;
    QGridLayout *gridLayout_4;
    QGridLayout *gLotD;
    QTableWidget *tblD;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ListUsersForm)
    {
        if (ListUsersForm->objectName().isEmpty())
            ListUsersForm->setObjectName(QString::fromUtf8("ListUsersForm"));
        ListUsersForm->resize(808, 566);
        centralwidget = new QWidget(ListUsersForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabP = new QWidget();
        tabP->setObjectName(QString::fromUtf8("tabP"));
        gridLayout = new QGridLayout(tabP);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gLotP = new QGridLayout();
        gLotP->setObjectName(QString::fromUtf8("gLotP"));
        tblP = new QTableWidget(tabP);
        if (tblP->columnCount() < 6)
            tblP->setColumnCount(6);
        tblP->setObjectName(QString::fromUtf8("tblP"));
        tblP->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblP->setSelectionMode(QAbstractItemView::SingleSelection);
        tblP->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblP->setSortingEnabled(true);
        tblP->setColumnCount(6);

        gLotP->addWidget(tblP, 0, 0, 1, 1);


        gridLayout->addLayout(gLotP, 0, 0, 1, 1);

        tabWidget->addTab(tabP, QString());
        tabD = new QWidget();
        tabD->setObjectName(QString::fromUtf8("tabD"));
        gridLayout_4 = new QGridLayout(tabD);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gLotD = new QGridLayout();
        gLotD->setObjectName(QString::fromUtf8("gLotD"));
        tblD = new QTableWidget(tabD);
        if (tblD->columnCount() < 5)
            tblD->setColumnCount(5);
        tblD->setObjectName(QString::fromUtf8("tblD"));
        tblD->setMinimumSize(QSize(50, 50));
        tblD->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblD->setSelectionMode(QAbstractItemView::SingleSelection);
        tblD->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblD->setSortingEnabled(true);
        tblD->setColumnCount(5);
        tblD->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        gLotD->addWidget(tblD, 0, 0, 1, 1);


        gridLayout_4->addLayout(gLotD, 0, 0, 1, 1);

        tabWidget->addTab(tabD, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        ListUsersForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ListUsersForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 808, 22));
        ListUsersForm->setMenuBar(menubar);
        statusbar = new QStatusBar(ListUsersForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ListUsersForm->setStatusBar(statusbar);

        retranslateUi(ListUsersForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ListUsersForm);
    } // setupUi

    void retranslateUi(QMainWindow *ListUsersForm)
    {
        ListUsersForm->setWindowTitle(QApplication::translate("ListUsersForm", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabP), QApplication::translate("ListUsersForm", "Player", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabD), QApplication::translate("ListUsersForm", "Designer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListUsersForm: public Ui_ListUsersForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTUSERSFORM_H
