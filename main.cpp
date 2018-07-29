#include "constant.h"
#include "logindialog.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog dlg;
    dlg.show();
    Constant::loadConfig();
    return a.exec();
}
