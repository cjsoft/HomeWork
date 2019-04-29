

#pragma once

#ifndef LOCALCONNECT_H
#define LOCALCONNECT_H
#define RTNERROR -2
#define CODEERROR -1

#include <QtCore>
#include <QString>
#include <QStringList>
#include "auth.h"
#include "serverconnect.h"
#include "user.h"
#include "challenge.h"
class Challenge;
class LocalConnect
{
private:
    //Auth ATH;
    User *CurrentUser;
    QVector<Player> PlayerList;
    QVector<Designer> DesignerList;
public:
    const QVector<Player> &getPlayerList() const;

    const QVector<Designer> &getDesignerList() const;

public:
    User const *getCurrentUser() const;

private:
    ServerConnect svc;
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
    int parseRtn(QString str, QJsonObject &data);
    int setTag(const QString &tag);
    int setName(const QString &name);
    int setThing(const QString &key, const QString &dta);
    int setThing(const QString &key, const int &dta);
    int addWord(const QString &word);
    int finishChallenge(int difficulty, int score);
    int fetchUserList();

    QStringList const &fetchWordlist();

    Challenge constructChallenge(int difficulty = 0);
    User const *fetchInfo();
    ~LocalConnect();
};
#endif // LOCALCONNECT_H
