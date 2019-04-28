#include "forms/initialform.h"
#include "forms/userhomeform.h"
#include "forms/addwordform.h"
#include "forms/playform.h"
#include "forms/listusersform.h"
#include <QApplication>
#include <QtGlobal>
#include <QDebug>
#include <QTime>
#include "common.h"
InitialForm *pInitialForm;
UserHomeForm *pUserHomeForm;
AddWordForm *pAddWordForm;
PlayForm *pPlayForm;
ListUsersForm *pListUsersForm;
QtAwesome* awesome;
QVariantMap ColorRed;
QVariantMap ColorGreen;
int main(int argc, char *argv[])
{
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    pInitialForm = nullptr;
    pUserHomeForm = nullptr;
    pAddWordForm = nullptr;
    pPlayForm = nullptr;
    pListUsersForm = nullptr;
    if (!qEnvironmentVariableIsSet("QT_DEVICE_PIXEL_RATIO")
                && !qEnvironmentVariableIsSet("QT_AUTO_SCREEN_SCALE_FACTOR")
                && !qEnvironmentVariableIsSet("QT_SCALE_FACTOR")
                && !qEnvironmentVariableIsSet("QT_SCREEN_SCALE_FACTORS")) {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    QApplication a(argc, argv);
    QFile qssFile(":/theme.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        QString qss = QLatin1String(qssFile.readAll());
        qDebug() << "SdF" << qss.length();
        a.setStyleSheet(qss);
        qssFile.close();
    }
    ColorRed.insert( "color" , QColor(255,0,0) );
    ColorGreen.insert( "color" , QColor(0,255,0) );
    awesome = new QtAwesome(&a);
    awesome->initFontAwesome();
    pInitialForm = new InitialForm();
    pInitialForm->show();
    return a.exec();
}
