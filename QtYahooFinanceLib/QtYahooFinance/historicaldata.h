#ifndef HISTORICALDATA_H
#define HISTORICALDATA_H
#include <string>

struct HistoricalStockData
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
