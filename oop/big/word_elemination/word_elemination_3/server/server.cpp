#include <QCoreApplication>
#include <QtNetwork>
#include <QDebug>
#include <QVector>
#include <QThread>
#include "server.h"
ServerConnect scc;
ConnManager conman;
Auth ATH;
int main(int argc,char *argv[]) {
    QCoreApplication app(argc,argv);
    qDebug() << "sd";
    conman.listen(QHostAddress::Any, 23333);
    return app.exec();
    qDebug() << "sd";
    qDebug() << "sd";
}