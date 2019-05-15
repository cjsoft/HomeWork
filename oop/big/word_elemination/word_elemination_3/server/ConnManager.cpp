//
// Created by egwcy on 2019/5/9.
//

#include "ConnManager.h"
#include "auth.h"
#include "servercommon.h"

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
    socks.removeOne(conn);
}

void ConnManager::newConn() {
    qDebug() << "New Conection inbound\n";
    socks.push_back(server->nextPendingConnection());
    qDebug() << "connection established: " << socks.back() << "\n";
    connect(socks.back(), &QTcpSocket::readyRead, this, &ConnManager::dataArrived);
    connect(socks.back(), &QTcpSocket::disconnected, this, &ConnManager::connDisconnected);
}

void ConnManager::dataArrived() {
    auto conn = qobject_cast<QTcpSocket*>(sender());
    QString str = conn->readAll();
    qDebug() << "Request from " << conn << "\n";
    qDebug() << str << "\n";
    conn->write(scc.executeQuery(str, conn).toUtf8());
    qDebug() << "Sending reply" << "\n";
}
