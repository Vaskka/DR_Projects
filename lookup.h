#ifndef LOOKUP_H
#define LOOKUP_H

#include <map>
using namespace std;

class LookUp
{
public:
    LookUp();
    ~LookUp();
    map<string, string> cMap;
    string iterator(string ziDuan);
};
#endif // LOOKUP_H
