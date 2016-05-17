#include "stockdata.h"
#include "QtYahooFinanceLib/QtYahooFinance/yahoofinance.h"
#include "JsonWriter/jsonwriter.h"

int idCount = 0;

void resetIdCount()
{
    idCount = 0;
}

void jsonWrite(HistoricalStockData& hsd, std::string& jsonString, JsonWriter* parent)
{
    idCount++;
    parent->objOpen();
    parent->OverideNextCommaRule();
    parent->add("id", idCount);
    parent->add("date", hsd.date);
    parent->add("average", hsd.Average());
    parent->objClose();
}


void jsonWrite(HistoricalStockData* hsd, std::string& jsonString, JsonWriter* parent)
{
    jsonWrite(*hsd,jsonString,parent);
}

