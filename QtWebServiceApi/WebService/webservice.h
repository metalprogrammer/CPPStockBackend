#ifndef WEBSERVICE_H
#define WEBSERVICE_H

#include "qhttpserver.h"

#include <QObject>
#include <vector>
#include <functional>
#include <string>
#include <vector>

/*
 * QTWebServiceApi
 * by Christopher Glynn Pelech, 2016
 * A simple webservervice libary for QT C++
 */

//Define Lib consts
#if defined WEBSERVICE_LIBRARY
 #define QT_WEB_SERVICE_API Q_DECL_EXPORT
#else
 #define QT_WEB_SERVICE_API Q_DECL_IMPORT
#endif

class QT_WEB_SERVICE_API WebService: public QObject
{
    Q_OBJECT
    typedef std::function<std::string (std::vector<std::string>&)> ServerFunction;

public:
    WebService(ServerFunction sf);
    void EnableCors(std::string site);

private:
    ServerFunction serverFunction;
    std::vector<std::string> crossSites;

private slots:
    void handleRequest(QHttpRequest *req, QHttpResponse *resp);



};

#endif // WEBSERVICE_H
