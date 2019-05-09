#pragma once


#ifndef CHALLENGE_H
#define CHALLENGE_H
//#include "common.h"
#include <QtCore>
#include <QString>
#include <QVector>
#include <QPair>
class Quiz;
class Challenge
{
private:
    int difficulty;
    QVector<Quiz> qzlist;
    int maximumtries;
public:
    int getMaximumtries() const;

    void setMaximumtries(int maximumtries);

    int getDifficulty() const;

    void setDifficulty(int difficulty);

    QVector<Quiz> & getQzlist();

    void setQzlist(const QVector<Quiz> &qzlist);

    QJsonObject toJsonObject() const;

    static Challenge fromJsonObject(const QJsonObject &obj);

    Challenge();
};

class Quiz {
public:
    Quiz();
    Quiz(QString word, int time);
    const QString &getWord() const;

    void setWord(const QString &word);

    int getTime() const;

    void setTime(int time);

private:
    QString word;
    int time;

};
#endif // CHALLENGE_H
