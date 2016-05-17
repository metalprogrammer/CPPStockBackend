#pragma once
#ifndef UTILTIESHELPERS_H
#define UTILTIESHELPERS_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

#include "time.h"

static void split(const std::string &s, char delim, std::vector<std::string> &data)
{
    std::stringstream stringStream(s);
    std::string element;
    while (std::getline(stringStream, element, delim)) {
        data.push_back(element);
    }
}

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
