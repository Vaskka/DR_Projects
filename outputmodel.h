#ifndef OUTPUTMODEL_H
#define OUTPUTMODEL_H

#include "mydownloader.h"

#include <QJsonArray>
#include <string>
#define OUTPUT_FILE_NAME "output.xlt"
using namespace std;

/**
* @projectName   AutomobileInsurance
* @brief         文件输出模型
* @author        Vaskka
* @date          2018-7-30
*/
class OutputModel
{
public:
    OutputModel();
    QJsonArray json;

    MyDownloader loader;

    /**
     * @brief toString 输出json
     * @return
     */
    QString toString();

    /**
     * @brief append 添加一个json串
     * @param jsonItem
     */
    void append(string jsonItem);

    /**
     * @brief run 获得输出文件
     * @param url
     * @param path
     */
    void run(QString url, QString path=OUTPUT_FILE_NAME);

private:
    QString path = QString(OUTPUT_FILE_NAME);

};

#endif // OUTPUTMODEL_H
