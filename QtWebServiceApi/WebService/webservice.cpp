#include "webservice.h"
#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>
#include <iostream>

WebService::WebService(ServerFunction sf) : serverFunction(sf)
{
    QHttpServer *server = new QHttpServer(this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));

    server->listen(QHostAddress::Any, 8080);
}

void WebService::EnableCors(std::string site)
{
    WebService::crossSites.push_back(site);
}

void WebService::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
    std::cout<<"We are handling a connection"<<std::endl;

    /*
    Access-Control-Allow-Origin: http://foo.example
    Access-Control-Allow-Methods: POST, GET, OPTIONS
    Access-Control-Allow-Headers: X-PINGOTHER
    Access-Control-Max-Age: 1728000
    */


    if(crossSites.size() > 0)
    {
        resp->setHeader("Access-Control-Allow-Credentials", "true");
        for(int i = 0; i < crossSites.size(); i ++)
        {
            //resp->setHeader("Access-Control-Allow-Origin", "http://localhost:4200");
            resp->setHeader("Access-Control-Allow-Origin", QString::fromStdString(crossSites[0]));
        }
    }

    resp->setHeader("Content-Type", "text/html");
    resp->writeHead(200);


    std::vector<std::string> list;

    foreach( QString str, req->path().split("/")) {
      list.push_back(str.toStdString());
    }

    QString body = QString::fromStdString(serverFunction(list));
    resp->end(body.toUtf8());

    //resp->end(req->path().toUtf8());
}
