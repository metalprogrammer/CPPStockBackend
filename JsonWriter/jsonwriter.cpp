#include <string>
#include <vector>
#include "jsonwriter.h"
#include <iostream>



void jsonWrite(std::string& str, std::string& jsonString, JsonWriter* parent)
{
    //A nice feature to add would to escape any quotes within str
    jsonString += "\"" + str + "\"";
}

void jsonWrite(double val, std::string& jsonString, JsonWriter* parent )
{
    jsonString += std::to_string(val);
}

void jsonWrite(int val, std::string& jsonString, JsonWriter* parent )
{
    jsonString += std::to_string(val);
}

void jsonWrite(float val, std::string& jsonString, JsonWriter* parent )
{
    jsonString += std::to_string(val);
}

/*
void jsonWrite(bool val, std::string& jsonString, JsonWriter* parent )
{
    std::string tof = "";
    if(val)
    {
        tof = "true";
    }w
    else
    {
        tof = "false";
    }
    jsonString += tof;
}
*/

