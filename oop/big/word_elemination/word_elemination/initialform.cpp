#include "initialform.h"
#include "ui_initialform.h"
#include <QKeyEvent>
InitialForm::InitialForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitialForm)
{
    ui->setupUi(this);
    ui->gb->setFocusPolicy(Qt::StrongFocus);
    ui->btnLogin->setFocus();
    ui->inputUserName->setFocus();
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

        break;

    default:

        break;

    }

}

void InitialForm::on_btnLogin_clicked()
{

}
