#pragma once
#ifndef UTILTIESHELPERS_H
#define UTILTIESHELPERS_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

#include "time.h"

/*
 * A file using commonly needed helper functions and classes
 */

/*
 * Creates a copy of the string in all caps
 */
static std::string CapString(std::string org)
{
    std::string cpy = org;
    for (auto & c: cpy)
    {
        c = toupper(c);
    }

    return cpy;
}

/*
 * Split as string and  insert the data into the passed in vector reference
 * Passing in a vector reference eases memory management over creating a new
 * heap allocated vector and is faster then returnign a vector.
 */
static void split(const std::string &s, char delim, std::vector<std::string> &data)
{
    std::stringstream stringStream(s);
    std::string element;
    while (std::getline(stringStream, element, delim)) {
        data.push_back(element);
    }
}


/*
 * Add days to C time structs
 */
static tm* addDays(time_t t,int days)
{
    tm* tmStruct = localtime(&t);
    tmStruct->tm_mday += days;
    tmStruct->tm_isdst = -1;
    std::cout<<"date:"<<tmStruct->tm_mday<<std::endl;
    mktime(tmStruct);
    std::cout<<"date:"<<tmStruct->tm_mday<<std::endl;
    return tmStruct;
}

/*
 * Add days to C time structs
 */
static tm addDays(tm* t,int days)
{
    tm temp = *t;
    temp.tm_mday += days;
    temp.tm_isdst = -1;
    std::cout<<"date:"<<temp.tm_mday<<std::endl;
    mktime(&temp);
    std::cout<<"date:"<<temp.tm_mday<<std::endl;
    return temp;
}

/*
 * Helper class for reading a csv File
 */
class CsvReader
{
public:
    CsvReader() {}

    CsvReader(std::string fileName)
    {
        open(fileName);
    }

    bool open (std::string fileName)
    {
        file.open(fileName);
        if (file.is_open())
        {
            hasReadFirstLine = false;
            readNextLine(header);
            std::cout<<"open"<<std::endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool readNextLine(std::vector<std::string>& parts)
    {
        if(std::getline(file, line))
        {
            parts.clear();
            split(line,',', parts);
            return true;
        }
        return false;
    }

    void close()
    {
        file.close();
    }

private:
    std::ifstream file;
    std::vector<std::string> header;
    bool hasReadFirstLine{false};
    std::string line;
};

#endif // UTILTIESHELPERS_H
