#pragma once
#ifndef LISTUSERSFORM_H
#define LISTUSERSFORM_H

#include <QMainWindow>
#include <QShowEvent>
#include <QMenu>
namespace Ui {
class ListUsersForm;
}

class ListUsersForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListUsersForm(QWidget *parent = nullptr);
    void show();
    ~ListUsersForm();

private:
    Ui::ListUsersForm *ui;
//    QMenu *mnu;
    void updateTableDesigner();
    void updateTablePlayer();
    void showEvent(QShowEvent *event) override;
private slots:
    void refresh();
    void search();

    void on_btnSearch_clicked();
};

#endif // LISTUSERSFORM_H
