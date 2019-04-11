#ifndef USER_H
#define USER_H
#include <QString>

class User
{
private:
    QString authcode;
public:
    User();
};

class Player : public User {
private:
    int exp;
    int level;

public:
    int getExp() const;
    int getLevel() const;

};

class Designer : public User {
    void addWord(QString wd);
};

#endif // USER_H
