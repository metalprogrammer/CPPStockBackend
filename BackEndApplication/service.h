#ifndef SERVICE_H
#define SERVICE_H

#include <functional>
#include <vector>

#include "stockdatamanager.h"
#include "QtWebServiceApi/WebService/webservice.h"


int Launch(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StockDataManager sdm;

    auto response = [](std::vector<std::string> list)
    {
        std::string output = "Args: ";
            foreach( std::string str, list)
            {
                output += str + ", ";
            }

            return output;
    };


    WebService ws(response);


    return a.exec();
}

#endif // SERVICE_H
