#include "initialform.h"
#include "userhomeform.h"
#include <QApplication>
class UserHomeForm;
InitialForm *pInitialForm;
UserHomeForm *pUserHomeForm;
int main(int argc, char *argv[])
{
    if (!qEnvironmentVariableIsSet("QT_DEVICE_PIXEL_RATIO")
                && !qEnvironmentVariableIsSet("QT_AUTO_SCREEN_SCALE_FACTOR")
                && !qEnvironmentVariableIsSet("QT_SCALE_FACTOR")
                && !qEnvironmentVariableIsSet("QT_SCREEN_SCALE_FACTORS")) {
                QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
            }
    QApplication a(argc, argv);

    pInitialForm = new InitialForm();
    pInitialForm->show();
    return a.exec();
}
