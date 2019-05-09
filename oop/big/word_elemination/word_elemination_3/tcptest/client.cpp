#include <QCoreApplication>
#include <QtNetwork>
#include <QDebug>

class Receiver : public QObject {
public:
    QTcpSocket *socket;
    Receiver() : QObject() {
        socket = new QTcpSocket;
        connect(socket, &QTcpSocket::readyRead, this, &Receiver::dataArrived);

    }
    void dataArrived() {
        QString str = socket->readAll();
        qDebug() << str;
    }
} tmp;

int main(int argc,char *argv[]) {
    QCoreApplication app(argc,argv);
    tmp.socket->connectToHost("127.0.0.1", 23333);
    tmp.socket->write("hello");
    return app.exec();
}