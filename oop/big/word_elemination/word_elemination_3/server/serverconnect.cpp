#include "serverconnect.h"
#include <QtCore>
#include <QDebug>
#include <QtNetwork>
#include "auth.h"
#include "../utils/user.h"
#include "ConnManager.h"
#include "servercommon.h"
class ConnManager;
extern ConnManager conman;

ServerConnect::ServerConnect()
{

}

QString ServerConnect::executeQuery(const QString &query, QTcpSocket *conn) {
    QJsonParseError err;
    QJsonDocument jdoc = QJsonDocument::fromJson(query.toUtf8(), &err);
    qDebug() << err.errorString();
    QJsonObject rtn, rtnData;
    if (err.error == QJsonParseError::NoError && jdoc.isObject()) {
        rtn.insert("code", 0);
        QJsonObject obj = jdoc.object();
        QString method = obj.value("method").toString();
        QString qryuuid = obj.value("uuid").toString();
        cout << "Request method: " << method.toStdString() << "\n";
        cout << "Uuid: " << qryuuid.toStdString() << "\n";
        QJsonObject data = obj.value("data").toObject();
        if (method == "login") {
            qDebug() << data.value("username").toString()<<data.value("password").toString();
            rtnData.insert("uuid", ATH.login(data.value("username").toString(), data.value("password").toString(),
                                             conn));
        } else if (method == "logout") {
            ATH.logout(qryuuid);
        } else if (method == "register") {
            rtnData.insert("regcode", ATH.reg(data.value("username").toString(), data.value("password").toString(), (char)data.value("type").toInt()));
        } else if (method == "fetchinfo") {
            User const *usr = ATH.getUser(qryuuid);
            if (usr) {
                rtnData = usr->toJsonObject();
                qDebug() << QJsonDocument(rtnData).toJson(QJsonDocument::Compact);
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
            rtnData.insert("lst", ATH.getWordList().join("\n"));
        } else if (method == "finchan") {
            if (data.contains("difficulty") && data.contains("score"))
                rtnData.insert("fincode", ATH.finishChallenge(qryuuid, data.value("difficulty").toInt(), data.value("score").toInt()));
        } else if (method == "conchan") {
            if (data.contains("difficulty")) {
                auto tmpChan = ATH.constructChallenge(data.value("difficulty").toInt());
                QJsonObject chan = tmpChan.toJsonObject();
                rtnData.insert("chan", chan);
            }
        }
        rtn.insert("method", method);
    } else {
        rtn.insert("code", 1);
    }
    rtn.insert("data", rtnData);
    jdoc.setObject(rtn);
    qDebug() << QString(jdoc.toJson(QJsonDocument::Compact));
    return QString(jdoc.toJson(QJsonDocument::Compact));
}

QJsonArray ServerConnect::QStringList2QJson(QStringList const &lst) {
    QJsonArray rtn;
    for (auto i : lst) {
        rtn.push_back(i);
    }
    return rtn;
}

void ServerConnect::inform(const QString &msg, QTcpSocket *conn) {
    if (conn->state() == QTcpSocket::ConnectedState) {
        QJsonDocument jdoc;
        QJsonObject jobj, payload;
        jobj.insert("code", 2);
        payload.insert("msg", msg);
        jobj.insert("payload", payload);
        jdoc.setObject(jobj);
        auto x = jdoc.toJson(QJsonDocument::Compact);
        conn->write(x);
    }
}
