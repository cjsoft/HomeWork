#include "localconnect.h"
#include "common.h"
#include <QtCore>
#include "macrodef.h"
#include <QDebug>
LocalConnect::LocalConnect()
{
    CurrentUser = nullptr;
}

QJsonDocument LocalConnect::constructQuery(QString method, QJsonObject data) {
    QJsonObject rtn;
    QJsonDocument doc;
    rtn.insert("method", method);
    rtn.insert("data", data);
    rtn.insert("uuid", uuid);
    doc.setObject(rtn);
    return doc;
}
int LocalConnect::parseRtn(QString str, QJsonObject &data) {
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &err);
    if (err.error == QJsonParseError::NoError && doc.isObject()) {
           QJsonObject obj = doc.object();
           if (obj.value("code").toInt() != 0) {
               return CODEERROR;
           }
           data = obj.value("data").toObject();
    } else {
        return RTNERROR;
    }
    return 0;
}
QString LocalConnect::login(QString username, QString password) {
    QJsonObject data;
    data.insert("username", username);
    data.insert("password", password);
    QString rtn = doQuery("login", data);
    qDebug() << rtn;
    uuid = "";
    if (parseRtn(rtn, data) == 0) {
        uuid = data.value("uuid").toString();
    }
    return uuid;
//    return LocalConnect::ATH.login(username, password);
}

int LocalConnect::reg(QString username, QString password, char type) {
    QJsonObject data;
    data.insert("username", username);
    data.insert("password", password);
    data.insert("type", (int)type);
    QString rtn = doQuery("register", data);
    qDebug() << rtn;
    if (parseRtn(rtn, data) == 0) {
        return data.value("regcode").toInt();
    }
    return -1;
}

void LocalConnect::setUuid(QString Uuid) {
    uuid = Uuid;
}

QString LocalConnect::getUuid() {
    return uuid;
}

User const *LocalConnect::fetchInfo() {
    QJsonObject data;
    QString rtn = doQuery("fetchinfo", data);

    qDebug() << rtn;
    if (parseRtn(rtn, data) == 0) {
        CurrentUser = User::fromJsonObject(data);
    }
    return CurrentUser;
}

QString LocalConnect::doQuery(QString method, QJsonObject data) {
    return svc.executeQuery(constructQuery(method, data).toJson());
}

User const *LocalConnect::getCurrentUser() const {
    return CurrentUser;
}

LocalConnect::~LocalConnect() {
    if (CurrentUser) delete CurrentUser;
}

int LocalConnect::setTag(const QString &tag) {
    return setThing("tag", tag);
}

int LocalConnect::setName(const QString &name) {
    return setThing("name", name);
}

int LocalConnect::setThing(const QString &key, const QString &dta) {
    QJsonObject data;
    data.insert(key, dta);
    QString rtn = doQuery("set", data);
    if (parseRtn(rtn, data) == 0) {
        return SUCCESS;
    }
    return SETFAILED;
}

int LocalConnect::addWord(const QString &word) {
    QJsonObject data;
    data.insert("word", word);
    QString rtn = doQuery("addword", data);
    if (parseRtn(rtn, data) == 0) {
        if (data.contains("addcode")) {
            return data.value("addcode").toInt();
        } else {
            return 1;
        }
    }
    return 1;
}


QStringList const &LocalConnect::fetchWordlist() {
    wordlist.clear();
    QJsonObject data;
    QString rtn = doQuery("wordlist", data);
    if (parseRtn(rtn, data) == 0) {
        QJsonArray arr = data.value("lst").toArray();
        for (auto i : arr) {
            wordlist.push_back(i.toString());
        }
    }
    qDebug() << wordlist.size();
    return wordlist;
}

int LocalConnect::fetchUserList() {
    PlayerList.clear();
    DesignerList.clear();
    QJsonObject data;
    QString rtn = doQuery("list", data);
    if (parseRtn(rtn, data) == 0) {
        QJsonArray arr = data.value("lst").toArray();
        for (auto i : arr) {
            QJsonObject ti(i.toObject());
            if (ti.value("type").toInt() == PLAYER) {
                PlayerList.push_back(Player(ti));
            } else {
                DesignerList.push_back(Designer(ti));
            }
        }
        return 0;
    }
    return 1;
}

const QVector<Player> &LocalConnect::getPlayerList() const {
    return PlayerList;
}

const QVector<Designer> &LocalConnect::getDesignerList() const {
    return DesignerList;
}

Challenge LocalConnect::constructChallenge(int difficulty) {
    Challenge rtn;
    rtn.setDifficulty(difficulty);
    double k = csigmoid(difficulty);
    int kn = 30 * k + 1;
    kn = __min(kn, wordlist.size());
    rtn.setMaximumtries(kn * (0.05 + (1 - k) * 0.8) + 1);
    int offsetbound = 0.05 * wordlist.size();
    int lb = __max(0, kn - offsetbound);
    int rb = __min(wordlist.size() - 1, kn + offsetbound + 1);
    lb = 0;
    rb = wordlist.size();
    for (int i = 0; i < kn; ++i) {
        int pi = qrand() % (rb - lb) + lb;
        rtn.getQzlist().push_back(Quiz(wordlist.at(pi), 100 + 900 * (1 - k)));
    }
    return rtn;
}

int LocalConnect::logout() {
    QJsonObject data;
    QString rtn = doQuery("logout", data);
    if (parseRtn(rtn, data) == 0) {
        setUuid("");
        return 0;
    }
    setUuid("");
    return 1;
}

int LocalConnect::finishChallenge(int difficulty, int score) {
    QJsonObject data;
    data.insert("difficulty", difficulty);
    data.insert("score", score);
    QString rtn = doQuery("finchan", data);
    if (parseRtn(rtn, data) == 0) {
        return data.value("fincode").toInt();
    }
    return 0;
}
