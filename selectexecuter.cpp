#include "selectexecuter.h"
#include <iostream>
#include <QDebug>
#include <QString>

SelectExecuter::SelectExecuter(string table)
{
    this->table = table;
}

vector<QuerySet> SelectExecuter::doSelect()
{
    string fil;
    if (this->filter.isEmpty()) {
        fil = "";
    }
    else {
        fil =" WHERE " + this->filter.toString();
    }

    string result = "SELECT * FROM " + this->table + fil + ";";
    //qDebug() << QString::fromStdString(result);
    // cout << result << endl;
    return this->maker->doSelectQuery(result);
}
