#pragma once

#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H
#include "auth.h"

class ServerConnect
{
private:
    Auth ATH;
public:
    ServerConnect();
    QString executeQuery(QString query);
};

#endif // SERVERCONNECT_H
