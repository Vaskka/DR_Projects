#include "constant.h"
#include "logindialog.h"
#include "mainwindow.h"
#include "mydownloader.h"
#include "outputitem.h"
#include "outputmodel.h"
#include <QApplication>
#include <QMessageBox>
#include <QJsonDocument>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog dlg;
    dlg.show();
    if (!Constant::loadConfig())
    {
        QMessageBox::information(nullptr, "Opps", "无法找到或打开配置文件", QMessageBox::Ok, QMessageBox::Ok);
    }



    return a.exec();
}
