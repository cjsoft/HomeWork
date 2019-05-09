

#pragma once

#ifndef LOCALCONNECT_H
#define LOCALCONNECT_H
#define RTNERROR -2
#define CODEERROR -1
#define INFORM 2
#define CONNECTPARAM "127.0.0.1", 23333
#include <QtCore>
#include <QString>
#include <QStringList>
#include <QtNetwork>
#include <QThread>
#include <QQueue>
#include "../utils/user.h"
#include "../utils/challenge.h"
class Challenge;
template <class T>
class BQueue : public QQueue<T> {
private:
    QSemaphore sem;
public:
    BQueue() : QQueue<T>() {}
    inline void enqueue(const T &t) {
        QQueue<T>::enqueue(t);
        sem.release(1);
    }
    inline T dequeue() {
        sem.acquire(1);
        return QQueue<T>::dequeue();
    }
    inline T dequeue(int timeout, bool *rtn) {
        *rtn = sem.tryAcquire(1, timeout);
        if (!(*rtn)) return T();
        return QQueue<T>::dequeue();
    }
    inline void clear() {
        sem.acquire(sem.available());
        this->clear();
    }
};

class LocalConnect : public QObject {
private:
    //Auth ATH;
    QTcpSocket *conn;
    BQueue<QString> dataQ;
    User *CurrentUser;
    QVector<Player> PlayerList;
    QVector<Designer> DesignerList;
    QString uuid;
    QStringList wordlist;
    char type;
public:
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
};


#endif // LOCALCONNECT_H
