#ifndef STOCKDATAMANAGER_H
#define STOCKDATAMANAGER_H

#include <vector>

#include "stocklisting.h"
#include "stockdata.h"

template <typename KEY, typename VALUE, int SIZE>
class Cache
{
    struct CacheEntry
    {
        CacheEntry(VALUE _val):  val(_val){}
        CacheEntry(KEY _key, VALUE _val):key(_key), val(_val){}
        KEY key;
        VALUE val;
        int CacheHit{1};
    };
};

class StockDataManager
{
public:
    StockDataManager();

    std::string StockListJsonGet(std::string search);
    std::string StockDataJsonGet(std::string symbol);
    std::vector<StockListing*> search(std::string symbol);

private:
    std::vector<StockListing*> stockList;

};

#endif // STOCKDATAMANAGER_H
