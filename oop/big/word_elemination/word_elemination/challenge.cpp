#include "challenge.h"

Challenge::Challenge()
{

}

QVector<Quiz> & Challenge::getQzlist() {
    return qzlist;
}

void Challenge::setQzlist(const QVector<Quiz> &qzlist) {
    Challenge::qzlist = qzlist;
}

int Challenge::getDifficulty() const {
    return difficulty;
}

void Challenge::setDifficulty(int difficulty) {
    Challenge::difficulty = difficulty;
}

const QString &Quiz::getWord() const {
    return word;
}

void Quiz::setWord(const QString &word) {
    Quiz::word = word;
}

int Quiz::getTime() const {
    return time;
}

void Quiz::setTime(int time) {
    Quiz::time = time;
}

Quiz::Quiz() : time(0), word(""){

}

Quiz::Quiz(QString word, int time) : word(word), time(time) {

}
