#pragma once


#include <QDialog>
#include <QShowEvent>

#ifndef INITIALFORM_H
#define INITIALFORM_H

namespace Ui {
class InitialForm;
}

class InitialForm : public QDialog
{
    Q_OBJECT

public:
    explicit InitialForm(QWidget *parent = nullptr);
    void show();
    ~InitialForm();

private slots:
    void keyPressEvent(QKeyEvent *event);


    void on_btnLogin_clicked();

    void on_btnRegister_clicked();

    void on_btnReturnToLogin_clicked();

    void on_btnConfirmRegister_clicked();

private:
    Ui::InitialForm *ui;
    void setWH(int w, int h);
    void showEvent(QShowEvent *event) override;
};

#endif // INITIALFORM_H
