#ifndef STOCKDATAMANAGER_H
#define STOCKDATAMANAGER_H

#include <vector>

#include "stocklisting.h"
#include "stockdata.h"

class StockDataManager
{
public:
    StockDataManager();

    std::string StockListJsonGet();
    std::string StockDataJsonGet(std::string symbol);

private:
    std::vector<StockListing*> stockList;

};

#endif // STOCKDATAMANAGER_H
