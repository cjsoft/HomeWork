#include "user.h"
#include <QDebug>
User::User()
{
    username = "";
    name = "";
    passwordmd5 = "";
    type = -1;
    uuid = "";
    exp = level = 0;
    online = false;
}

User::User(UserData ud) {
    username = ud.username;
    passwordmd5 = ud.passwordmd5;
    name = ud.name;
    tag = ud.tag;
//    qDebug() << "SADSAF" << ud.passwordmd5;
    type = ud.usertype;
    uuid = "";
    online = false;
    level = ud.level;
    exp = ud.exp;
}

const char &User::getType() const {
    return type;
}
const QString &User::getUuid() const {
    return uuid;
}

const QString &User::getPasswordmd5() const {
    return passwordmd5;
}
bool User::isOnline() const {
    return online;
}

const QString &User::getTag() const {
    return tag;
}

void User::setTag(const QString &tag) {
    User::tag = tag;
}

void User::setUsername(const QString &username) {
    User::username = username;
}

void User::setType(char type) {
    User::type = type;
}

const QString &User::getName() const {
    return name;
}

void User::setName(const QString &name) {
    User::name = name;
}

void User::setUuid(const QString &uuid) {
    User::uuid = uuid;
}

const QString &User::getUsername() const {
    return username;
}

int User::getLevel() const {
    return level;
}

void User::setLevel(int level) {
    User::level = level;
}

int User::getExp() const {
    return exp;
}

void User::setExp(int exp) {
    User::exp = exp;
}

QJsonObject User::toJsonObject() const {
    QJsonObject rtnData;
    rtnData.insert("username", this->getUsername());
    rtnData.insert("type", (int)this->getType());
    rtnData.insert("tag", this->getTag());
    rtnData.insert("name", this->getName());
    rtnData.insert("level", this->getLevel());
    rtnData.insert("exp", this->getExp());
    rtnData.insert("online", this->isOnline());
    if (this->getType() == PLAYER) {
        Player const *ply = static_cast<Player const*>(this);
        rtnData.insert("puzzlepassed", ply->getPuzzlepassed());
    }
    return rtnData;
}

User *User::fromJsonObject(const QJsonObject &data) {
    User *CurrentUser = nullptr;
    if (!data.contains("type")) return nullptr;
    if (data.value("type").toInt() == PLAYER) {
        CurrentUser = new Player();
    } else {
        CurrentUser = new Designer();
    }
    if (data.contains("type"))
        CurrentUser->setType(data.value("type").toInt());
    else
        qDebug() << "no type";
    if (data.contains("tag"))
        CurrentUser->setTag(data.value("tag").toString());
    else
        qDebug() << "no tag";
    if (data.contains("username"))
        CurrentUser->setUsername(data.value("username").toString());
    else
        qDebug() << "no username";
    if (data.contains("name"))
        CurrentUser->setName(data.value("name").toString());
    else
        qDebug() << "no name";
    if (data.contains("level"))
        CurrentUser->setLevel(data.value("level").toInt());
    else
        qDebug() << "no level";
    if (data.contains("exp"))
        CurrentUser->setExp(data.value("exp").toInt());
    else
        qDebug() << "no exp";
    if (data.contains("online"))
        CurrentUser->setOnline(data.value("online").toBool());
    else
        qDebug() << "no online";
    if (data.value("type").toInt() == PLAYER) {
        Player *p = static_cast<Player*>(CurrentUser);
        if (data.contains("puzzlepassed"))
            p->setPuzzlepassed(data.value("puzzlepassed").toInt());
        else
            qDebug() << "no puzzlepassed";
    } else {
        Designer *p = static_cast<Designer*>(CurrentUser);
    }
    return CurrentUser;
}

bool User::cmpByExp(User const *a, User const *b) {
    return a->getExp() > b->getExp();
}

bool User::cmpByLevel(User const *a, User const *b) {
    return a->getLevel() > b->getLevel();
}

void User::setOnline(bool online) {
    User::online = online;
}


Player::Player() : User() {
    puzzlepassed = 0;
}
Player::Player(UserData ud) : User(ud) {
    puzzlepassed = 0;
}

int Player::getPuzzlepassed() const {
    return puzzlepassed;
}

void Player::setPuzzlepassed(int puzzlepassed) {
    Player::puzzlepassed = puzzlepassed;
}

bool Player::cmpByPuzzlepassed(Player const *a, Player const *b) {
    return a->getPuzzlepassed() > b->getPuzzlepassed();
}

Player::Player(const QJsonObject &obj) {
    Player *tmp = static_cast<Player*>(fromJsonObject(obj));
    (*this) = (*tmp);
    delete tmp;
}


Designer::Designer() {}
Designer::Designer(UserData ud) : User(ud) {

}

Designer::Designer(const QJsonObject &obj) {
    Designer *tmp = static_cast<Designer*>(fromJsonObject(obj));
    (*this) = (*tmp);
    delete tmp;
}
