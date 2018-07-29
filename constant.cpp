#include "constant.h"

#include <QFile>
#include <QDebug>

string Constant::database = "carinsurancessystem";
string Constant::host = "localhost";
string Constant::password = "root";
int Constant::port = 3306;
string Constant::user = "root";



Constant::Constant()
{

}

bool Constant::loadConfig()
{
    QFile file("mysql.conf");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!";
        return false;

    }
    QTextStream in(&file);

    while( !in.atEnd()){
        QString line = in.readLine();
        QString key = getGroup("^mysql_(.*)=(.*);$", line, 1);
        QString value = getGroup("^mysql_(.*)=(.*);$", line, 2);
        routeToConf(key, value);
    }
}

/**
 * @brief Constant::getGroup 从正则得到相应组
 * @param reg
 * @param str
 * @param group
 * @return
 */
QString Constant::getGroup(QString reg, QString str, int group)
{
    QString pattern(reg);
     QRegExp rx(pattern);

     int pos = str.indexOf(rx);
     if ( pos >= 0 )
     {
           return rx.cap(group);
     }
     return nullptr;
}

/**
 * @brief Constant::routeToConf 根据key路由进配置
 * @param key
 */
void Constant::routeToConf(QString key, QString value)
{
    if (key == "username") {
        Constant::user = value.toStdString();
    }
    else if (key == "password") {
        Constant::password = value.toStdString();
    }
}
