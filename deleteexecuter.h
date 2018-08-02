#ifndef DELETEEXECUTER_H
#define DELETEEXECUTER_H

#include "executer.h"

/**
* @projectName   AutomobileInsurance
* @brief         mysql通用删除接口
* @author        Vaskka
* @date          2018-7-27
*/
class DeleteExecuter : public Executer
{
public:
    DeleteExecuter(string table);

    /**
     * @brief doDelete 执行删除
     * @return
     */
    QueryResult doDelete();
};

#endif // DELETEEXECUTER_H
