#include "queryresult.h"

QueryResult::QueryResult(bool isOk, string msg)
{
    this->isQueryRight = isOk;
    this->msg = msg;
}
