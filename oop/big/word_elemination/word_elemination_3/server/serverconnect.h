#pragma once

#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H
#include "auth.h"
#include "ConnManager.h"
class Auth;
extern Auth ATH;
class ServerConnect {
private:
    QJsonArray QStringList2QJson(QStringList const &lst);
public:
    ServerConnect();
    QString executeQuery(const QString &query, QTcpSocket *conn);
    void inform(const QString &msg, QTcpSocket *conn);
};

#endif // SERVERCONNECT_H
