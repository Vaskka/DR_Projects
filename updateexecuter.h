#ifndef UPDATEEXECUTER_H
#define UPDATEEXECUTER_H

#include "executer.h"


/**
* @projectName   AutomobileInsurance
* @brief         更新执行器
* @author        Vaskka
* @date          2018-7-27
*/
class UpdateExecuter : public Executer
{
public:
    UpdateExecuter(string table);
    QueryResult doUpdate(QuerySet dataToUpdate);
};

#endif // UPDATEEXECUTER_H
