#include <QCoreApplication>
#include <QtNetwork>
#include <QDebug>
#include <QVector>
#include <QThread>
#include "server.h"
#include "servercommon.h"
ServerConnect scc;
ConnManager conman;
Auth ATH;
int main(int argc,char *argv[]) {
    QCoreApplication app(argc,argv);
    cout << QString().sprintf("Word  Elemation Server build on " __DATE__ " " __TIME__ "\n"
                              "Code by CJSoft https://wallacenews.tk\n").toStdString();
    conman.listen(QHostAddress::Any, 23333);
    return app.exec();

}