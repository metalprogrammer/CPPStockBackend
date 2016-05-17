#ifndef STOCKDATA_H
#define STOCKDATA_H
#include "JsonWriter/jsonwriter.h"
#include "QtYahooFinanceLib/QtYahooFinance/yahoofinance.h"


namespace CoolJson
{
void jsonWrite(HistoricalStockData& hsd, std::string& jsonString, JsonWriter* parent);
}


#endif // STOCKDATA_H
