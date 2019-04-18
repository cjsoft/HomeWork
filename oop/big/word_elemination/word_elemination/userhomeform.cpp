#include "userhomeform.h"
#include "initialform.h"
#include "ui_userhomeform.h"
#include "common.h"
#include <QDebug>
class InitialForm;
extern InitialForm *pInitialForm;
UserHomeForm::UserHomeForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserHomeForm)
{
    ui->setupUi(this);
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
    QString tmp = InputBox("请输入您的姓名，不超过32个字节", "输入");
    if (tmp.toStdString().length() > 128) {
        MessageBox("姓名过长！", "提示", QMessageBox::Ok, QMessageBox::Ok);
    }
    lcc.setName(tmp);
    lcc.fetchInfo();
    updateDisplay();
//    ui->lineEdit->setText(lcc.getCurrentUser()->getUserName());
}

void UserHomeForm::updateDisplay() {
    lcc.fetchInfo();
    ui->txtUserName->setText(lcc.getCurrentUser()->getUserName());
    ui->txtType->setText((lcc.getCurrentUser()->getType() == PLAYER) ? "Player" : "Designer");
    if (lcc.getCurrentUser()->getType() == PLAYER) {
        txtName = ui->txtPName;
        txtTag = ui->txtPTag;
        txtLevel = ui->txtPLevel;
        txtExp = ui->txtPExp;
        Player const *tmp = reinterpret_cast<Player const*>(lcc.getCurrentUser());
        ui->txtPPuzzlePassed->setText(QString().setNum(tmp->getPuzzlepassed()));
    } else {
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
    QString tmp = InputBox("请输入新的个性签名，不超过128个字节", "输入");
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
