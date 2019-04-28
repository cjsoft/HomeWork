#pragma once

#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H
#include "auth.h"

class ServerConnect
{
private:
    Auth ATH;
    QJsonObject User2QJson(User const *usr);
    QJsonArray QStringList2QJson(QStringList const &lst);
public:
    ServerConnect();
    QString executeQuery(QString query);
};

#endif // SERVERCONNECT_H
