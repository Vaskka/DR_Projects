#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <string>

using namespace std;

/**
* @projectName   AutomobileInsurance
* @brief         查询结果状态
* @author        Vaskka
* @date          2018-7-27
*/
class QueryResult
{
public:
    bool isQueryRight;

    string msg;


    QueryResult(bool isOk, string msg);
};

#endif // QUERYRESULT_H
