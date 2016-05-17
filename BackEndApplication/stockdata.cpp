#include "stockdata.h"
#include "QtYahooFinanceLib/QtYahooFinance/yahoofinance.h"
#include "JsonWriter/jsonwriter.h"

int idCount = 0;

namespace CoolJson
{

void jsonWrite(HistoricalStockData& hsd, std::string& jsonString, JsonWriter* parent)
{
    idCount++;
    parent->objOpen();
    parent->add("id", idCount);
    parent->add("date", hsd.date);
    parent->add("average", hsd.Average());
    parent->objClose();
}
}
