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
        } else if (method == "register") {
            rtnData.insert("regcode", ATH.reg(data.value("username").toString(), data.value("password").toString(), (char)data.value("type").toInt()));
        } else if (method == "fetchinfo") {
            User const *usr = ATH.getUser(qryuuid);
            if (usr) {
                rtnData.insert("username", usr->getUserName());
                rtnData.insert("type", (int)usr->getType());
                rtnData.insert("tag", usr->getTag());
                rtnData.insert("name", usr->getName());
                rtnData.insert("level", usr->getLevel());
                rtnData.insert("exp", usr->getExp());
                if (usr->getType() == PLAYER) {
                    Player const *ply = reinterpret_cast<Player const*>(usr);
                    rtnData.insert("puzzlepassed", ply->getPuzzlepassed());
                }
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
        }

    } else {
        rtn.insert("code", 1);
    }
    rtn.insert("data", rtnData);
    jdoc.setObject(rtn);
    qDebug() << QString(jdoc.toJson());
    return QString(jdoc.toJson());
}
