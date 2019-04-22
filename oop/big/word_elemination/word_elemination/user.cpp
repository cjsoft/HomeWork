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
const QString &User::getUserName() const {
    return username;
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


Designer::Designer() {}
Designer::Designer(UserData ud) : User(ud) {

}
