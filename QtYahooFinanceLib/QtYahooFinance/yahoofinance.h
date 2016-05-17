#ifndef YAHOOFINANCE_H
#define YAHOOFINANCE_H
#include <QCoreApplication>

#if defined QT_YAHOO_FINANC_LIBRARY
 #define QT_FINANC_COMMON_DLLSPEC Q_DECL_EXPORT
#else
 #define QT_FINANC_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

#include <vector>
#include <string>
#include "historicaldata.h"
#include <time.h>

enum QT_FINANC_COMMON_DLLSPEC EXCHANGE {AMERICAN_STOCK_EXCHANGE	,
                      BATS_EXCHANGE	,
                      CHICAGO_BOARD_OF_TRADE	,
                      CHICAGO_MERCANTILE_EXCHANGE	,
                      DOW_JONES_INDEXES	,
                      NASDAQ_STOCK_EXCHANGE	,
                      NEW_YORK_BOARD_OF_TRADE	,
                      NEW_YORK_COMMODITIES_EXCHANGE	,
                      NEW_YORK_MERCANTILE_EXCHANGE	,
                      NEW_YORK_STOCK_EXCHANGE	,
                      OTC_BULLETIN_BOARD_MARKET	,
                      PINK_SHEETS	,
                      S_AND_P_INDICES	,
                      BUENOS_AIRES_STOCK_EXCHANGE	,
                      VIENNA_STOCK_EXCHANGE	,
                      AUSTRALIAN_STOCK_EXCHANGE	,
                      BRUSSELS_STOCKS	,
                      BOVESPA_SAO_PAOLO_STOCK_EXCHANGE	,
                      TORONTO_STOCK_EXCHANGE	,
                      TSX_VENTURE_EXCHANGE	,
                      SANTIAGO_STOCK_EXCHANGE	,
                      SHANGHAI_STOCK_EXCHANGE	,
                      SHENZHEN_STOCK_EXCHANGE	,
                      COPENHAGEN_STOCK_EXCHANGE	,
                      EURONEXT	,
                      PARIS_STOCK_EXCHANGE	,
                      BERLIN_STOCK_EXCHANGE	,
                      BREMEN_STOCK_EXCHANGE	,
                      DUSSELDORF_STOCK_EXCHANGE	,
                      FRANKFURT_STOCK_EXCHANGE	,
                      HAMBURG_STOCK_EXCHANGE	,
                      HANOVER_STOCK_EXCHANGE	,
                      MUNICH_STOCK_EXCHANGE	,
                      STUTTGART_STOCK_EXCHANGE	,
                      XETRA_STOCK_EXCHANGE	,
                      HONG_KONG_STOCK_EXCHANGE	,
                      BOMBAY_STOCK_EXCHANGE	,
                      NATIONAL_STOCK_EXCHANGE_OF_INDIA	,
                      JAKARTA_STOCK_EXCHANGE	,
                      TEL_AVIV_STOCK_EXCHANGE	,
                      MILAN_STOCK_EXCHANGE	,
                      NIKKEI_INDICES	,
                      MEXICO_STOCK_EXCHANGE	,
                      AMSTERDAM_STOCK_EXCHANGE	,
                      NEW_ZEALAND_STOCK_EXCHANGE	,
                      OSLO_STOCK_EXCHANGE	,
                      LISBON_STOCKS	,
                      SINGAPORE_STOCK_EXCHANGE	,
                      KOREA_STOCK_EXCHANGE	,
                      KOSDAQ	,
                      BARCELONA_STOCK_EXCHANGE	,
                      BILBAO_STOCK_EXCHANGE	,
                      MADRID_FIXED_INCOME_MARKET	,
                      MADRID_SE_CATS	,
                      MADRID_STOCK_EXCHANGE	,
                      STOCKHOLM_STOCK_EXCHANGE	,
                      SWISS_EXCHANGE	,
                      TAIWAN_OTC_EXCHANGE	,
                      TAIWAN_STOCK_EXCHANGE	,
                      FTSE_INDICES	,
                      LONDON_STOCK_EXCHANGE
};

const std::string  suffixLookUp[] = {"",
                                    "",
                                    ".CBT",
                                    ".CME",
                                    "",
                                    "",
                                    ".NYB",
                                    ".CMX",
                                    ".NYM",
                                    "",
                                    ".OB",
                                    ".PK",
                                    "",
                                    ".BA",
                                    ".VI",
                                    ".AX",
                                    ".BR",
                                    ".SA",
                                    ".TO",
                                    ".V",
                                    ".SN",
                                    ".SS",
                                    ".SZ",
                                    ".CO",
                                    ".NX",
                                    ".PA",
                                    ".BE",
                                    ".BM",
                                    ".DU",
                                    ".F",
                                    ".HM",
                                    ".HA",
                                    ".MU",
                                    ".SG",
                                    ".DE",
                                    ".HK",
                                    ".BO",
                                    ".NS",
                                    ".JK",
                                    ".TA",
                                    ".MI",
                                    "",
                                    ".MX",
                                    ".AS",
                                    ".NZ",
                                    ".OL",
                                    ".LS",
                                    ".SI",
                                    ".KS",
                                    ".KQ",
                                    ".BC",
                                    ".BI",
                                    ".MF",
                                    ".MC",
                                    ".MA",
                                    ".ST",
                                    ".SW",
                                    ".TWO",
                                    ".TW",
                                    "",
                                    ".L"
};

class QT_FINANC_COMMON_DLLSPEC YahooFinance
{
public:
    YahooFinance(){}

    void historicalDataGet(std::string symbol, tm* start, tm* end, EXCHANGE exchange, std::vector<HistoricalStockData*> &result);
    std::vector<HistoricalStockData*> historicalDataGet(std::string symbol, tm* start, tm* end, EXCHANGE exchange = AMERICAN_STOCK_EXCHANGE);
};

#endif // YAHOOFINANCE_H
