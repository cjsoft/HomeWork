#include <QtCore>
#include <QtNetwork>
#include <QDebug>
#include <QThread>
#include <QQueue>
#include "localconnect.h"
#include "clientcommon.h"
#include "../utils/macrodef.h"


LocalConnect::LocalConnect()
{
    CurrentUser = nullptr;
//    dth = new DataHandler(&sendQ, &dataQ);
//    dth->moveToThread(dth);
//    connect(this, &LocalConnect::sendData, dth, &DataHandler::send);
    conn = new QTcpSocket;
    connect(conn, &QTcpSocket::readyRead, this, &LocalConnect::dataArrived, Qt::QueuedConnection);
    connect(conn, &QTcpSocket::disconnected, this, &LocalConnect::connDisconnected);
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
           if (obj.value("code").toInt() == 1) {
               return CODEERROR;
           } else if (obj.value("code").toInt() == 2) {
               data = obj.value("payload").toObject();
               return INFORM;
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
    if (conn->state() == QTcpSocket::UnconnectedState) {
        conn->connectToHost(CONNECTPARAM);
        conn->waitForConnected(1000);
    }
    if (conn->state() == QTcpSocket::ConnectedState) {
        auto payload = constructQuery(method, data).toJson(QJsonDocument::Compact);
        conn->write(payload);
        conn->waitForBytesWritten(1000);
//        bool tag;
//        auto rtnData = dataQ.dequeue(10000, &tag);

        if (conn->waitForReadyRead(5000)) {
            auto rtnData = conn->readAll();
            qDebug() << rtnData;
            return rtnData;
        } else {
            qDebug() << "lock failed";
        }
        return "";
    }
    return "";
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
        wordlist = data.value("lst").toString().split("\n");
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
    QJsonObject data;
    data.insert("difficulty", difficulty);
    QString rtn = doQuery("conchan", data);
    if (parseRtn(rtn, data) == 0) {
        if (data.contains("chan") && data.value("chan").isObject()) {
            QJsonObject chanjson = data.value("chan").toObject();
            return Challenge::fromJsonObject(chanjson);
        } else {
            return Challenge();
        }
    }
    return Challenge();
/*
    Challenge rtn;
    rtn.setDifficulty(difficulty);
    double k = csigmoid(difficulty);
    int kn = 30 * k + 1;
    kn = __min(kn, wordlist.size());                      // 关卡包含单词个数
    rtn.setMaximumtries(kn * (0.05 + (1 - k) * 0.8) + 1); // 设置最大重试次数
    int offsetbound = __max(100, 0.5 * wordlist.size());    // 难度分布区间为0.5倍词库大小，太小容易导致选择的词长度高度相近
                                                            // 这个区间可以使新加词语几乎不影响关卡难度
    int lb = __max(0, kn - offsetbound);
    int rb = __min(wordlist.size(), kn + offsetbound + 1);  // 选取单词的上下界
//    lb = 0;
//    rb = wordlist.size();
    for (int i = 0; i < kn; ++i) {
        int pi = qrand() % (rb - lb) + lb;
        rtn.getQzlist().push_back(Quiz(wordlist.at(pi), 100 + 900 * (1 - k))); // 显示时间随着难度递增而递减
    }
    */
//    return rtn;
}

int LocalConnect::logout() {
    if (uuid.length() > 0 && conn->state() == QTcpSocket::ConnectedState) {
        QJsonObject data;
        QString rtn = doQuery("logout", data);
        if (parseRtn(rtn, data) == 0) {
            setUuid("");
            return 0;
        }
        setUuid("");
    }
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

void LocalConnect::connectToHost(const QString &hostName, quint16 port, QTcpSocket::OpenMode mode,
                                 QTcpSocket::NetworkLayerProtocol protocol) {
    conn->connectToHost(hostName, port, mode, protocol);
}

void LocalConnect::dataArrived() {
//    return;
    auto x = QString::fromUtf8(conn->readAll());
    qDebug() << x;
    QJsonObject data;
    if (parseRtn(x, data) == INFORM) {
        if (data.value("msg").toString() == "logout") {
            forcedToLogout();
        }
    } else {
        qDebug() << "enqueing";
        qDebug() << x;
//        assert(x.length() == 0);
    }
}

void LocalConnect::connDisconnected() {
    dataQ.clear();
    MessageBox("链接丢失", "提示", QMessageBox::Ok, QMessageBox::Ok);
    pInitialForm->show();
    if (pPlayForm != nullptr) pPlayForm->close();
    if (pListUsersForm != nullptr) pListUsersForm->close();
    if (pAddWordForm != nullptr) pAddWordForm->close();
    if (pUserHomeForm != nullptr) pUserHomeForm->close();
}

void LocalConnect::forcedToLogout() {
    MessageBox("您已在其他地方登录，您将被强制下线", "提示", QMessageBox::Ok, QMessageBox::Ok);
    pInitialForm->show();
    if (pPlayForm != nullptr) pPlayForm->close();
    if (pListUsersForm != nullptr) pListUsersForm->close();
    if (pAddWordForm != nullptr) pAddWordForm->close();
    if (pUserHomeForm != nullptr) pUserHomeForm->close();
}

void LocalConnect::setConnaddr(const QString &connaddr) {
    LocalConnect::connaddr = connaddr;
}
