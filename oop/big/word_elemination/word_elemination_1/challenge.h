#pragma once

#include "common.h"
#include <QString>
#include <QVector>
#include <QPair>


#ifndef CHALLENGE_H
#define CHALLENGE_H
class Quiz;
class Challenge
{
private:
    int difficulty;
public:
    int getDifficulty() const;

    void setDifficulty(int difficulty);

private:
    QVector<Quiz> qzlist;
public:
    QVector<Quiz> & getQzlist();

    void setQzlist(const QVector<Quiz> &qzlist);

public:
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
