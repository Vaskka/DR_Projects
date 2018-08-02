#ifndef QUERYSET_H
#define QUERYSET_H

#include "lookup.h"

#include <string>
#include <map>
using namespace std;

/**
* @projectName   AutomobileInsurance
* @brief         查询结果集
* @author        Vaskka
* @date          2018-7-27
*/
class QuerySet
{
public:
    QuerySet();

    string operator[](string key);

    void setValue(string key, string value);

    void setValue(string key, int value);

    string findValue(string key);

    /**
     * @brief getSize 获得容量
     * @return
     */
    int getSize();

    map<string, string> getDict() const;

    /**
     * @brief getIntegerKeyMapping 进行int与key的映射
     */
    void getIntegerKeyMapping();

    /**
     * @brief fromIntegerGetKey 从int到相应key
     * @param c int
     * @return string key
     */
    string fromIntegerGetKey(int c);

    /**
     * @brief getBegin 内部头迭代
     * @return
     */
    map<string, string>::iterator getBegin();
    /**
     * @brief getEnd 内部尾迭代
     * @return
     */
    map<string, string>::iterator getEnd();

    /**
     * @brief remove 移除某个键值映射
     * @param key
     */
    bool remove(string key);

    /**
     * @brief L for debug
     */
    void L();

    /**
     * @brief L_I debug int key mapping
     */
    void L_I();

private:
    const static bool DEBUG = true;

    map<string, string> dict;

    /**
     * @brief isIntegerKeyMapping 是否全部进行了key->int
     */
    bool isIntegerKeyMapping = false;

    /**
     * @brief integerKeyMapping 编号与key的映射
     */
    map<int, string> integerKeyMapping;
};

#endif // QUERYSET_H
