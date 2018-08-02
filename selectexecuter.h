#ifndef SELECTEXECUTER_H
#define SELECTEXECUTER_H

#include "executer.h"


/**
* @projectName   AutomobileInsurance
* @brief         获取执行器
* @author        Vaskka
* @date          2018-7-27
*/
class SelectExecuter : public Executer
{
public:
    SelectExecuter(string table);
    // 全部查询
    vector<QuerySet> doSelect();

};

#endif // SELECTEXECUTER_H
