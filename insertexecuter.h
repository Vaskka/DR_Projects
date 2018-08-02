#ifndef INSERTEXECUTER_H
#define INSERTEXECUTER_H

#include "executer.h"


/**
* @projectName   AutomobileInsurance
* @brief         插入执行器
* @author        Vaskka
* @date          2018-7-28
*/
class InsertExecuter : public Executer
{
public:
    InsertExecuter(string table);
    QueryResult doInsert(QuerySet row);
};

#endif // INSERTEXECUTER_H
