#include "auth.h"
#include <QCryptographicHash>
#include "common.h"
#include "macrodef.h"
#include <QUuid>
#include <QFileInfo>
#include <QDebug>
#define LOADPARRAM tmp.username, tmp.passwordmd5, tmp.usertype, tmp.tag, tmp.name, tmp.level, tmp.exp
Auth::Auth() {
    salt = "19260817";
    loadDataBase(DBPATH);
}
Auth::Auth(QString slt) : salt(slt) {
    loadDataBase(DBPATH);
}

bool Auth::loadDataBase(QString dbpath) {
    FILE *f;
    try {
        QFileInfo fi(dbpath);
        if (!fi.isFile()) return true;
        mpUserName2User.clear();
        f = fopen(dbpath.toStdString().c_str(), "rb");
        int Usercnt;
        readObj(f, Usercnt);
        RawUserData tmp;
        for (int i = 0; i < Usercnt; ++i) {
            readObj(f, tmp);
            if (tmp.usertype == DESIGNER) {
                Designer *p = new Designer(UserData(LOADPARRAM));
                mpUserName2User.insert(QString(tmp.username), p);
            } else {
                Player *p = new Player(UserData(LOADPARRAM));
                p->setPuzzlepassed(tmp.puzzlepassed);
                mpUserName2User.insert(QString(tmp.username), p);
            }
        }


        fclose(f);
        f = NULL;

    } catch (...) {
        fclose(f);
        f = NULL;
        return false;
    }
    if (f) fclose(f);
    return true;
}
bool Auth::saveDataBase(QString dbpath) {
    FILE *f;
    RawUserData *rud;
    try {
        f = fopen(dbpath.toStdString().c_str(), "w+b");
        int n = mpUserName2User.size();
        qDebug() << "sdfsd" << n;
        writeObj(f, n);
        rud = new RawUserData[n];
        memset(rud, 0, sizeof(RawUserData) * n);
        int cnt = 0;
        for (auto i : mpUserName2User) {
            std::string tmp = i->getUserName().toStdString();
            memcpy(rud[cnt].username, tmp.c_str(), tmp.length());
            tmp = i->getPasswordmd5().toStdString();
            memcpy(rud[cnt].passwordmd5, tmp.c_str(), tmp.length());
            rud[cnt].usertype = i->getType();
            tmp = i->getTag().toStdString();
            qDebug() << i->getTag();
            memcpy(rud[cnt].tag, tmp.c_str(), tmp.length());
            qDebug() << rud[cnt].tag;
            tmp = i->getName().toStdString();
            memcpy(rud[cnt].name, tmp.c_str(), tmp.length());
            rud[cnt].level = i->getLevel();
            rud[cnt].exp = i->getExp();
            rud[cnt].puzzlepassed = 0;
            if (i->getType() == PLAYER) {
                rud[cnt].puzzlepassed = reinterpret_cast<Player*>(i)->getPuzzlepassed();
            }
            cnt++;
        }
        writeObjArray(f, rud, n);
        fclose(f);
        f = NULL;
        delete[] rud;
        rud = NULL;
    } catch (...) {
        if (f) fclose(f);
        f = NULL;
        if (rud) delete[] rud;
        rud = NULL;
        return false;
    }
    if (f) fclose(f);
    if (rud) delete[] rud;
    return true;
}
int Auth::reg(QString username, QString password, char type) {
    if (username.length() < MINUSERNAMELENGTH || password < MINPASSWORDLENGTH) return BADPARRAM;
    if (mpUserName2User.empty() || mpUserName2User.find(username) == mpUserName2User.constEnd()) {
        mpUserName2User.insert(username, new User(UserData(username.toStdString().c_str(), genmd5(username, password).toStdString().c_str(), type)));
        return SUCCESS;
    } else {
        return ALREADYREG;
    }
}

QString Auth::login(QString username, QString password) {
    QMap<QString, User*>::iterator itr = mpUserName2User.find(username);
    qDebug()<<(itr == mpUserName2User.constEnd());
    if (itr == mpUserName2User.constEnd() || genmd5(username, password) != itr.value()->getPasswordmd5()) {
        return "";
    }
    QMap<QString, QString>::iterator qi = mpUserName2Uuid.find(username);
    if (qi != mpUserName2Uuid.constEnd()) return qi.value();
    QString tmpUuid;
    do {
        tmpUuid = QUuid::createUuid().toString();
    } while (mpUuid2UserName.find(tmpUuid) != mpUuid2UserName.constEnd());
    itr.value()->setUuid(tmpUuid);
    mpUuid2UserName.insert(tmpUuid, username);
    mpUserName2Uuid.insert(username, tmpUuid);
    return tmpUuid;
}

QString Auth::genmd5(const QString &username, const QString &password) {
    qDebug() << QString(QCryptographicHash::hash((username + salt + password).toLocal8Bit(), QCryptographicHash::Md5).toHex());
    return QString(QCryptographicHash::hash((username + salt + password).toLocal8Bit(), QCryptographicHash::Md5).toHex());
}

User *Auth::getUser(QString uuid) {
    return getUserByUuid(uuid);
}

int Auth::setTag(QString uuid, const QString &tag) {
    auto i = getUserByUuid(uuid);
    if (i) {
        i->setTag(tag);
        return SUCCESS;
    } else {
        return BADUUID;
    }
}

Auth::~Auth() {
    saveDataBase(DBPATH);
}

User *Auth::getUserByUuid(QString uuid) {
    auto itr = mpUuid2UserName.find(uuid);
    if (itr == mpUuid2UserName.constEnd()) return nullptr;
    auto itt = mpUserName2User.find(itr.value());
    if (itt == mpUserName2User.constEnd()) return nullptr;
    return itt.value();
}

int Auth::setName(QString uuid, const QString &name) {
    auto i = getUserByUuid(uuid);
    if (i) {
        i->setName(name);
        return SUCCESS;
    }  else {
        return  BADUUID;
    }
}
