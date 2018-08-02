
#include "mydownloader.h"
#include <cstdlib>

MyDownloader::MyDownloader()
{

}

void MyDownloader::output(QUrl url, QString path)
{
    system(("wget -O \"insure.xlt\" " + url.toString().toStdString()).c_str());
}
