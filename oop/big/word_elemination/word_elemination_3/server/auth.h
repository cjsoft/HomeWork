#pragma once

#ifndef AUTH_H
#define AUTH_H
#include "../utils/user.h"
#include "../utils/challenge.h"
#include <QString>
#include <QMap>
#include <QtNetwork>
#define MINUSERNAMELENGTH 4
#define MINPASSWORDLENGTH 6
#define UDBPATH "word_elem.db"
#define WDBPATH "words.txt"

// Serverside Auth
struct RawUserData {
    char username[33];
    char passwordmd5[33];
    char usertype;
    char tag[129];
    char name[33];
    int level;
    int exp;
    int puzzlepassed;
};

class User;
class Challenge;
class Auth
{
private:
    QMap<QString, User*> mpUserName2User;
    QMap<QString, QString> mpUuid2Username;
    QMap<QString, QString> mpUsername2Uuid;
    QMap<QString, QTcpSocket*> mpUsername2Socket;
    QMap<QTcpSocket*, QString> mpSocket2Username;
    QStringList WordList;
    QString salt;
    User *getUserByUuid(QString uuid);
public:
    Auth();
    Auth(QString slt);
    bool loadDataBase(QString dbpath);
    QString login(QString username, QString password, QTcpSocket *conn);
    int reg(QString username, QString password, char type);
    QString genmd5(const QString &username, const QString &password);
    bool saveDataBase(QString dbpath);
    bool loadWordList(QString dbpath);
    bool saveWordList(QString dbpath);
    User *getUser(QString uuid);
    QVector<User*> getUserList();
    int setTag(QString uuid, const QString &tag);
    int setName(QString uuid, const QString &name);
    int addWord(QString uuid, QString word);
    int finishChallenge(QString uuid, int difficulty, int score);
    int calcLevelP(int exp);
    int calcLevelD(int exp);
    void delConn(QTcpSocket *conn);
    void delConn(const QString &username);
    Challenge constructChallenge(int difficulty);
    QStringList const &getWordList();
    void logout(QString uuid);
    ~Auth();
};



#endif // AUTH_H
