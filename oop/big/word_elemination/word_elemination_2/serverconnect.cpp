#include "serverconnect.h"
#include <QtCore>
#include <QDebug>
#include "auth.h"
#include "user.h"
ServerConnect::ServerConnect()
{

}

QString ServerConnect::executeQuery(QString query) {
    QJsonParseError err;
    QJsonDocument jdoc = QJsonDocument::fromJson(query.toUtf8(), &err);
    qDebug() << err.errorString();
    QJsonObject rtn, rtnData;
    if (err.error == QJsonParseError::NoError && jdoc.isObject()) {
        rtn.insert("code", 0);
        QJsonObject obj = jdoc.object();
        QString method = obj.value("method").toString();
        QString qryuuid = obj.value("uuid").toString();
        QJsonObject data = obj.value("data").toObject();
        if (method == "login") {
            qDebug() << data.value("username").toString()<<data.value("password").toString();
            rtnData.insert("uuid", ATH.login(data.value("username").toString(), data.value("password").toString()));
        } else if (method == "logout") {
            ATH.logout(qryuuid);
        } else if (method == "register") {
            rtnData.insert("regcode", ATH.reg(data.value("username").toString(), data.value("password").toString(), (char)data.value("type").toInt()));
        } else if (method == "fetchinfo") {
            User const *usr = ATH.getUser(qryuuid);
            if (usr) {
                rtnData = usr->toJsonObject();
                qDebug() << QJsonDocument(rtnData).toJson();
            } else {
                rtn.insert("username", "");
            }
//            rtnData.insert("", usr.)
        } else if (method == "set") {
            User *tusr = ATH.getUser(qryuuid);
            QString parram;
            if (data.contains("tag") && data.value("tag").isString()) {
                tusr->setTag(data.value("tag").toString());
            }
            if (data.contains("name") && data.value("name").isString()) {
                tusr->setName(data.value("name").toString());
            }
            rtnData.insert("regcode", 0);
        } else if (method == "list") {
            QJsonArray lst;
            auto vec = ATH.getUserList();
            for (auto i : vec) {
                lst.push_back(i->toJsonObject());
            }
            rtnData.insert("lst", lst);
        } else if (method == "addword") {
            if (data.contains("word") && data.value("word").isString()) {
                rtnData.insert("addcode", ATH.addWord(qryuuid, data.value("word").toString()));
            }
        } else if (method == "wordlist") {
            rtnData.insert("lst", QStringList2QJson(ATH.getWordList()));
        } else if (method == "finchan") {
            if (data.contains("difficulty") && data.contains("score"))
                rtnData.insert("fincode", ATH.finishChallenge(qryuuid, data.value("difficulty").toInt(), data.value("score").toInt()));
        }
        rtn.insert("method", method);
    } else {
        rtn.insert("code", 1);
    }
    rtn.insert("data", rtnData);
    jdoc.setObject(rtn);
    qDebug() << QString(jdoc.toJson());
    return QString(jdoc.toJson());
}

QJsonObject ServerConnect::User2QJson(User const *usr) {
        QJsonObject rtnData;
        rtnData.insert("username", usr->getUsername());
        rtnData.insert("type", (int)usr->getType());
        rtnData.insert("tag", usr->getTag());
        rtnData.insert("name", usr->getName());
        rtnData.insert("level", usr->getLevel());
        rtnData.insert("exp", usr->getExp());
        rtnData.insert("online", usr->isOnline());
        if (usr->getType() == PLAYER) {
            Player const *ply = reinterpret_cast<Player const*>(usr);
            rtnData.insert("puzzlepassed", ply->getPuzzlepassed());
        }
        return rtnData;
}

QJsonArray ServerConnect::QStringList2QJson(QStringList const &lst) {
    QJsonArray rtn;
    for (auto i : lst) {
        rtn.push_back(i);
    }
    return rtn;
}
