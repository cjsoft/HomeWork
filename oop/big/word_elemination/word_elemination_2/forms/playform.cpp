#include "playform.h"
#include "ui_playform.h"
#include "../common.h"
#include "userhomeform.h"
#include <QValidator>
class UserHomeForm;
extern UserHomeForm *pUserHomeForm;
PlayForm::PlayForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayForm)
{
    playing = false;
    pti = -1;
    ui->setupUi(this);
    ui->inputWord->setValidator(new QRegExpValidator(QRegExp("[0-9a-zA-Z\\.\\- \'&]+"), ui->inputWord));
    lblstatus = new QLabel;
    lblFcnt = new QLabel;
    lblQuizno = new QLabel;
    ui->statusbar->addWidget(lblstatus);
    ui->statusbar->addWidget(lblQuizno);
    ui->statusbar->addWidget(lblFcnt);
    color[1].setColor(QPalette::Text, Qt::red);
    color[0].setColor(QPalette::Text, Qt::black);
    clr[1] = "QLineEdit {color:red}";
    clr[0] = "QLineEdit {color:white}";
    colorindicator = 0;
    connect(&tmrBlink, SIGNAL(timeout()), this, SLOT(changeColor()));
    connect(&tmrDisable, SIGNAL(timeout()), this, SLOT(disableTimer()));
    connect(&tmrHide, SIGNAL(timeout()), this, SLOT(hideWord()));
}

PlayForm::~PlayForm()
{
    delete ui;
}

void PlayForm::loadChallenge(const Challenge &cha) {
    challenge = cha;
    fcnt = 0;
    pti = -1;
    playing = true;
    ui->inputWord->setText("");
    timecounter.restart();
    nextQuiz();
}

void PlayForm::nextQuiz() {
    if (pti + 1 >= challenge.getQzlist().size()) {
        completeChallenge();
    } else {
        auto quiz = challenge.getQzlist().at(++pti);
        updateStatusBarQuizno();
        updateStatusBarFcnt();
        tmrHide.stop();
        ui->label->setText(quiz.getWord());
        tmrHide.start(quiz.getTime());
    }
}

void PlayForm::hideWord() {
    tmrHide.stop();
    ui->label->setText("");
}

void PlayForm::completeChallenge() {
    playing = false;
    lcc.finishChallenge(challenge.getDifficulty(), calcScore(challenge, static_cast<Player const*>(lcc.getCurrentUser())->getPuzzlepassed(), timecounter.elapsed(), fcnt));
    updateStatusBarUserInfo();
    int choice = MessageBox("通关！\n是否要再来一关？", "提示", QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if (choice == QMessageBox::No) {
        pUserHomeForm->updateDisplay();
        pUserHomeForm->show();
        this->close();
    } else {
        loadChallenge(lcc.constructChallenge(static_cast<Player const*>(lcc.getCurrentUser())->getPuzzlepassed()));
    }
    qDebug() << "challenge finished";
}

void PlayForm::on_inputWord_returnPressed() {
    if (playing) {
        qDebug() << ui->inputWord->text() << challenge.getQzlist().at(pti).getWord();
        if (ui->inputWord->text() == challenge.getQzlist().at(pti).getWord()) {
            ui->inputWord->setText("");
            nextQuiz();
        } else {
            fcnt++;
            updateStatusBarFcnt();
            changeColor();
            tmrBlink.start(150);
            tmrDisable.start(900);
            if (fcnt > challenge.getMaximumtries()) {
                int choice = MessageBox("闯关失败！\n是否要重来？", "提示", QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
                if (choice == QMessageBox::No) {
                    pUserHomeForm->show();
                    this->close();
                } else {
                    loadChallenge(challenge);
                }
            }
        }
    }
}

void PlayForm::formShown() {
    updateStatusBarUserInfo();
    lcc.fetchWordlist();
    loadChallenge(lcc.constructChallenge(static_cast<Player const*>(lcc.getCurrentUser())->getPuzzlepassed()));
}

void PlayForm::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
}

void PlayForm::changeColor() {
    ui->inputWord->setPalette(color[colorindicator ^= 1]);
    ui->inputWord->setStyleSheet(clr[colorindicator]);
}

void PlayForm::disableTimer() {
    tmrDisable.stop();
    tmrBlink.stop();
    ui->inputWord->setPalette(color[colorindicator = 0]);
    ui->inputWord->setStyleSheet(clr[colorindicator]);
}

void PlayForm::updateStatusBarUserInfo() {
    if (lblstatus == nullptr) return;
    lcc.fetchInfo();
    Player const *ply = static_cast<Player const*>(lcc.getCurrentUser());
    lblstatus->setText(QString().sprintf("第%d关  经验值:%d  等级:%d", ply->getPuzzlepassed(), ply->getExp(), ply->getLevel()));
}

void PlayForm::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    pUserHomeForm->updateDisplay();
}

void PlayForm::show() {
    QMainWindow::show();
    formShown();
}

void PlayForm::updateStatusBarFcnt() {
    if (lblFcnt) {
        lblFcnt->setText(QString().sprintf("当前剩余机会:%d", challenge.getMaximumtries() - fcnt));
    }
}

void PlayForm::updateStatusBarQuizno() {
    if (lblQuizno) {
        lblQuizno->setText(QString().sprintf("%d/%d个单词", pti + 1, challenge.getQzlist().size()));
    }
}
