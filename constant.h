#ifndef CONSTANT_H
#define CONSTANT_H

#include <qstring.h>
#include <string>
using namespace std;

class Constant
{
public:
    Constant();

    /* for mysql */
    static string host;
    static string password;
    static int port;
    static string user;
    static string database;

    /**
     * @brief loadConfig 加载配置
     */
    static bool loadConfig();

    /**
     * @brief getGroup 从正则获得相应组
     * @param reg 正则
     * @param str 字符串
     * @param group 组数 默认1
     * @return QString
     */
    static QString getGroup(QString reg, QString str, int group=1);
private:
    static void routeToConf(QString key, QString value);
};

#endif // CONSTANT_H
