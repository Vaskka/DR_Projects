#include "mydownloader.h"

#include <QFileInfo>

MyDownloader::MyDownloader()
{
    downloadFile = NULL;
    downloadReply = NULL;
    bisFinished = false;
}

MyDownloader::~MyDownloader()
{
    cancel();
}

void MyDownloader::setData(QUrl url, QString pathtoSave)
{
    downloadUrl = url;
    savePath = pathtoSave;
}

void MyDownloader::getFile()
{

    qDebug() << savePath;
    create(savePath);
    if (savePath.isEmpty() || downloadUrl.isEmpty())
    {
        qDebug() << "a";
        return;
    }
    if (downloadFile)
    {
        qDebug() << "a";
        return;
    }
    bisFinished = false;
    downloadFile = new QFile(savePath);



    if (!downloadFile->open(QIODevice::WriteOnly))
    {

        delete downloadFile;
        downloadFile = 0;
        return;
    }
    allBits = downloadFile->size();
    httpRequestAborted = false;
    //尝试获取文件
    startRequest(downloadUrl);
    //事件循环，防止在下载没完成前结束对象
}

void MyDownloader::startRequest(QUrl url)
{
    QNetworkRequest req(url);
    if (allBits)
    {
        //QByteArray rangeHeaderValue = "bytes=" + QByteArray::number(allBits) + "-";// + QByteArray::number(already + cUpdateChunk() - 1);
        //req.setRawHeader("Range", rangeHeaderValue);
        //req.setAttribute(QNetworkRequest::HttpPipeliningAllowedAttribute, true);
        //req.setRawHeader("RANGE", tr("bytes=%1-").arg(allBits).toUtf8());//
    }
    downloadReply = downloadmanager.get(req);
    //连接信号与槽
    if (downloadReply)
    {
        connect(downloadReply, SIGNAL(readyRead()), this, SLOT(downloadReadyRead()));
        connect(downloadReply, SIGNAL(finished()), this, SLOT(downloadFinished()));
        //connect(downloadReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(downloadError(QNetworkReply::NetworkError)));
    }
}

QString MyDownloader::getDownloadVersionCode()
{
    return versionCode;
}

QString MyDownloader::getFileName()
{
    return fileName;
}

void MyDownloader::cancel()
{
    if (downloadFile)
    {
        downloadFile->close();
        delete downloadFile;
        downloadFile = NULL;
    }
    if (downloadReply)
    {
        downloadReply->deleteLater();
        downloadReply = NULL;
    }
}

void MyDownloader::output(QUrl url, QString pathtoSave)
{
    setData(url, pathtoSave);
    cancel();
    getFile();
}

void MyDownloader::create(QString path)
{
    QFile file(path);
    if ( file.exists())
    {
            return;
    }
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    file.close();

}

void MyDownloader::downloadReadyRead()
{
    //如果文件可以访问，下载
    if (downloadFile)
        downloadFile->write(downloadReply->readAll());
}

void MyDownloader::downloadFinished()
{
    if (httpRequestAborted)
    {
        cancel();
        return;
    }
    downloadFile->flush();
    downloadFile->close();

    QVariant redirectionTarget = downloadReply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (downloadReply->error())
    {

    }
    else if (!redirectionTarget.isNull())
    {
        QUrl newUrl = downloadUrl.resolved(redirectionTarget.toUrl());
        {
            downloadUrl = newUrl;
            downloadReply->deleteLater();
            downloadFile->open(QIODevice::WriteOnly);
            downloadFile->resize(0); allBits = 0;
            startRequest(downloadUrl);
            return;
        }
    }
    else
    {
        QString fileName = QFileInfo(downloadUrl.path()).fileName();
        delete downloadFile;
        downloadFile = 0;
        bisFinished = true;
        emit downloadResult(0);
    }
    downloadReply->deleteLater();
    downloadReply = 0;
    if (downloadFile)
    {
        delete downloadFile;
        downloadFile = 0;
    }
}

void MyDownloader::downloadError(QNetworkReply::NetworkError)
{
    emit downloadResult(-1);
}

void MyDownloader::downloadProgress(qint64, qint64)
{

}

