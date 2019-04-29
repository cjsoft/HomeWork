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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QComboBox *cbo;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSearch;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ListUsersForm)
    {
        if (ListUsersForm->objectName().isEmpty())
            ListUsersForm->setObjectName(QString::fromUtf8("ListUsersForm"));
        ListUsersForm->resize(659, 566);
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
        tblP->setProperty("showDropIndicator", QVariant(false));
        tblP->setSelectionMode(QAbstractItemView::SingleSelection);
        tblP->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblP->setSortingEnabled(true);
        tblP->setColumnCount(6);

        gLotP->addWidget(tblP, 1, 0, 1, 2);


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
        tblD->setProperty("showDropIndicator", QVariant(false));
        tblD->setSelectionMode(QAbstractItemView::SingleSelection);
        tblD->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblD->setSortingEnabled(true);
        tblD->setColumnCount(5);
        tblD->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        gLotD->addWidget(tblD, 0, 0, 1, 1);


        gridLayout_4->addLayout(gLotD, 0, 0, 1, 1);

        tabWidget->addTab(tabD, QString());

        gridLayout_2->addWidget(tabWidget, 2, 0, 1, 2);

        cbo = new QComboBox(centralwidget);
        cbo->addItem(QString());
        cbo->addItem(QString());
        cbo->addItem(QString());
        cbo->addItem(QString());
        cbo->addItem(QString());
        cbo->addItem(QString());
        cbo->addItem(QString());
        cbo->addItem(QString());
        cbo->setObjectName(QString::fromUtf8("cbo"));

        gridLayout_2->addWidget(cbo, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        btnSearch = new QPushButton(centralwidget);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setMinimumSize(QSize(0, 20));

        gridLayout_2->addWidget(btnSearch, 0, 1, 1, 1);

        ListUsersForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ListUsersForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 659, 21));
        ListUsersForm->setMenuBar(menubar);
        statusbar = new QStatusBar(ListUsersForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ListUsersForm->setStatusBar(statusbar);
        QWidget::setTabOrder(cbo, btnSearch);
        QWidget::setTabOrder(btnSearch, tabWidget);
        QWidget::setTabOrder(tabWidget, tblP);
        QWidget::setTabOrder(tblP, tblD);

        retranslateUi(ListUsersForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ListUsersForm);
    } // setupUi

    void retranslateUi(QMainWindow *ListUsersForm)
    {
        ListUsersForm->setWindowTitle(QApplication::translate("ListUsersForm", "\347\224\250\346\210\267\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabP), QApplication::translate("ListUsersForm", "Player", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabD), QApplication::translate("ListUsersForm", "Designer", nullptr));
        cbo->setItemText(0, QApplication::translate("ListUsersForm", "\347\224\250\346\210\267\345\220\215", nullptr));
        cbo->setItemText(1, QApplication::translate("ListUsersForm", "\345\247\223\345\220\215", nullptr));
        cbo->setItemText(2, QApplication::translate("ListUsersForm", "\351\227\257\345\205\263\346\225\260", nullptr));
        cbo->setItemText(3, QApplication::translate("ListUsersForm", "\347\273\217\351\252\214\345\200\274", nullptr));
        cbo->setItemText(4, QApplication::translate("ListUsersForm", "\347\255\211\347\272\247", nullptr));
        cbo->setItemText(5, QApplication::translate("ListUsersForm", "\345\207\272\351\242\230\346\225\260", nullptr));
        cbo->setItemText(6, QApplication::translate("ListUsersForm", "\345\234\250\347\272\277", nullptr));
        cbo->setItemText(7, QApplication::translate("ListUsersForm", "\347\246\273\347\272\277", nullptr));

        btnSearch->setText(QApplication::translate("ListUsersForm", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListUsersForm: public Ui_ListUsersForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTUSERSFORM_H
