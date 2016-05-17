#ifndef CAT_H
#define CAT_H

#include "jsonwriter.h"

struct Cat
{
    Cat(std::string n) : name(n){}
    std::string name;
};

namespace CoolJson
{
    void jsonWrite(Cat& cat, std::string& jsonString, JsonWriter* parent);
}

#endif // CAT_H
