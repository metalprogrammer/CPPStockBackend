#ifndef STOCKLISTING_H
#define STOCKLISTING_H


#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "MiscHelpers/utiltieshelpers.h"
#include "JsonWriter/jsonwriter.h"

struct StockListing
{
    StockListing(std::string name_, std::string sym_);

    int myId;
    std::string name;
    std::string sym;

private:
    static int id;

};



namespace CoolJson
{
    void jsonWrite(StockListing& s, std::string& jsonString, JsonWriter* parent);
    //void jsonWrite(StockListing* s, std::string& jsonString, JsonWriter* parent);
}


void readFile(std::string file, std::vector<StockListing*>& list);


#endif // STOCKLISTING_H
