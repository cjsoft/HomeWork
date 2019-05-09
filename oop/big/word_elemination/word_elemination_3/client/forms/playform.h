#pragma once
#ifndef PLAYFORM_H
#define PLAYFORM_H

#include <QMainWindow>
#include <QTimer>
#include <QPalette>
#include <QEvent>
#include <QTime>
#include <QLabel>
#include "../../utils/challenge.h"
namespace Ui {
class PlayForm;
}

class Challenge;
class PlayForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayForm(QWidget *parent = nullptr);
    void show();
    ~PlayForm();

private:
    Ui::PlayForm *ui;
    QTimer tmrBlink, tmrDisable, tmrHide;
    QTime timecounter;
    QPalette color[2];
    QString clr[2];
    QLabel *lblstatus, *lblFcnt, *lblQuizno;
    char colorindicator;
    int pti;
    bool playing;
    int fcnt;
    Challenge challenge;
    void loadChallenge(const Challenge &cha);
    void nextQuiz();
    void completeChallenge();
    void updateStatusBarUserInfo();
    void updateStatusBarFcnt();
    void updateStatusBarQuizno();
    void showEvent(QShowEvent* event) override;
    virtual void closeEvent(QCloseEvent *event) override;
    void formShown();
private slots:
    void hideWord();
    void on_inputWord_returnPressed();
    void changeColor();
    void disableTimer();
};

#endif // PLAYFORM_H
