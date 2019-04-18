#pragma once

#include "common.h"
#include <QString>
#include <QVector>
#include <QPair>


#ifndef CHALLENGE_H
#define CHALLENGE_H

class Challenge
{
public:
    Challenge();
    QVector<Quiz> qzlist;
};

#endif // CHALLENGE_H
