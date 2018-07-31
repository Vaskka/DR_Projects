#ifndef BASE_DATABASE_H
#define BASE_DATABASE_H

#include <string>
#include <mysql/mysql.h>
#include "queryresult.h"
#include "queryset.h"
#include <vector>

using namespace std;

class base_database
{
public:
    base_database();

    base_database(string host, string password, int port, string user, string database);

    string getDatabase() const;
    void setDatabase(const string &value);

    string getUser() const;
    void setUser(const string &value);

    int getPort() const;
    void setPort(int value);

    string getPassword() const;
    void setPassword(const string &value);

    string getHost() const;
    void setHost(const string &value);


    vector<QuerySet> doSelectQuery(string sql);
    QueryResult doUpdateQuery(string sql);
    QueryResult doDeleteQuery(string sql);
    QueryResult doInsertQuery(string sql);

private:
    string host;
    string password;
    int port;
    string user;
    string database;

    // 初始化mysql连接
    void init_mysql(MYSQL &mysql);

};

#endif // BASE_DATABASE_H
