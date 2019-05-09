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

int Challenge::getMaximumtries() const {
    return maximumtries;
}

void Challenge::setMaximumtries(int maximumtries) {
    Challenge::maximumtries = maximumtries;
}

QJsonObject Challenge::toJsonObject() const {
    QJsonObject rtn;
    rtn.insert("tries", getMaximumtries());
    QJsonArray lst;
    for (auto i : qzlist) {
        QJsonObject record;
        record.insert("word", i.getWord());
        record.insert("time", i.getTime());
        lst.push_back(record);
    }
    rtn.insert("lst", lst);
    return rtn;
}

Challenge Challenge::fromJsonObject(const QJsonObject &obj) {
    Challenge rtn;
    if (obj.contains("tries"))
        rtn.setMaximumtries(obj.value("tries").toInt());
    if (obj.contains("lst") && obj.value("lst").isArray()) {
        auto tmp = obj.value("lst").toArray();
        for (auto i : tmp) {
            auto ti = i.toObject();
            if (
                    ti.contains("word") && ti.value("word").isString() &&
                    ti.contains("time")
            )
                rtn.getQzlist().push_back(Quiz(ti.value("word").toString(), ti.value("time").toInt()));
        }
    }
    return rtn;
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
