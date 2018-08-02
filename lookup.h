#ifndef LOOKUP_H
#define LOOKUP_H

#include <map>
using namespace std;

/**
* @projectName   AutomobileInsurance
* @brief         翻译器
* @author        Vaskka
* @date          2018-7-31
*/
class LookUp
{
public:
    LookUp();
    ~LookUp();
    map<string, string> cMap;
    /**
     * @brief iterator 根据字段映射翻译
     * @param ziDuan 字段
     * @return 翻译Unicode
     */
    string iterator(string ziDuan);

    /**
     * @brief deIterator 根据翻译映射字段
     * @param trans 翻译Unicode
     * @return 字段
     */
    string deIterator(string trans);
};
#endif // LOOKUP_H
