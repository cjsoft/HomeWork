//
// Created by egwcy on 2019/5/9.
//

#include "ConnManager.h"
#include "auth.h"

bool ConnManager::listen(const QHostAddress &address, quint16 port) {
    if (server) {
        return server->listen(address, port);
    }
    return false;
}

ConnManager::ConnManager() {
    server = new QTcpServer;
    connect(server, &QTcpServer::newConnection, this, &ConnManager::newConn);
}

ConnManager::~ConnManager() {
    for (auto i : socks) {
        if (i->state() == QTcpSocket::ConnectedState) {
            i->disconnectFromHost();
        }
    }
}

void ConnManager::connDisconnected() {
    auto conn = qobject_cast<QTcpSocket*>(sender());
    lockSocks.lock();
    socks.removeOne(conn);
    lockSocks.unlock();
}

void ConnManager::newConn() {
    qDebug() << "new conn";
    lockSocks.lock();
    socks.push_back(server->nextPendingConnection());
    connect(socks.back(), &QTcpSocket::readyRead, this, &ConnManager::dataArrived);
    connect(socks.back(), &QTcpSocket::disconnected, this, &ConnManager::connDisconnected);
    lockSocks.unlock();
}

void ConnManager::dataArrived() {
    auto conn = qobject_cast<QTcpSocket*>(sender());
    QString str = conn->readAll();
    conn->write(scc.executeQuery(str, nullptr).toUtf8());
    qDebug() << str;
}
