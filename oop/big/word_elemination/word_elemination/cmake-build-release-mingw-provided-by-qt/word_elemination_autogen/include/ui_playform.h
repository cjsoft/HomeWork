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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayForm
{
public:
    QWidget *centralwidget;
    QLineEdit *inputWord;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayForm)
    {
        if (PlayForm->objectName().isEmpty())
            PlayForm->setObjectName(QString::fromUtf8("PlayForm"));
        PlayForm->resize(500, 415);
        centralwidget = new QWidget(PlayForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        inputWord = new QLineEdit(centralwidget);
        inputWord->setObjectName(QString::fromUtf8("inputWord"));
        inputWord->setGeometry(QRect(90, 210, 311, 41));
        QFont font;
        font.setPointSize(20);
        inputWord->setFont(font);
        inputWord->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 60, 501, 91));
        QFont font1;
        font1.setPointSize(25);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        PlayForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 22));
        PlayForm->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlayForm->setStatusBar(statusbar);

        retranslateUi(PlayForm);

        QMetaObject::connectSlotsByName(PlayForm);
    } // setupUi

    void retranslateUi(QMainWindow *PlayForm)
    {
        PlayForm->setWindowTitle(QApplication::translate("PlayForm", "MainWindow", nullptr));
        inputWord->setPlaceholderText(QApplication::translate("PlayForm", "Ready to Type", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayForm: public Ui_PlayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYFORM_H
