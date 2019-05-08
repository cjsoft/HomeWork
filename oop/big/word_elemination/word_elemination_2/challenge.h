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
    QVector<Quiz> qzlist;
    int maximumtries;
public:
    int getMaximumtries() const;

    void setMaximumtries(int maximumtries);

    int getDifficulty() const;

    void setDifficulty(int difficulty);

    QVector<Quiz> & getQzlist();

    void setQzlist(const QVector<Quiz> &qzlist);

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
