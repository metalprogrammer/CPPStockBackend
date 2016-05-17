#include <string>
#include <vector>
#include "jsonwriter.h"


void CoolJson::jsonWrite(std::string& str, std::string& jsonString, JsonWriter* parent)
{
    //A nice feature to add would to escape any quotes within str

    jsonString += "\"" + str + "\"";
}

void CoolJson::jsonWrite(double val, std::string& jsonString, JsonWriter* parent )
{
    jsonString += std::to_string(val);
}

void CoolJson::jsonWrite(int val, std::string& jsonString, JsonWriter* parent )
{
    jsonString += std::to_string(val);
}

void CoolJson::jsonWrite(float val, std::string& jsonString, JsonWriter* parent )
{
    jsonString += std::to_string(val);
}

void CoolJson::jsonWrite(bool val, std::string& jsonString, JsonWriter* parent )
{
    std::string tof = "";
    if(val)
    {
        tof = "true";
    }
    else
    {
        tof = "false";
    }
    jsonString += tof;
}

