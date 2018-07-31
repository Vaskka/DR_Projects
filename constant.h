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

    /**
     * @brief checkCarNumber 检查车牌号
     * @param carNumber
     * @return bool
     */
    static bool checkCarNumber(string carNumber);

    /**
     * @brief checkTelNumber 检查电话号
     * @param telNumber
     * @return bool
     */
    static bool checkTelNumber(string telNumber);

    /**
     * @brief checkPersonalNumber 检查身份证
     * @param personalNumber
     * @return bool
     */
    static bool checkPersonalNumber(string personalNumber);

    /**
     * @brief checkNumber 检查金额
     * @param num
     * @return bool
     */
    static bool checkNumber(string num);

    /**
     * @brief toInt string 转 int
     * @param n
     * @return int
     */
    static int toInt(string n);

    /**
     * @brief getCarDownRatio 得到某辆车的交强险比率
     * @param carNumber
     * @return float
     */
    static float getCarForceDownRatio(string carNumber);

    /**
     * @brief getCarCommcialDownRatio 得到某辆车的商业险比率
     * @param carNumber
     * @return float
     */
    static float getCarCommcialDownRatio(string carNumber);

    /**
     * @brief fromIntToString int 转string
     * @param n
     * @return std::string
     */
    static string fromIntToString(int n);

    /**
     * @brief fromFloatToString float 转string
     * @param n
     * @return std::string
     */
    static string fromFloatToString(float n);

    /**
     * @brief checkFloat 检查浮点数
     * @param fl
     * @return bool
     */
    static bool checkFloat(string fl);

private:
    static void routeToConf(QString key, QString value);
};

#endif // CONSTANT_H
