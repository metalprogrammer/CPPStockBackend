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

    print("a");

    auto response = [&sdm](std::vector<std::string> list)
    {
        /*
         * std::string output = "Args: ";
            foreach( std::string str, list)
            {
                output += str + ", ";
            }

            return output;
            */
        return sdm.StockListJsonGet();
    };


    WebService ws(response);
    ws.EnableCors("http://localhost:4200");

    return a.exec();
}

#endif // SERVICE_H
