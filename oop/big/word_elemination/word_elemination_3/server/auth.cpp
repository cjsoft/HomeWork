#include "auth.h"
#include <QCryptographicHash>
#include "servercommon.h"
#include "../utils/macrodef.h"
#include <cmath>
#include <QUuid>
#include <QFileInfo>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include "serverconnect.h"
#include "servercommon.h"

#define LOADPARRAM tmp.username, tmp.passwordmd5, tmp.usertype, tmp.tag, tmp.name, tmp.level, tmp.exp
class ServerConnect;
extern ServerConnect scc;
bool cmp(const QString &a, const QString &b) {
    return a.length() < b.length();
}
Auth::Auth() {
    salt = "19260817";
    loadDataBase(UDBPATH);
    loadWordList(WDBPATH);
    qDebug() << "ffffffffffffff" << WordList.size();
}
Auth::Auth(QString slt) : salt(slt) {
    loadDataBase(UDBPATH);
    loadWordList(WDBPATH);
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
            std::string tmp = i->getUsername().toStdString();
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
                rud[cnt].puzzlepassed = static_cast<Player*>(i)->getPuzzlepassed();
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
        if (type == PLAYER) {
            mpUserName2User.insert(username, new Player(UserData(username.toStdString().c_str(), genmd5(username, password).toStdString().c_str(), type)));
        } else {
            mpUserName2User.insert(username, new Designer(UserData(username.toStdString().c_str(), genmd5(username, password).toStdString().c_str(), type)));
        }
        return SUCCESS;
    } else {
        return ALREADYREG;
    }
}

QString Auth::login(QString username, QString password, QTcpSocket *conn) {
    QMap<QString, User*>::iterator itr = mpUserName2User.find(username);
    qDebug()<<(itr == mpUserName2User.constEnd());
    if (itr == mpUserName2User.constEnd() || genmd5(username, password) != itr.value()->getPasswordmd5()) {
        return "";
    }
    QMap<QString, QString>::iterator qi = mpUsername2Uuid.find(username);
    if (qi != mpUsername2Uuid.constEnd()) {
        logout(qi.value());
    }
    QString tmpUuid;
    do {
        tmpUuid = QUuid::createUuid().toString();
    } while (mpUuid2Username.find(tmpUuid) != mpUuid2Username.constEnd());
    itr.value()->setUuid(tmpUuid);
    itr.value()->setOnline(true);
    mpUuid2Username.insert(tmpUuid, username);
    mpUsername2Uuid.insert(username, tmpUuid);
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
    saveDataBase(UDBPATH);
    saveWordList(WDBPATH);
}

User *Auth::getUserByUuid(QString uuid) {
    auto itr = mpUuid2Username.find(uuid);
    if (itr == mpUuid2Username.constEnd()) return nullptr;
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
        return BADUUID;
    }
}

QVector<User *> Auth::getUserList() {
    QVector<User*> rtn;
    for (auto i : mpUserName2User) {
        rtn.push_back(i);
    }
    return rtn;
}

bool Auth::loadWordList(QString dbpath) {
    try {
        WordList.clear();
        QFileInfo fi(dbpath);
        if (!fi.isFile()) return true;
        QFile file(dbpath);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        if (!file.isOpen()) return false;
        while (!file.atEnd()) {
            QString tmp = file.readLine().trimmed();
            WordList.push_back(tmp);
        }
        file.close();
        qSort(WordList.begin(), WordList.end(), cmp);
    } catch (...) {

        return false;
    }
    return false;
}

bool Auth::saveWordList(QString dbpath) {
    try {
        QFile file(dbpath);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        if (!file.isOpen())
            return false;
        file.write(WordList.join("\n").toLocal8Bit());
        file.close();
        return true;
    } catch (...) {
        return false;
    }
    return false;
}


int Auth::addWord(QString uuid, QString word) {
    User *usr = getUser(uuid);
    if (usr == nullptr) return 1;
    if (usr->getType() != DESIGNER) return 1;
    if (word.trimmed() == "") {
        return 1;
    }
    auto tmpPtr = qLowerBound(WordList.begin(), WordList.end(), word, cmp);
    if (tmpPtr != WordList.end() && (*tmpPtr) == word) {
        return 2;
    } else {
        WordList.push_back(word);
        usr->setExp(usr->getExp() + 1);
        qSort(WordList.begin(), WordList.end(), cmp);
    }
    return 0;
}

QStringList const &Auth::getWordList() {
    return WordList;
}

void Auth::logout(QString uuid) {

    auto itr = mpUuid2Username.find(uuid);
    if (itr != mpUuid2Username.constEnd()) {
        if (mpUsername2Socket.contains(itr.value())) {
            auto conn = mpUsername2Socket.value(itr.value());
            scc.inform("logout", conn);
            conn->waitForBytesWritten();
            mpSocket2Username.remove(conn);
            if (mpUsername2Socket.contains(itr.value())) {
                mpUsername2Socket.remove(itr.value());
            }
        }
        mpUserName2User.find(itr.value()).value()->setOnline(false);
    }
    mpUsername2Uuid.remove(itr.value());
    mpUuid2Username.remove(uuid);
}

int Auth::finishChallenge(QString uuid, int difficulty, int score) {
    User *usr = getUser(uuid);
    if (usr == nullptr) return 1;
    if (usr->getType() != PLAYER) return 1;
    Player *ply = static_cast<Player*>(usr);
    ply->setPuzzlepassed(ply->getPuzzlepassed() + 1);
    ply->setExp(ply->getExp() + score);
    ply->setLevel(calcLevelP(ply->getExp()));
    return 0;
}

int Auth::calcLevelP(int exp) {
    return log(exp / 10. + 1);
}

int Auth::calcLevelD(int exp) {
    return exp / 5;
}

Challenge Auth::constructChallenge(int difficulty){
    Challenge rtn;
    rtn.setDifficulty(difficulty);
    double k = csigmoid(difficulty);
    int kn = 30 * k + 1;
    kn = __min(kn, WordList.size());                      // 关卡包含单词个数
    rtn.setMaximumtries(kn * (0.05 + (1 - k) * 0.8) + 1); // 设置最大重试次数
    int offsetbound = __max(100, 0.5 * WordList.size());    // 难度分布区间为0.5倍词库大小，太小容易导致选择的词长度高度相近
    // 这个区间可以使新加词语几乎不影响关卡难度
    int lb = __max(0, kn - offsetbound);
    int rb = __min(WordList.size(), kn + offsetbound + 1);  // 选取单词的上下界
//    lb = 0;
//    rb = WordList.size();
    for (int i = 0; i < kn; ++i) {
        int pi = qrand() % (rb - lb) + lb;
        rtn.getQzlist().push_back(Quiz(WordList.at(pi), 100 + 900 * (1 - k))); // 显示时间随着难度递增而递减
    }
    return rtn;
}

void Auth::delConn(QTcpSocket *conn) {
    if (mpSocket2Username.contains(conn)) {
        auto x = mpSocket2Username.value(conn);
        if (conn->state() == QTcpSocket::ConnectedState) conn->disconnectFromHost();
        if (mpUsername2Socket.contains(x)) {
            mpUsername2Socket.remove(x);
        }
        mpSocket2Username.remove(conn);
    }
}

void Auth::delConn(const QString &username) {
    if (mpUsername2Socket.contains(username)) {
        auto x = mpUsername2Socket.value(username);
        if (x->state() == QTcpSocket::ConnectedState) x->disconnectFromHost();
        if (mpSocket2Username.contains(x)) {
            mpSocket2Username.remove(x);
        }
        mpUsername2Socket.remove(username);
    }
}
