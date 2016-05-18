#include "stockdatamanager.h"
#include "QtYahooFinanceLib/QtYahooFinance/yahoofinance.h"
#include "JsonWriter/jsonwriter.h"

StockDataManager::StockDataManager()
{
    readFile("companylist1.csv",stockList);
    readFile("companylist2.csv",stockList);
    readFile("companylist3.csv",stockList);
}

std::vector<StockListing*> StockDataManager::search(std::string symbol )
{

}

std::string StockDataManager::StockListJsonGet(std::string search)
{
    JsonWriter jw;

    jw.writeNameLabel("stocklisting");
    jw.objOpen();
    jw.OverideNextCommaRule();
    jw.add("id", search);

    std::vector<StockListing*>* searchResult = search(symbol);




    jw.writeIDArray("listofstocks", searchResult.size());
    jw.objClose();

    jw.addArrayPointer("stocks",searchResult);
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

