#ifndef EXECUTER_H
#define EXECUTER_H

#include <map>
#include <string>
#include <vector>
#include "base_database.h"
#include "constant.h"
#include "executer_filter.h"
#include "queryset.h"
using namespace std;

class Executer
{
public:
    Executer();
    Executer(string table);
    string table;

    base_database *maker = new base_database(Constant::host, Constant::password, Constant::port, Constant::user, Constant::database);

    // 过滤器
    Executer_Filter filter;


//    // 插入
//    static void dealInsert();

//    // 更新
//    static void dealUpdate(QuerySet value);

//    // 删除
//    static void dealDelete();

};

#endif // EXECUTER_H
