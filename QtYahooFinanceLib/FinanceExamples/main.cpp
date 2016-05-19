#ifndef MAIN_H
#define MAIN_H

#include <QCoreApplication>

#include "QtYahooFinanceLib/QtYahooFinance/yahoofinance.h"
#include <iostream>
#include "time.h"
#include "MiscHelpers/utiltieshelpers.h"


int main(int argc, char *argv[])
{
    std::cout<<"start"<<std::endl;
    QCoreApplication a(argc, argv);
    YahooFinance yf;

    time_t  timeNow = time(0);
    tm* tmNow = localtime(&timeNow);
    tm tmPast = addDays(tmNow, -30);


    std::vector<HistoricalStockData*> data;

    yf.historicalDataGet("GOOG",&tmPast, tmNow,FTSE_INDICES, data);

    while(true)
    {

    }

    return 0;
}

#endif // MAIN_H
