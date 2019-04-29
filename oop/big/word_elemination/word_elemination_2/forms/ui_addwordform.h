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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWordForm
{
public:
    QAction *actionfanhui;
    QAction *actReturn;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSplitter *splitter;
    QLineEdit *inputWord;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *AddWordForm)
    {
        if (AddWordForm->objectName().isEmpty())
            AddWordForm->setObjectName(QString::fromUtf8("AddWordForm"));
        AddWordForm->resize(330, 101);
        actionfanhui = new QAction(AddWordForm);
        actionfanhui->setObjectName(QString::fromUtf8("actionfanhui"));
        actReturn = new QAction(AddWordForm);
        actReturn->setObjectName(QString::fromUtf8("actReturn"));
        centralwidget = new QWidget(AddWordForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(300, 50));
        splitter->setMaximumSize(QSize(800, 100));
        splitter->setOrientation(Qt::Horizontal);
        inputWord = new QLineEdit(splitter);
        inputWord->setObjectName(QString::fromUtf8("inputWord"));
        QFont font;
        font.setPointSize(20);
        inputWord->setFont(font);
        splitter->addWidget(inputWord);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        splitter->addWidget(pushButton);

        gridLayout->addWidget(splitter, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        AddWordForm->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(AddWordForm);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 330, 21));
        AddWordForm->setMenuBar(menuBar);

        retranslateUi(AddWordForm);

        QMetaObject::connectSlotsByName(AddWordForm);
    } // setupUi

    void retranslateUi(QMainWindow *AddWordForm)
    {
        AddWordForm->setWindowTitle(QApplication::translate("AddWordForm", "\346\267\273\345\212\240\345\215\225\350\257\215", nullptr));
        actionfanhui->setText(QApplication::translate("AddWordForm", "fanhui", nullptr));
        actReturn->setText(QApplication::translate("AddWordForm", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", nullptr));
        inputWord->setText(QString());
        inputWord->setPlaceholderText(QApplication::translate("AddWordForm", "\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\345\215\225\350\257\215", nullptr));
        pushButton->setText(QApplication::translate("AddWordForm", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWordForm: public Ui_AddWordForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWORDFORM_H
