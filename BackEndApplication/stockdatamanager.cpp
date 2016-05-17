#include "stockdatamanager.h"
#include "QtYahooFinanceLib/QtYahooFinance/yahoofinance.h"
#include "JsonWriter/jsonwriter.h"

StockDataManager::StockDataManager()
{
    readFile("file",stockList);
}

std::string StockDataManager::StockListJsonGet()
{
    CoolJson::JsonWriter jw;

    jw.writeJSONWebFormatArray("stockList","listofstocks",stockList, "stocks");

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

    CoolJson::JsonWriter jw;
    jw.writeNameLabel(std::string("historicaldatas"));
    jw.objOpen();
    jw.add(std::string("name"), symbol);

    jw.writeJSONWebFormatArray(symbol, "listofdata",data,"stockdatas");

    return jw.jsonStringGet();

}

