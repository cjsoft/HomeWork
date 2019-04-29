
#pragma once


#ifndef USER_H
#define USER_H
#define PLAYER 0
#define DESIGNER 1
#include "auth.h"
#include <QString>
#include <QDebug>
#include <QtCore>
struct UserData {
    QString username;
    QString passwordmd5;
    char usertype;
    QString tag;
    QString name;
    int level;
    int exp;
    UserData() {}
    UserData(const char username[], const char passwordmd5[], const char usertype,
            const char tag[] = "", const char name[] = "", int level = 0, int exp = 0) :
    username(username), passwordmd5(passwordmd5), usertype(usertype),
    tag(tag), name(name), level(level), exp(exp){
        qDebug() << name;
    }
};

class User
{
private:
    QString username;
    QString uuid;
    QString passwordmd5;
    QString tag;
    QString name;
    int level;
    int exp;
    char type;
    bool online;
public:
    void setOnline(bool online);

public:
    void setUsername(const QString &username);

    void setType(char type);

    const QString &getUsername() const;

    void setUuid(const QString &uuid);

    int getLevel() const;

    void setLevel(int level);

    int getExp() const;

    void setExp(int exp);

    QJsonObject toJsonObject() const;


    const QString &getName() const;

    void setName(const QString &name);

    void setTag(const QString &tag);

    const QString &getTag() const;

    const QString &getUuid() const;
    const QString &getPasswordmd5() const;
    const char &getType() const;

    bool isOnline() const;
    static User *fromJsonObject(const QJsonObject &data);
    User();
    User(UserData ud);

    static bool cmpByExp(User const *a, User const *b);
    static bool cmpByLevel(User const *a, User const *b);


};

class Player : public User {
private:
    int puzzlepassed;
public:
    int getPuzzlepassed() const;

    void setPuzzlepassed(int puzzlepassed);

    Player();
    Player(UserData ud);
    Player(const QJsonObject &obj);
    static bool cmpByPuzzlepassed(Player const *a, Player const *b);

};

class Designer : public User {
public:
    Designer();
    Designer(UserData ud);
    Designer(const QJsonObject &obj);
    void addWord(QString wd);
};



#endif // USER_H
