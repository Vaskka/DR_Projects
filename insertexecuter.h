#ifndef INSERTEXECUTER_H
#define INSERTEXECUTER_H

#include "executer.h"


// over test
class InsertExecuter : public Executer
{
public:
    InsertExecuter(string table);
    QueryResult doInsert(QuerySet row);
};

#endif // INSERTEXECUTER_H
