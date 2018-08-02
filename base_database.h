#ifndef BASE_DATABASE_H
#define BASE_DATABASE_H

#include <string>
#include <mysql/mysql.h>
#include "queryresult.h"
#include "queryset.h"
#include <vector>

using namespace std;

/**
* @projectName   AutomobileInsurance
* @brief         基本数据库工具
* @author        Vaskka
* @date          2018-7-26
*/
class base_database
{
public:
    base_database();

    base_database(string host, string password, int port, string user, string database);

    /**
     * @brief getDatabase 得到数据库名
     * @return string 数据库名
     */
    string getDatabase() const;

    /**
     * @brief setDatabase 设置数据库名
     * @param value 新数据库名
     */
    void setDatabase(const string &value);

    /**
     * @brief getUser 得到用户名
     * @return  返回用户名
     */
    string getUser() const;

    /**
     * @brief setUser 设置用户
     * @param value
     */
    void setUser(const string &value);

    /**
     * @brief getPort 获得端口
     * @return 端口号
     */
    int getPort() const;

    /**
     * @brief setPort 设置端口号
     * @param value
     */
    void setPort(int value);

    /**
     * @brief getPassword
     * @return
     */
    string getPassword() const;

    /**
     * @brief setPassword 设置密码
     * @param value 新密码
     */
    void setPassword(const string &value);

    /**
     * @brief getHost 获得ip
     * @return
     */
    string getHost() const;

    /**
     * @brief setHost 设置密码
     * @param value
     */
    void setHost(const string &value);

    /**
     * @brief doSelectQuery 执行查询
     * @param sql sql语句
     * @return
     */
    vector<QuerySet> doSelectQuery(string sql);

    /**
     * @brief doUpdateQuery 执行更新
     * @param sql sql语句
     * @return
     */
    QueryResult doUpdateQuery(string sql);

    /**
     * @brief doDeleteQuery 执行删除
     * @param sql sql语句
     * @return
     */
    QueryResult doDeleteQuery(string sql);

    /**
     * @brief doInsertQuery 执行插入
     * @param sql
     * @return
     */
    QueryResult doInsertQuery(string sql);

private:
    /**
     * @brief host ip
     */
    string host;

    /**
     * @brief password 密码
     */
    string password;

    /**
     * @brief port 端口号
     */
    int port;

    /**
     * @brief user 用户名
     */
    string user;

    /**
     * @brief database 数据库名
     */
    string database;

    /**
     * @brief init_mysql 初始化mysql连接
     * @param mysql sql语句
     */
    void init_mysql(MYSQL &mysql);

};

#endif // BASE_DATABASE_H
