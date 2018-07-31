#include "constant.h"
#include "selectexecuter.h"

#include <QFile>
#include <QDebug>
#include <QDate>
#include <sstream>
#include <string>
using namespace std;

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
    return true;
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

bool Constant::checkCarNumber(string carNumber)
{

    if (getGroup(QString::fromStdString("^[京津沪渝冀豫云辽黑湘皖鲁新苏浙赣鄂桂甘晋蒙陕吉闽贵粤青藏川宁琼使领A-Z]{1}[A-Z]{1}[A-Z0-9]{4}[A-Z0-9挂学警港澳]{1}$"), QString::fromStdString(carNumber), 0) != nullptr)
    {
        return true;
    }
    return false;

}

bool Constant::checkTelNumber(string telNumber)
{
    if (getGroup(QString::fromStdString("^((13[0-9])|(14[5|7])|(15([0-3]|[5-9]))|(18[0,5-9]))\\d{8}$"), QString::fromStdString(telNumber), 0) != nullptr)
    {
        return true;
    }
    return false;

}

bool Constant::checkPersonalNumber(string personalNumber)
{
    if (getGroup(QString::fromStdString("^(^[1-9]\\d{7}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}$)|(^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])((\\d{4})|\\d{3}[Xx])$)$"), QString::fromStdString(personalNumber), 0) != nullptr)
    {
        return true;
    }
    return false;
}

bool Constant::checkNumber(string num)
{
    if (getGroup(QString::fromStdString("^([1-9]\\d*|[0]{1,1})$"), QString::fromStdString(num), 0) != nullptr)
    {
        return true;
    }
    return false;
}

int Constant::toInt(string n)
{
    return QString::fromStdString(n).toInt();
}

float Constant::getCarForceDownRatio(string carNumber)
{

    SelectExecuter sel = SelectExecuter("case_reportcaseinfo");

    sel.filter.addFilter("PlateNumber", carNumber);

    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();

    if (result.size() == 0)
    {
        return -1;
    }

    vector<QDate> datelist = vector<QDate>();

    for (int i = 0; i < result.size(); i ++)
    {
        datelist.push_back(QDate::fromString(result.at(i)["TimeOfOccurrenceOfCase"].c_str(), QString::fromStdString("yyyy-M-d")));
    }

    sort(datelist.begin(), datelist.end());

    Executer base = Executer();
    string key = "select datediff('" + datelist.at(datelist.size() - 2).toString().toStdString() + "', '" + datelist.at(datelist.size() - 1).toString().toStdString() +"');";
    vector<QuerySet> diffResult = base.maker->doSelectQuery(key);


    int days = toInt(diffResult.at(0)[key]);

    if (days >= 0 && days <= 365)
    {
        return 1;
    }
    else if (days >= 366 && days <= 730)
    {
        return 0.9f;
    }
    else if (days >= 731 && days <= 1095)
    {
        return 0.8f;
    }
    else
    {
        return 0.7f;
    }

}

float Constant::getCarCommcialDownRatio(string carNumber)
{

    SelectExecuter sel = SelectExecuter("case_reportcaseinfo");

    sel.filter.addFilter("PlateNumber", carNumber);

    // 得到结果是一组结果集的向量
    vector<QuerySet> result = sel.doSelect();

    if (result.size() == 0)
    {
        return -1;
    }

    vector<QDate> datelist = vector<QDate>();

    for (int i = 0; i < result.size(); i ++)
    {
        datelist.push_back(QDate::fromString(result.at(i)["TimeOfOccurrenceOfCase"].c_str(), QString::fromStdString("yyyy-M-d")));
    }

    sort(datelist.begin(), datelist.end());

    Executer base = Executer();
    string key = "select datediff('" + datelist.at(datelist.size() - 2).toString().toStdString() + "', '" + datelist.at(datelist.size() - 1).toString().toStdString() +"');";
    vector<QuerySet> diffResult = base.maker->doSelectQuery(key);

    int days = toInt(diffResult.at(0)[key]);

    if (days >= 0 && days <= 365)
    {
        return 1;
    }
    else if (days >= 366 && days <= 730)
    {
        return 0.6141f;
    }
    else if (days >= 731 && days <= 1095)
    {
        return 0.5058f;
    }
    else
    {
        return 0.4335f;
    }

}

string Constant::fromIntToString(int n)
{
    stringstream ss;

    ss << n;
    string str;
    ss >> str;

    return str;

}

string Constant::fromFloatToString(float n)
{
    stringstream ss;

    ss << n;
    string str;
    ss >> str;

    return str;
}

bool Constant::checkFloat(string fl)
{
    if (getGroup(QString::fromStdString("^\\d+\\.\\d+$"), QString::fromStdString(fl), 0) != nullptr)
    {
        return true;
    }
    return false;
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
