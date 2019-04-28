#include "initialform.h"
#include "ui_initialform.h"
#include "../common.h"
#include <QKeyEvent>
#include <QApplication>
#include <QDesktopWidget>
#include "../localconnect.h"
#include "../serverconnect.h"
#include <QtCore>
#include "userhomeform.h"

InitialForm::InitialForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitialForm)
{
    ui->setupUi(this);

    setWindowFlags(this->windowFlags()&~Qt::WindowContextHelpButtonHint);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    ui->gb->setFocusPolicy(Qt::StrongFocus);
    ui->gb_2->setFocusPolicy(Qt::StrongFocus);
    ui->btnLogin->setFocus();
    ui->inputUserName->setFocus();
    ui->gb_2->hide();
    setTabOrder(ui->inputUserName, ui->inputPassword);
    setTabOrder(ui->inputPassword, ui->btnLogin);
    setTabOrder(ui->btnLogin, ui->btnRegister);
    setTabOrder(ui->btnRegister, ui->inputUserName_2);
    setTabOrder(ui->inputUserName_2, ui->inputPassword_2);
    setTabOrder(ui->inputPassword_2, ui->inputPassword_3);
    setTabOrder(ui->inputPassword_3, ui->btnConfirmRegister);
    setTabOrder(ui->btnConfirmRegister, ui->rPlayer);
    setTabOrder(ui->rPlayer, ui->rDesigner);
    setTabOrder(ui->rDesigner, ui->btnConfirmRegister);
    setTabOrder(ui->btnConfirmRegister, ui->btnReturnToLogin);

    ui->gb_2->setGeometry(ui->gb->x(), ui->gb->y(), ui->gb_2->width(), ui->gb_2->height());

    setWH(270, 140);
//    ServerConnect tmp;

}
void InitialForm::setWH(int w, int h) {

    this->setFixedSize(w, h);
    this->setGeometry((qApp->desktop()->availableGeometry().width() - w) / 2 + qApp->desktop()->availableGeometry().x(),
                      (qApp->desktop()->availableGeometry().height() - h) / 2 + qApp->desktop()->availableGeometry().y()
           , w, h);
}
InitialForm::~InitialForm()
{
    delete ui;
}

void InitialForm::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {

    case Qt::Key_Return:

       if (ui->inputUserName->hasFocus())
           ui->inputPassword->setFocus();
       else if (ui->inputPassword->hasFocus())
           emit ui->btnLogin->clicked();
        else if (ui->inputUserName_2->hasFocus())
           ui->inputPassword_2->setFocus();
       else if (ui->inputPassword_2->hasFocus())
           ui->inputPassword_3->setFocus();
       else if (ui->inputPassword_3->hasFocus())
           emit ui->btnConfirmRegister->clicked();
       else if (ui->rDesigner->hasFocus() || ui->rPlayer->hasFocus())
           emit ui->btnConfirmRegister->clicked();
        break;

    default:

        break;

    }

}

void InitialForm::on_btnLogin_clicked()
{
    lcc.setUuid(lcc.login(ui->inputUserName->text(), ui->inputPassword->text()));
    if (lcc.getUuid().length()) {
        MessageBox("登陆成功！", "提示", QMessageBox::Ok, QMessageBox::Ok);
        ui->inputUserName->setText("");
        ui->inputPassword->setText("");
        if (pUserHomeForm != nullptr)
            delete pUserHomeForm;
        pUserHomeForm = new UserHomeForm;
        pUserHomeForm->show();
        this->close();
    } else {
        MessageBox("登陆失败，可能是错误的用户名或者密码", "提示", QMessageBox::Ok, QMessageBox::Ok);
    }
}

void InitialForm::on_btnRegister_clicked()
{
    ui->gb_2->show();
    ui->gb->hide();
    setWH(270, 190);
    ui->inputUserName_2->setFocus();
}




void InitialForm::on_btnReturnToLogin_clicked()
{
    ui->gb->show();
    ui->gb_2->hide();
    setWH(270, 140);
}

void InitialForm::on_btnConfirmRegister_clicked()
{

    char type;
    if (ui->rPlayer->isChecked())
        type = 0;
    else type = 1;

    if (ui->inputPassword_2->text().compare(ui->inputPassword_3->text()) != 0) {
        MessageBox("两次密码不匹配", "提示", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    int rtn = lcc.reg(ui->inputUserName_2->text(), ui->inputPassword_2->text(), type);
    if (!rtn) {
        MessageBox("注册成功，返回登录", "提示", QMessageBox::Ok, QMessageBox::Ok);
        ui->inputPassword->setText(ui->inputPassword_2->text());
        ui->inputUserName->setText(ui->inputUserName_2->text());
        ui->inputPassword_2->setText("");
        ui->inputPassword_3->setText("");
        ui->inputUserName_2->setText("");
        emit ui->btnReturnToLogin->clicked();
    } else if (rtn == 2) {
        MessageBox("此用户已存在", "提示", QMessageBox::Ok, QMessageBox::Ok);
    } else if (rtn == 1) {
        MessageBox("用户名或密码过短", "提示", QMessageBox::Ok, QMessageBox::Ok);
    }
}

void InitialForm::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);
}

void InitialForm::show() {
    QDialog::show();
    ui->inputUserName->setFocus();
}
