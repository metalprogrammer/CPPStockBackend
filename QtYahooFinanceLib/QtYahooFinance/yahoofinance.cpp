#include "yahoofinance.h"
#include "QTHttpGet/qthttpgetheaderonly.h"
#include <iostream>
#include "MiscHelpers/utiltieshelpers.h"


void YahooFinance::historicalDataGet(std::string symbol, tm* start, tm* end, EXCHANGE exchange, std::vector<HistoricalStockData*> &result)
{
    std::cout<<"starturl"<<std::endl;
    std::string baseUrl = std::string("http://ichart.finance.yahoo.com/table.csv?s=") + symbol + suffixLookUp[exchange];
    baseUrl += std::string("&a=")  + std::to_string(start->tm_mon);
    baseUrl += std::string("&b=")  + std::to_string(start->tm_mday);
    baseUrl += std::string("&c=")  + std::to_string(start->tm_year + 1900);
    baseUrl += std::string("&d=")  + std::to_string(end->tm_mon);
    baseUrl += std::string("&e=")  + std::to_string(end->tm_mday);
    baseUrl += std::string("&f=")  + std::to_string(end->tm_year + 1900);

    std::string csvResult = httpGet(baseUrl);
    std::cout<<"url:"<<baseUrl<<std::endl;
    std::cout<<"results:"<<csvResult<<std::endl;

    std::stringstream stringStream(csvResult);
    std::string element;
    bool firstElement = false;
    while (std::getline(stringStream, element))
    {
        if(!firstElement)
        {
            firstElement = true;
            continue;
        }
        std::vector<std::string> parts;
        split(element,',', parts);

        HistoricalStockData* stock = new HistoricalStockData();

        if(parts.size() >= 1)
        {
            stock->date = parts[0];

            if(parts.size() >= 2)
            {
                stock->open = std::stod(parts[1]);

                if(parts.size() >= 3)
                {
                    stock->high = std::stod(parts[2]);

                    if(parts.size() >= 4)
                    {
                        stock->low = std::stod(parts[3]);
                    }

                    if(parts.size() >= 5)
                    {
                        stock->close = std::stod(parts[4]);
                        std::cout<<"end"<<std::endl;
                    }
                }
            }
        }

        result.push_back(stock);
    }
}

std::vector<HistoricalStockData*> YahooFinance::historicalDataGet(std::string symbol, tm *start, tm *end,  EXCHANGE exchange)
{
    std::vector<HistoricalStockData*> temp;
    return temp;
}
