#ifndef MYDOWNLOADER_H
#define MYDOWNLOADER_H

#include <QFile>
#include <QObject>
#include <QUrl>
#include <QNetworkReply>

/**
* @projectName   AutomobileInsurance
* @brief         网络下载模块
* @author        Vaskka
* @date          2018-7-30
*/
class MyDownloader : public QObject
{

    Q_OBJECT
public:
    //构造函数，要求下载地址，保存位置，进度条（可选）
    MyDownloader();
    void output(QUrl url, QString path);


private:


};

#endif // MYDOWNLOADER_H
