#ifndef ADDWORDFORM_H
#define ADDWORDFORM_H

#include <QMainWindow>
#include <QEvent>
namespace Ui {
class AddWordForm;
}

class AddWordForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWordForm(QWidget *parent = nullptr);
    ~AddWordForm();

private:
    Ui::AddWordForm *ui;
private slots:
    void MenuPressed();
    void on_inputWord_returnPressed();
};

#endif // ADDWORDFORM_H
