#include "addwordform.h"
#include "ui_addwordform.h"
#include <QDebug>
#include <QRegExp>
#include <QValidator>
#include "userhomeform.h"
#include "../clientcommon.h"

AddWordForm::AddWordForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWordForm)
{
    ui->setupUi(this);
    ui->inputWord->setValidator(new QRegExpValidator(QRegExp("[0-9a-zA-Z\\.\\- \'&]+"), ui->inputWord));
    ui->menuBar->addAction(QString("返回上一级"), this, SLOT(MenuPressed()));
}

AddWordForm::~AddWordForm()
{
    delete ui;
}

void AddWordForm::MenuPressed() {
    pUserHomeForm->show();
    this->close();
}

void AddWordForm::on_inputWord_returnPressed()
{
    if (ui->inputWord->text().trimmed().length() == 0) {
        MessageBox("输入不能为空！", "提示", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    QByteArray tmp = ui->inputWord->text().toLatin1();
//    for (auto i : tmp) {
//        if (!isalpha(i)) {
//            MessageBox("有不合法字符，请检查输入！", "提示", QMessageBox::Ok, QMessageBox::Ok);
//            return;
//        }
//    }
    int rtn = lcc.addWord(ui->inputWord->text());
    if (rtn == 0) {
        MessageBox("单词添加成功！", "提示", QMessageBox::Ok, QMessageBox::Ok);
        ui->inputWord->setText("");
        ui->inputWord->setFocus();
    } else if (rtn == 2) {
        MessageBox("词库中已有该词！", "提示", QMessageBox::Ok, QMessageBox::Ok);
    } else {
        MessageBox("单词添加失败！", "提示", QMessageBox::Ok, QMessageBox::Ok);
    }

}
