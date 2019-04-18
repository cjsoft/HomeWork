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
private:
    void updateDisplay();

public:
    explicit UserHomeForm(QWidget *parent = nullptr);
    ~UserHomeForm();

private:
    Ui::UserHomeForm *ui;
    QLineEdit *txtTag, *txtName, *txtLevel, *txtExp;
private slots:
    void on_btnEditName_clicked();
    void on_btnEditTag_clicked();
    void on_btnLogout_clicked();
};

#endif // USERHOMEFORM_H
