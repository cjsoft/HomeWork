#include "localconnect.h"
#include "common.h"
#include <QtCore>
#include "macrodef.h"
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
        if (data.value("type").toInt() == PLAYER) {
            CurrentUser = new Player();
        } else {
            CurrentUser = new Designer();
        }
        CurrentUser->setType(data.value("type").toInt());
        CurrentUser->setTag(data.value("tag").toString());
        CurrentUser->setUsername(data.value("username").toString());
        CurrentUser->setName(data.value("name").toString());
        CurrentUser->setLevel(data.value("level").toInt());
        CurrentUser->setExp(data.value("exp").toInt());
        if (data.value("type").toInt() == PLAYER) {
            Player *p = reinterpret_cast<Player*>(CurrentUser);
            p->setPuzzlepassed(data.value("puzzlepassed").toInt());
        } else {
            Designer *p = reinterpret_cast<Designer*>(CurrentUser);
        }
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
