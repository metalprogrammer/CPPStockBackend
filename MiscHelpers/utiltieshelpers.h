#ifndef UTILTIESHELPERS_H
#define UTILTIESHELPERS_H

#include <string>
#include <sstream>
#include "time.h"

void split(const std::string &s, char delim, std::vector<std::string> &data)
{
    std::stringstream stringStream(s);
    std::string element;
    while (std::getline(stringStream, element, delim)) {
        data.push_back(element);
    }
}

tm* addDays(time_t t,int days)
{
    tm* tmStruct = localtime(&t);
    tmStruct->tm_mday += days;
    tmStruct->tm_isdst = -1;
    std::cout<<"date:"<<tmStruct->tm_mday<<std::endl;
    mktime(tmStruct);
    std::cout<<"date:"<<tmStruct->tm_mday<<std::endl;
    return tmStruct;
}

tm addDays(tm* t,int days)
{
    tm temp = *t;
    temp.tm_mday += days;
    temp.tm_isdst = -1;
    std::cout<<"date:"<<temp.tm_mday<<std::endl;
    mktime(&temp);
    std::cout<<"date:"<<temp.tm_mday<<std::endl;
    return temp;
}



#endif // UTILTIESHELPERS_H
