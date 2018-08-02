#ifndef USER_H
#define USER_H

#include <QString>

#include <string>

using namespace std;

/**
* @projectName   AutomobileInsurance
* @brief         用户类
* @author        Vaskka
* @date          2018-7-26
*/
class User
{
public:
    User();

    /**
     * @brief User
     * @param name 用户名
     * @param number 员工编号
     * @param access 权限
     */
    User(string name, string number, int access);

    /**
     * 姓名
     * @brief name
     */
    QString name = QString("Nex");

    /**
     * 编号
     * @brief number
     */
    QString number = QString("2333333");

    /**
     * 权限
     * 1 : 普通用户
     * 0 : root用户
     * @brief access
     */
    int access = 0;
};

#endif // USER_H
