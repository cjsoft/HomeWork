//
// Created by egwcy on 2019/5/9.
//
#pragma once
#ifndef WORD_ELEMINATION_3_CONNMANAGER_H
#define WORD_ELEMINATION_3_CONNMANAGER_H

#include <QThread>
#include <QtNetwork>
#include <QMap>
#include "serverconnect.h"
class ServerConnect;
extern ServerConnect scc;
class ConnManager : public QObject {
private:
    QVector<QTcpSocket*> socks;
    QMutex lockSocks;
    QTcpServer *server;
public:
    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);
    ConnManager();
    ~ConnManager();
private slots:
    void connDisconnected();
    void newConn();
    void dataArrived();
};


#endif //WORD_ELEMINATION_3_CONNMANAGER_H
