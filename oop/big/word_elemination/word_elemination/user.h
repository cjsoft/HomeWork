
#pragma once


#ifndef USER_H
#define USER_H
#define PLAYER 0
#define DESIGNER 1
#include "auth.h"
#include <QString>
#include <QDebug>
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
public:
    void setUsername(const QString &username);

    void setType(char type);

private:
    QString uuid;
public:
    const QString &getUsername() const;

public:
    void setUuid(const QString &uuid);

private:
    QString passwordmd5;
    QString tag;
    QString name;
    int level;
    int exp;
public:
    int getLevel() const;

    void setLevel(int level);

    int getExp() const;

    void setExp(int exp);

public:
    const QString &getName() const;

    void setName(const QString &name);

public:
    void setTag(const QString &tag);

public:
    const QString &getTag() const;

private:
    char type;
    bool online;
public:
    const QString &getUserName() const;
    const QString &getUuid() const;
    const QString &getPasswordmd5() const;
    const char &getType() const;

    bool isOnline() const;
    User();
    User(UserData ud);

};

class Player : public User {
private:
    int puzzlepassed;
public:
    int getPuzzlepassed() const;

    void setPuzzlepassed(int puzzlepassed);

public:


public:
    Player();
    Player(UserData ud);


};

class Designer : public User {
public:
    Designer();
    Designer(UserData ud);
    void addWord(QString wd);
};



#endif // USER_H
