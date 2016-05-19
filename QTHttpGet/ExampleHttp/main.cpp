#include <QCoreApplication>
#include "../qthttpgetheaderonly.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string result = httpGet("http://download.finance.yahoo.com/d/quotes.csv?s=AAPL+GOOG+MSFT&f=nabm/");
    std::cout<<result<<std::endl;
    return a.exec();
}
