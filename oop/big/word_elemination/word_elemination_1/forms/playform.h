#pragma once
#ifndef PLAYFORM_H
#define PLAYFORM_H

#include <QMainWindow>
#include <QTimer>
#include <QPalette>
#include <QEvent>
#include "../challenge.h"
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
    QPalette color[2];
    QString clr[2];
    QLabel *lblstatus;
    char colorindicator;
    int pti;
    bool playing;
    Challenge challenge;
    void loadChallenge(const Challenge &cha);
    void nextQuiz();
    void completeChallenge();
    void updateStatusBar();
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
