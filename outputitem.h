#ifndef OUTPUTITEM_H
#define OUTPUTITEM_H

#include <QJsonObject>
#include <QString>
#include <string>

using namespace std;
class OutputItem
{
public:
    OutputItem();

    // json maker
    QJsonObject json;

    /**
     * @brief setValue 设置键值映射
     * @param key
     * @param value
     */
    void setValue(QString key, QString value);

    /**
     * @brief toString 得到json字符串
     * @return
     */
    string toString();
};

#endif // OUTPUTITEM_H
