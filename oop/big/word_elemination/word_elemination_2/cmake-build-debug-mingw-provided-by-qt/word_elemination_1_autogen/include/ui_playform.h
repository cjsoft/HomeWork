/********************************************************************************
** Form generated from reading UI file 'playform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYFORM_H
#define UI_PLAYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayForm
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *inputWord;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayForm)
    {
        if (PlayForm->objectName().isEmpty())
            PlayForm->setObjectName(QString::fromUtf8("PlayForm"));
        PlayForm->resize(520, 389);
        centralwidget = new QWidget(PlayForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        inputWord = new QLineEdit(centralwidget);
        inputWord->setObjectName(QString::fromUtf8("inputWord"));
        inputWord->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(20);
        inputWord->setFont(font1);
        inputWord->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(inputWord, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        PlayForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 520, 21));
        PlayForm->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlayForm->setStatusBar(statusbar);

        retranslateUi(PlayForm);

        QMetaObject::connectSlotsByName(PlayForm);
    } // setupUi

    void retranslateUi(QMainWindow *PlayForm)
    {
        PlayForm->setWindowTitle(QApplication::translate("PlayForm", "\351\227\257\345\205\263", nullptr));
        label->setText(QString());
        inputWord->setPlaceholderText(QApplication::translate("PlayForm", "Ready to Type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayForm: public Ui_PlayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYFORM_H
