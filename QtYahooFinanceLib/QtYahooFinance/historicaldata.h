#ifndef HISTORICALDATA_H
#define HISTORICALDATA_H
#include <string>
#include "yahoofinance.h"

struct QT_FINANC_COMMON_DLLSPEC HistoricalStockData
{
    std::string date;
    double open;
    double high;
    double close;
    double low;

    double Average()
    {
        return (open + high + close + low)/4;
    }
};

#endif // HISTORICALDATA_H
