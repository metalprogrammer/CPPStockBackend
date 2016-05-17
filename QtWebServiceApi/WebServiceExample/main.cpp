#include <QCoreApplication>
#include "webservice.h"
#include <string>
#include <vector>

std::string func(std::vector<std::string> list)
{
    std::string output = "Args: ";
    foreach( std::string str, list)
    {
        output += str + ", ";
    }

    return output;
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    WebService hello(func);
    app.exec();
}
