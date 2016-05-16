#ifndef QTHTTPGETHEADERONLY_H
#define QTHTTPGETHEADERONLY_H

#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <string>

std::string httpGet(std::string url)
{
    // create custom temporary event loop on stack
        QEventLoop eventLoop;

        // "quit()" the event-loop, when the network request "finished()"
        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        // the HTTP request
        QNetworkRequest req( QUrl( QString::fromStdString(url) ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

    QString result = "";

    if (reply->error() == QNetworkReply::NoError)
    {
        result = reply->readAll();
    }
    else
    {
        result = "Failure: " + reply->errorString();
    }
    delete reply;
    return result.toStdString();
}


#endif // QTHTTPGETHEADERONLY_H
