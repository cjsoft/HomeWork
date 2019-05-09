#include "listusersform.h"
#include "ui_listusersform.h"
#include "../clientcommon.h"
#include <QTableWidgetItem>
#include <QTableWidgetItem>
#define DEDIT(lst, i, j) do {\
ui->tblD->setItem((j), 0, new QTableWidgetItem((lst).at((i)).isOnline() ? awesome->icon("checkcircleo", ColorGreen) : awesome->icon("timescircleo", ColorRed), (lst).at((i)).getUsername()));\
ui->tblD->setItem((j), 1, new QTableWidgetItem((lst).at((i)).getName()));\
ui->tblD->setItem((j), 2, new QTableWidgetItem((lst).at((i)).getTag()));\
ui->tblD->setItem((j), 3, dynamic_cast<QTableWidgetItem*>(new TableItemInt((lst).at((i)).getExp())));\
ui->tblD->setItem((j), 4, dynamic_cast<QTableWidgetItem*>(new TableItemInt((lst).at((i)).getLevel())));\
} while (0)
#define PEDIT(lst, i, j) do {\
ui->tblP->setItem((j), 0, new QTableWidgetItem((lst).at((i)).isOnline() ? awesome->icon("checkcircleo", ColorGreen) : awesome->icon("timescircleo", ColorRed), (lst).at((i)).getUsername()));\
ui->tblP->setItem((j), 1, new QTableWidgetItem((lst).at((i)).getName()));\
ui->tblP->setItem((j), 2, new QTableWidgetItem((lst).at((i)).getTag()));\
ui->tblP->setItem((j), 3, dynamic_cast<QTableWidgetItem*>(new TableItemInt((lst).at((i)).getPuzzlepassed())));\
ui->tblP->setItem((j), 4, dynamic_cast<QTableWidgetItem*>(new TableItemInt((lst).at((i)).getExp())));\
ui->tblP->setItem((j), 5, dynamic_cast<QTableWidgetItem*>(new TableItemInt((lst).at((i)).getLevel())));\
} while (0)
extern QtAwesome* awesome;
extern QVariantMap ColorRed;
extern QVariantMap ColorGreen;
class QTableWidgetItem;
class TableItemInt : public QTableWidgetItem {
private:
    int value;
public:

    int getValue() const {
        return value;
    }
    TableItemInt(int val) : QTableWidgetItem(QString().setNum(val)) {
        value = val;
    }
    virtual bool operator<(const QTableWidgetItem &b) const override {
        return value < dynamic_cast<TableItemInt const&>(b).value;
    }
};
ListUsersForm::ListUsersForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListUsersForm)
{
    ui->setupUi(this);
//    mnu = new QMenu;
    ui->menubar->addAction("刷新", this, SLOT(refresh()));
//    mnu->addAction("搜索", this, SLOT(search()));
//    ui->menubar->addMenu(mnu);
    QStringList headerP, headerD;
    headerP << "用户名" << "姓名" << "个性签名" << "闯关数" << "经验值" << "等级";
    headerD << "用户名" << "姓名" << "个性签名" << "出题数" << "等级";
    ui->tblD->setHorizontalHeaderLabels(headerD);
    ui->tblP->setHorizontalHeaderLabels(headerP);
    ui->tblD->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblP->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblD->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblP->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblD->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblP->setSelectionMode(QAbstractItemView::SingleSelection);
}

ListUsersForm::~ListUsersForm()
{
    delete ui;
}

void ListUsersForm::updateTableDesigner() {
    ui->tblD->clearContents();
    ui->tblD->setRowCount(lcc.getDesignerList().size());
    auto &lst = lcc.getDesignerList();
    for (int i = 0; i < lst.size(); ++i) {
        DEDIT(lst, i, i);
    }

}

void ListUsersForm::updateTablePlayer() {
    ui->tblP->clearContents();
    ui->tblP->setRowCount(lcc.getPlayerList().size());
    auto &lst = lcc.getPlayerList();
    for (int i = 0; i < lst.size(); ++i) {
        PEDIT(lst, i, i);
    }

}

void ListUsersForm::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
}

void ListUsersForm::refresh() {
    lcc.fetchUserList();
    updateTableDesigner();
    updateTablePlayer();

}

void ListUsersForm::search() {
    lcc.fetchUserList();
    auto &lstP = lcc.getPlayerList();
    auto &lstD = lcc.getDesignerList();

    if (ui->cbo->currentText() == "闯关数" || ui->cbo->currentText() == "经验值") {
    } else if (ui->cbo->currentText() == "出题数") {
    }
    if (ui->cbo->currentText() == "用户名" || ui->cbo->currentText() == "姓名") {
        bool tag = true;
        QString sstr = InputBox("请输入搜索字符串", "输入", "", &tag);
        if (!tag)
            return;
        ui->tblD->setRowCount(0);
        ui->tblP->setRowCount(0);
        bool looptag = true;
        if (ui->cbo->currentText() == "用户名") {
            for (int i = 0; i < lstP.size(); ++i) {
                if (lstP.at(i).getUsername() == sstr) {
                    ui->tblP->setRowCount(1);
                    PEDIT(lstP, i, 0);
                    looptag = false;
                    break;
                }
            }
            if (looptag) {
                for (int i = 0; i < lstD.size(); ++i) {
                    qDebug() << "Sdf";
                    if (lstD.at(i).getUsername() == sstr) {
                        ui->tblD->setRowCount(1);
                        DEDIT(lstD, i, 0);
                        break;
                    }
                }
            }
        } else if (ui->cbo->currentText() == "姓名") {
            QVector<int> store;
            int cnt = 0;
            for (int i = 0; i < lstP.size(); ++i) {
                if (lstP.at(i).getName() == sstr) {
                    store.push_back(i);
                }
            }
            ui->tblP->setRowCount(store.size());
            for (auto i : store) {
                PEDIT(lstP, i, cnt);
                cnt++;
            }
            cnt = 0;
            store.clear();
            for (int i = 0; i < lstD.size(); ++i) {
                if (lstD.at(i).getName() == sstr) {
                    store.push_back(i);
                }
            }
            ui->tblD->setRowCount(store.size());
            for (auto i : store) {
                DEDIT(lstD, i, cnt);
                cnt++;
            }
        }
    } else if (ui->cbo->currentText() == "在线" || ui->cbo->currentText() == "离线") {
        QVector<int> store;
        int cnt = 0;
        if (ui->cbo->currentText() == "在线") {
            for (int i = 0; i < lstP.size(); ++i) {
                bool x = lstP.at(i).isOnline();
                if (x) {
                    store.push_back(i);
                }
            }
            ui->tblP->setRowCount(store.size());
            for (auto i : store) {
                PEDIT(lstP, i, cnt);
                cnt++;
            }
            cnt = 0;
            store.clear();
            for (int i = 0; i < lstD.size(); ++i) {
                bool x = lstD.at(i).isOnline();
                if (x) {
                    store.push_back(i);
                }
            }
            ui->tblD->setRowCount(store.size());
            for (auto i : store) {
                DEDIT(lstD, i, cnt);
                cnt++;
            }
        } else {
            for (int i = 0; i < lstP.size(); ++i) {
                bool x = lstP.at(i).isOnline();
                if (!x) {
                    store.push_back(i);
                }
            }
            ui->tblP->setRowCount(store.size());
            for (auto i : store) {
                PEDIT(lstP, i, cnt);
                cnt++;
            }
            cnt = 0;
            store.clear();
            for (int i = 0; i < lstD.size(); ++i) {
                bool x = lstD.at(i).isOnline();
                if (!x) {
                    store.push_back(i);
                }
            }
            ui->tblD->setRowCount(store.size());
            for (auto i : store) {
                DEDIT(lstD, i, cnt);
                cnt++;
            }
        }
    } else {
        QPair<int, int> rg = RangeBox("请输入搜索范围", "输入", 0, 1000000000);
        if (rg.first > rg.second) return;
        ui->tblD->setRowCount(0);
        ui->tblP->setRowCount(0);
        QVector<int> store;
        if (ui->cbo->currentText() == "闯关数") {
            int cnt = 0;
            for (int i = 0; i < lstP.size(); ++i) {
                int x = lstP.at(i).getPuzzlepassed();
                if (rg.first <= x && x <= rg.second) {
                    store.push_back(i);
                }
            }
            ui->tblP->setRowCount(store.size());
            for (auto i : store) {
                PEDIT(lstP, i, cnt);
                cnt++;
            }
        } else if (ui->cbo->currentText() == "出题数") {
            int cnt = 0;
            store.clear();
            for (int i = 0; i < lstD.size(); ++i) {
                int x = lstD.at(i).getExp();
                if (rg.first <= x && x <= rg.second) {
                    store.push_back(i);
                }
            }
            ui->tblD->setRowCount(store.size());
            for (auto i : store) {
                DEDIT(lstD, i, cnt);
                cnt++;
            }
        } else if (ui->cbo->currentText() == "等级") {
            int cnt = 0;
            for (int i = 0; i < lstP.size(); ++i) {
                int x = lstP.at(i).getLevel();
                if (rg.first <= x && x <= rg.second) {
                    store.push_back(i);
                }
            }
            ui->tblP->setRowCount(store.size());
            for (auto i : store) {
                PEDIT(lstP, i, cnt);
                cnt++;
            }
            cnt = 0;
            store.clear();
            for (int i = 0; i < lstD.size(); ++i) {
                int x = lstD.at(i).getLevel();
                if (rg.first <= x && x <= rg.second) {
                    store.push_back(i);
                }
            }
            ui->tblD->setRowCount(store.size());
            for (auto i : store) {
                DEDIT(lstD, i, cnt);
                cnt++;
            }
        } else if (ui->cbo->currentText() == "经验值") {
            int cnt = 0;
            for (int i = 0; i < lstP.size(); ++i) {
                int x = lstP.at(i).getExp();
                if (rg.first <= x && x <= rg.second) {
                    store.push_back(i);
                }
            }
            ui->tblP->setRowCount(store.size());
            for (auto i : store) {
                PEDIT(lstP, i, cnt);
                cnt++;
            }
        }
    }
}


void ListUsersForm::on_btnSearch_clicked()
{
    emit search();
}

void ListUsersForm::show() {
    QMainWindow::show();
    refresh();
}
