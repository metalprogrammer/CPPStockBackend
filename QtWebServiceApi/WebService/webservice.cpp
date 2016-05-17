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

void WebService::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
    std::cout<<"We are handling a connection"<<std::endl;

    resp->setHeader("Content-Type", "text/html");
    resp->writeHead(200);


    std::vector<std::string> list;

    foreach( QString str, req->path().split("/")) {
      list.push_back(str.toStdString());
    }

    QString body = QString::fromStdString(serverFunction(list));
    resp->end(body.toUtf8());

    std::cout<<"Connection Handled"<<std::endl;
    std::cout<<body.arg(req->path()).toStdString()<<std::endl;
    //resp->end(req->path().toUtf8());
}
