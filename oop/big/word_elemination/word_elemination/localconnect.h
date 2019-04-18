

#pragma once

#ifndef LOCALCONNECT_H
#define LOCALCONNECT_H
#define RTNERROR -2
#define CODEERROR -1

#include <QtCore>
#include <QString>
#include "auth.h"
#include "serverconnect.h"
#include "user.h"
class LocalConnect
{
private:
    //Auth ATH;
    User *CurrentUser;
public:
    User const *getCurrentUser() const;

private:
    ServerConnect svc;
    QString uuid;
    char type;
public:
    LocalConnect();
    QString login(QString username, QString password);
    void setUuid(QString Uuid);
    int reg(QString username, QString password, char type);
    QString getUuid();
    QJsonDocument constructQuery(QString method, QJsonObject data);
    QString doQuery(QString method, QJsonObject data);
    int parseRtn(QString str, QJsonObject &data);
    int setTag(const QString &tag);
    int setName(const QString &name);
    int setThing(const QString &key, const QString &dta);
    int setThing(const QString &key, const int &dta);
    User const *fetchInfo();
    ~LocalConnect();
};
#endif // LOCALCONNECT_H
