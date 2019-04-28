#include "userhomeform.h"
#include "initialform.h"
#include "ui_userhomeform.h"
#include "addwordform.h"
#include "playform.h"
#include "listusersform.h"
#include "../common.h"
#include <QDebug>

UserHomeForm::UserHomeForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserHomeForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->cnterD->setGeometry(ui->cnterP->x(), ui->cnterP->y(), ui->cnterD->width(), ui->cnterD->height());
    txtName = ui->txtPName;
    txtTag = ui->txtPTag;
    txtLevel = ui->txtPLevel;
    txtExp = ui->txtPExp;
    lcc.fetchInfo();
    updateDisplay();
}

UserHomeForm::~UserHomeForm()
{
    delete ui;
}

void UserHomeForm::on_btnEditName_clicked() {
    bool tag = true;
    QString tmp = InputBox("请输入您的姓名，不超过32个字节", "输入", lcc.getCurrentUser()->getName(), &tag);
    if (!tag) return;
    if (tmp.toStdString().length() > 128) {
        MessageBox("姓名过长！", "提示", QMessageBox::Ok, QMessageBox::Ok);
    }
    lcc.setName(tmp);
    lcc.fetchInfo();
    updateDisplay();
//    ui->lineEdit->setText(lcc.getCurrentUser()->getUsername());
}

void UserHomeForm::updateDisplay() {
    lcc.fetchInfo();
    ui->txtUserName->setText(lcc.getCurrentUser()->getUsername());
    ui->txtType->setText((lcc.getCurrentUser()->getType() == PLAYER) ? "Player" : "Designer");
    if (lcc.getCurrentUser()->getType() == PLAYER) {
        ui->btnAddWord->hide();
        ui->btnPlay->show();
        ui->cnterD->hide();
        ui->cnterP->show();
        txtName = ui->txtPName;
        txtTag = ui->txtPTag;
        txtLevel = ui->txtPLevel;
        txtExp = ui->txtPExp;
        Player const *tmp = reinterpret_cast<Player const*>(lcc.getCurrentUser());
        ui->txtPPuzzlePassed->setText(QString().setNum(tmp->getPuzzlepassed()));
    } else {
        ui->btnAddWord->show();
        ui->btnPlay->hide();
        ui->cnterP->hide();
        ui->cnterD->show();
        txtName = ui->txtDName;
        txtTag = ui->txtDTag;
        txtLevel = ui->txtDLevel;
        txtExp = ui->txtDPuzzleMade;
        Designer const *tmp = reinterpret_cast<Designer const*>(lcc.getCurrentUser());
    }
    qDebug() << (lcc.getCurrentUser()->getTag());
    txtTag->setText(lcc.getCurrentUser()->getTag());
    txtName->setText(lcc.getCurrentUser()->getName());
    txtLevel->setText(QString().setNum(lcc.getCurrentUser()->getLevel()));
    txtExp->setText(QString().setNum(lcc.getCurrentUser()->getExp()));
}

void UserHomeForm::on_btnEditTag_clicked() {
    bool tag = true;
    QString tmp = InputBox("请输入新的个性签名，不超过128个字节", "输入", lcc.getCurrentUser()->getTag(), &tag);
    if (!tag) return;
    if (tmp.toStdString().length() > 128) {
        MessageBox("个性签名过长！", "提示", QMessageBox::Ok, QMessageBox::Ok);
    }
    lcc.setTag(tmp);
    lcc.fetchInfo();
    updateDisplay();
}

void UserHomeForm::on_btnLogout_clicked()
{
    lcc.setUuid("");
    pInitialForm->show();
    this->close();
}

void UserHomeForm::on_btnAddWord_clicked() {
    if (pAddWordForm == nullptr)
        pAddWordForm = new AddWordForm;
    pAddWordForm->show();
}

void UserHomeForm::on_btnPlay_clicked() {
    if (pPlayForm == nullptr)
        pPlayForm = new PlayForm;
    pPlayForm->show();
}

void UserHomeForm::on_btnAll_clicked() {
    if (pListUsersForm == nullptr)
        pListUsersForm = new ListUsersForm;
    pListUsersForm->show();
}
