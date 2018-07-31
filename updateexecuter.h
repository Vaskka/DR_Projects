#ifndef UPDATEEXECUTER_H
#define UPDATEEXECUTER_H

#include "executer.h"


// Over test
class UpdateExecuter : public Executer
{
public:
    UpdateExecuter(string table);
    QueryResult doUpdate(QuerySet dataToUpdate);
};

#endif // UPDATEEXECUTER_H
