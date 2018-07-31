#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <string>

using namespace std;

class QueryResult
{
public:
    bool isQueryRight;

    string msg;


    QueryResult(bool isOk, string msg);
};

#endif // QUERYRESULT_H
