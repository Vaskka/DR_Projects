#include "outputitem.h"

#include <QJsonDocument>

#include <string>
using namespace std;

OutputItem::OutputItem()
{

}

void OutputItem::setValue(QString key, QString value)
{
    this->json.insert(key, value);
}

string OutputItem::toString()
{
    // 构建 JSON 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);



    return strJson.toStdString();
}

