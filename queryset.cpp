#include "queryset.h"

#include <string>
#include <sstream>
#include <QDebug>
using namespace std;

QuerySet::QuerySet()
{

}

string QuerySet::operator[](string key)
{
    return this->dict[key];
}

// 设置queryset
void QuerySet::setValue(string key, string value)
{
    this->dict[key] = value;

    this->isIntegerKeyMapping = false;
}

void QuerySet::setValue(string key, int value)
{
    stringstream ss;
    string s;
    ss << value;

    ss >> s;
    this->dict[key] = s;
    this->isIntegerKeyMapping = false;
}

// 查找queryset
string QuerySet::findValue(string key)
{
    return this->dict[key];
}

// 拿到容量
int QuerySet::getSize()
{
    return this->dict.size();
}

map<string, string> QuerySet::getDict() const
{
    return dict;
}

/**
 * @brief QuerySet::getIntegerKeyMapping 得到正数key映射
 */
void QuerySet::getIntegerKeyMapping()
{
    if (this->isIntegerKeyMapping) {
        return;
    }

    int c = 0;
    map<string, string>::iterator ite;
    for (ite = this->getBegin(); ite != this->getEnd(); ite++) {
        integerKeyMapping[c] = ite->first;
        c++;
    }

    this->isIntegerKeyMapping = true;

}

/**
 * @brief QuerySet::fromIntegerGetKey 从数字得到key
 * @param c 数字索引
 * @return string key
 */
string QuerySet::fromIntegerGetKey(int c)
{
    if (!this->isIntegerKeyMapping) {
        return nullptr;
    }

    return this->integerKeyMapping[c];

}

/**
 * @brief QuerySet::getBegin dict的头迭代
 * @return
 */
map<string, string>::iterator QuerySet::getBegin()
{
    return this->dict.begin();
}

/**
 * @brief QuerySet::getEnd dict尾迭代
 * @return
 */
map<string, string>::iterator QuerySet::getEnd()
{
    return this->dict.end();
}

/**
 * @brief QuerySet::L debug
 */
void QuerySet::L()
{
    if (DEBUG) {

        map<string, string>::iterator ite;
        for (ite = dict.begin(); ite != dict.end(); ite++)
        {
            qDebug() << QString::fromStdString(ite->first) << ":" << QString::fromStdString(ite->second) << QString::fromStdString("\n");
        }
    }
}

void QuerySet::L_I()
{
    if (DEBUG) {

        map<int, string>::iterator ite;
        for (ite = integerKeyMapping.begin(); ite != integerKeyMapping.end(); ite++)
        {
            qDebug() << ite->first << ":" << QString::fromStdString(ite->second) << QString::fromStdString("\n");
        }
    }
}


