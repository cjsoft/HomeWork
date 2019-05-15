

#pragma once

#ifndef LOCALCONNECT_H
#define LOCALCONNECT_H
#define RTNERROR -2
#define CODEERROR -1
#define INFORM 2
#define CONNECTPARAM connaddr, 23333
#include <QtCore>
#include <QString>
#include <QStringList>
#include <QtNetwork>
#include <QThread>
#include <QQueue>
#include "../utils/user.h"
#include "../utils/challenge.h"
class Challenge;
//class DataHandler : public QThread {
//public:
//    QTcpSocket *conn;
//    QQueue<QString> *replyQ;
//    QSemaphore *sem;
//    DataHandler() : QThread() {
//
//    }
//
//    DataHandler(QSemaphore *sm, QQueue<QString> *rq) : QThread() {
//        sem = sm;
//        replyQ = rq;
//        conn = new QTcpSocket;
//        connect(conn, &QTcpSocket::readyRead, this, &DataHandler::dataArrived);
//    }
//
//    void run() {
////        QThread::run();
//    }
//
//public slots:
//    void send(QString data) {
//        if (conn->state() == QTcpSocket::UnconnectedState) {
//            conn->connectToHost(CONNECTPARAM);
//            conn->waitForConnected(1000);
//        }
//    };
//    void dataArrived() {
//        auto x = QString::fromUtf8(conn->readAll());
//        qDebug() << x;
//        QJsonObject data;
//        if (parseRtn(x, data) == INFORM) {
//            auto payload = data.value("payload").toObject();
//            if (payload.value("msg").toString() == "logout") {
//                forcedToLogout();
//            }
//        } else {
//            qDebug() << "enqueing";
//            dataQ.enqueue(x);
//        }
//    }
//};

class LocalConnect : public QObject {
private:
    //Auth ATH;
    QTcpSocket *conn;
//    DataHandler *dth;
//    QSemaphore sem;
    QQueue<QString> dataQ;
    User *CurrentUser;
    QVector<Player> PlayerList;
    QVector<Designer> DesignerList;
    QString uuid;
    QStringList wordlist;
    QString connaddr;
    char type;
public:
    void setConnaddr(const QString &connaddr);
    LocalConnect();
    QString login(QString username, QString password);
    void setUuid(QString Uuid);
    int reg(QString username, QString password, char type);
    int logout();
    QString getUuid();
    QJsonDocument constructQuery(QString method, QJsonObject data);
    QString doQuery(QString method, QJsonObject data);

    const QVector<Player> &getPlayerList() const;

    const QVector<Designer> &getDesignerList() const;

    User const *getCurrentUser() const;
    int parseRtn(QString str, QJsonObject &data);
    int setTag(const QString &tag);
    int setName(const QString &name);
    int setThing(const QString &key, const QString &dta);
    int setThing(const QString &key, const int &dta);
    int addWord(const QString &word);
    int finishChallenge(int difficulty, int score);
    int fetchUserList();
    void connectToHost(const QString &hostName, quint16 port,
            QTcpSocket::OpenMode mode = QTcpSocket::ReadWrite,
            QTcpSocket::NetworkLayerProtocol protocol = QTcpSocket::AnyIPProtocol);
    QStringList const &fetchWordlist();
    void forcedToLogout();
    Challenge constructChallenge(int difficulty = 0);
    User const *fetchInfo();
    ~LocalConnect();

private slots:
    void dataArrived();
    void connDisconnected();

signals:
    void sendData(QString data);
};


#endif // LOCALCONNECT_H
