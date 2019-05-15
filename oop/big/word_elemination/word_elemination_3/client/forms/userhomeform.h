#pragma once
#ifndef USERHOMEFORM_H
#define USERHOMEFORM_H

#include <QMainWindow>
#include <QLineEdit>
namespace Ui {
class UserHomeForm;
}

class UserHomeForm : public QMainWindow
{
    Q_OBJECT

public:
    void updateDisplay();
    explicit UserHomeForm(QWidget *parent = nullptr);
    ~UserHomeForm();
    void show();
private:
    Ui::UserHomeForm *ui;
    QLineEdit *txtTag, *txtName, *txtLevel, *txtExp;
private slots:
    void on_btnEditName_clicked();
    void on_btnEditTag_clicked();
    void on_btnLogout_clicked();
    void on_btnAddWord_clicked();
    void on_btnPlay_clicked();
    void on_btnAll_clicked();
};

#endif // USERHOMEFORM_H
