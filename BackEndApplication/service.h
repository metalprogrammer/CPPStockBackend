#ifndef SERVICE_H
#define SERVICE_H

#include <functional>
#include <vector>
#include <iostream>

#include "stockdatamanager.h"
#include "QtWebServiceApi/WebService/webservice.h"

template<typename T>
void print(T t)
{
    std::cout<<t<<std::endl;
}

int Launch(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StockDataManager sdm;


    auto response = [&sdm](std::vector<std::string>& list)
    {
       std::cout<<"arg list"<<std::endl;
       foreach( std::string str, list)
       {
           std::cout<<str<<std::endl;
       }
       std::cout<<"arg end"<<std::endl;

        if(list[1] == "stocklistings")
        {
            return sdm.StockListJsonGet();
        }
        if(list[1] == "historicaldata")
        {
            std::cout<<"historical"<<std::endl;
            if(list.size() >= 3)
            {
                std::cout<<sdm.StockDataJsonGet(list[2])<<std::endl;
                return sdm.StockDataJsonGet(list[2]);
            }
            return std::string("");
        }


        return std::string("");
    };


    WebService ws(response);
    ws.EnableCors("http://localhost:4200");

    return a.exec();
}

#endif // SERVICE_H
