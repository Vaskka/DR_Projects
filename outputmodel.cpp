#include "outputmodel.h"

#include <QJsonDocument>


OutputModel::OutputModel()
{

}

QString OutputModel::toString()
{
    // 构建 JSON 文档
    QJsonDocument document;
    document.setArray(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    return strJson;
}

void OutputModel::append(string jsonItem)
{
    this->json.append(jsonItem.c_str());
}

void OutputModel::run(QString url, QString path)
{
    this->loader.output(url + "?data=" + this->toString(), path);
}
