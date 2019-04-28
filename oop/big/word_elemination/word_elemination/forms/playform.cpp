#include "playform.h"
#include "ui_playform.h"
#include "../common.h"
#include "userhomeform.h"
class UserHomeForm;
extern UserHomeForm *pUserHomeForm;
PlayForm::PlayForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayForm)
{
    playing = false;
    pti = -1;
    ui->setupUi(this);
    lblstatus = new QLabel;
    ui->statusbar->addWidget(lblstatus);
    color[1].setColor(QPalette::Text, Qt::red);
    color[0].setColor(QPalette::Text, Qt::black);
    clr[1] = "QLineEdit {color:red}";
    clr[0] = "QLineEdit {color:black}";
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
    pti = -1;
    playing = true;
    ui->inputWord->setText("");
    nextQuiz();
}

void PlayForm::nextQuiz() {
    if (pti + 1 >= challenge.getQzlist().size()) {
        completeChallenge();
    } else {
        auto quiz = challenge.getQzlist().at(++pti);
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
    lcc.finishChallenge(challenge.getDifficulty(), 10);
    updateStatusBar();
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
            changeColor();
            tmrBlink.start(150);
            tmrDisable.start(900);
        }
    }
}

void PlayForm::formShown() {
    updateStatusBar();
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

void PlayForm::updateStatusBar() {
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
