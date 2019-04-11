#ifndef INITIALFORM_H
#define INITIALFORM_H

#include <QDialog>

namespace Ui {
class InitialForm;
}

class InitialForm : public QDialog
{
    Q_OBJECT

public:
    explicit InitialForm(QWidget *parent = nullptr);
    ~InitialForm();

private slots:
    void keyPressEvent(QKeyEvent *event);


    void on_btnLogin_clicked();

private:
    Ui::InitialForm *ui;
};

#endif // INITIALFORM_H
