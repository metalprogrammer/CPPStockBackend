#include "stockdatamanager.h"
#include "QtYahooFinanceLib/QtYahooFinance/yahoofinance.h"
#include "JsonWriter/jsonwriter.h"

StockDataManager::StockDataManager()
{
    readFile("companylist1.csv",stockList);
    readFile("companylist2.csv",stockList);
    readFile("companylist3.csv",stockList);
}

std::vector<StockListing *> *StockDataManager::SymbolSearch(std::string symbol )
{
    std::cout<<"searach"<<std::endl;

    if(cache.KeyHas(symbol))
    {
        std::cout<<"cache hit"<<std::endl;
        return cache.EntryGet(symbol);
    }
    else
    {
       std::vector<StockListing *>* temp = new std::vector<StockListing*>();
        std::cout<<"cache miss"<<symbol<<std::endl;

       for(int i = 0; i < stockList.size(); i++)
       {
           if(stockList[i]->name.find(symbol) != std::string::npos)
           {
               std::cout<<"match"<<std::endl;
               temp->push_back(stockList[i]);
           }
       }
       cache.UpdateEntry(symbol,temp);
       return temp;
    }
}

std::string StockDataManager::StockListJsonGet(std::string search)
{
    JsonWriter jw;

    jw.writeNameLabel("stocklisting");
    jw.objOpen();
    jw.OverideNextCommaRule();
    jw.add("id", search);

    std::vector<StockListing*>* searchResult = SymbolSearch(search);

    jw.writeCommaAsNeeded();
    jw.writeNameLabel("listofstocks");

    jw.BracketOpen();
    for(int i = 0; i < searchResult->size(); i++)
    {
        std::cout<<"as"<<std::endl;
        jw.addHelper(searchResult->at(i)->myId);
        if(i + 1 != searchResult->size())
        {
            jw.writeCommaAsNeeded();
        }

    }
    jw.BracketClose();

    jw.objClose();

    jw.addArrayPointer("stocks",*searchResult);


    std::cout<<"done"<<std::endl;
    return jw.jsonStringGet();
}


std::string StockDataManager::StockDataJsonGet(std::string symbol)
{
    YahooFinance yf;

    time_t  timeNow = time(0);
    tm* tmNow = localtime(&timeNow);
    tm tmPast = addDays(tmNow, -30);

    std::vector<HistoricalStockData*> data;

    yf.historicalDataGet(symbol,&tmPast, tmNow,AMERICAN_STOCK_EXCHANGE, data);

    JsonWriter jw;
    jw.writeNameLabel(std::string("historicaldatas"));
    jw.objOpen();
    jw.OverideNextCommaRule();
    jw.add(std::string("id"), symbol);
    jw.add(std::string("name"), symbol);

    jw.writeIDArray("listofdata", data.size());
    jw.objClose();

    resetIdCount();

    jw.addArrayPointer("stockdatas",data);

    return jw.jsonStringGet();

}

