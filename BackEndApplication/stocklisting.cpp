#include "stocklisting.h"
#include "JsonWriter/jsonwriter.h"

int StockListing::id = 0;

StockListing::StockListing(std::string name_, std::string sym_):
    name(name_), sym(sym_)
{
    id++;
    myId = id;
}



void readFile(std::string file, std::vector<StockListing*>& list)
{
    CsvReader reader(file);

    std::vector<std::string> parts;
    while(reader.readNextLine(parts))
    {
        std::string symbol = parts[0];
        std::string name = parts[1];

        StockListing* temp = new StockListing(name, symbol);
        list.push_back(temp);
    }

}
namespace CoolJson
{
void jsonWrite(StockListing& s, std::string& jsonString, JsonWriter* parent)
{
    parent->objOpen();
    parent->add("id", s.myId);
    parent->add(std::string("name"), s.name);
    parent->add("symbol", s.sym);
    parent->objClose();
}
}




