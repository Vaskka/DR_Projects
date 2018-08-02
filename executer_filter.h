#ifndef EXECUTER_FILTER_H
#define EXECUTER_FILTER_H

#include <string>
#include <vector>
#include <map>
using namespace std;
/**
* @projectName   AutomobileInsurance
* @brief         过滤器
* @author        Vaskka
* @date          2018-7-28
*/
class Executer_Filter
{
public:
    const string STATUS = "AND";
    Executer_Filter();
    map<string, string> indexs;

    /**
     * @brief addFilter 添加过滤映射
     * @param key
     * @param value
     */
    void addFilter(string key, string value);

    /**
     * @brief isEmpty 判断是否为空
     * @return
     */
    bool isEmpty();

    /**
     * @brief toString 得到格式化的sql过滤语句
     * @return
     */
    string toString();

};

#endif // EXECUTER_FILTER_H
