#include "base_database.h"
#include "deleteexecuter.h"

#include <iostream>

DeleteExecuter::DeleteExecuter(string table)
{
    this->table = table;

}

QueryResult DeleteExecuter::doDelete()
{
    if (this->filter.isEmpty()) {
        cerr << "error:未给删除器指定过滤器" << endl;
        return QueryResult(false, "error:未给删除器指定过滤器");
    }
    string result = "delete from " + table + " where " + this->filter.toString() + ";";
    cout << result;
    return this->maker->doDeleteQuery(result);
}


