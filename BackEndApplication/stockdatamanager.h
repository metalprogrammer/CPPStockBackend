#ifndef STOCKDATAMANAGER_H
#define STOCKDATAMANAGER_H

#include <vector>

#include "stocklisting.h"
#include "stockdata.h"

template <typename KEY, typename VALUE>
class Cache
{
public:
    void UpdateEntry(KEY _key, VALUE _val)
    {
        int pos = PosOfKeyGet(_key);
        if(pos > -1)
        {
            enteries[pos]->val = _val;
            enteries[pos]->CacheHit++;
            OrderCache(pos);
        }
        else
        {
           enteries.push_back(new CacheEntry(_key,_val));
        }
    }

    int PosOfKeyGet(KEY _key)
    {
        for(int i = 0; i < enteries.size(); i++)
        {
            if(enteries[i]->key == _key)
            {
                return i;
            }
        }
        return -1;
    }

    bool KeyHas(KEY _key)
    {
        int pos = PosOfKeyGet(_key);

        return (pos > -1);
    }

    VALUE EntryGet(KEY _key)
    {
        int pos = PosOfKeyGet(_key);

        if(pos > -1)
        {
            enteries[pos]->CacheHit++;
            OrderCache(pos);
            return enteries[pos]->val;
        }
        else
        {
            VALUE val;
            return val;
        }
    }

private:
    struct CacheEntry
    {
        CacheEntry(KEY _key):  key(_key){}
        CacheEntry(KEY _key, VALUE _val):key(_key), val(_val){}

        KEY key;
        VALUE val;
        int CacheHit{1};
    };


    void OrderCache(int currentModifiedEntry)
    {
        if(currentModifiedEntry != 0)
        {
            if (enteries[currentModifiedEntry]->CacheHit  > enteries[currentModifiedEntry - 1]->CacheHit )
            {
                std::swap(enteries[currentModifiedEntry - 1], enteries[currentModifiedEntry]);
            }
        }
    }

    std::vector<CacheEntry*> enteries;

};

class StockDataManager
{
public:
    StockDataManager();

    std::string StockListJsonGet(std::string search);
    std::string StockDataJsonGet(std::string symbol);
    std::vector<StockListing*>* SymbolSearch(std::string _searchSymbol);

private:
    std::vector<StockListing*> stockList;
    Cache<std::string, std::vector<StockListing*>*> cache;

};

#endif // STOCKDATAMANAGER_H
