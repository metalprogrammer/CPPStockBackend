#include <string>
#include <iostream>

#include "jsonwriter.h"
#include "cat.h"


namespace CoolJson
{
    void jsonWrite(Cat& cat, std::string& jsonString, JsonWriter* parent)
    {
        parent->add("name", 3);
        parent->add("name", cat.name);
    }
}

int main(int argc, char *argv[])
{
    /*
    Cat myCat{"Loki"};
    CoolJson::JsonWriter json;
    json.add("myCat",myCat);
    */

    CoolJson::JsonWriter json;
    std::string abc = "abc";
    json.add(std::string("num"), abc);

    Cat myCat{"Loki"};
    json.add(std::string("myCat"),myCat);

    std::cout<<json.jsonStringGet();
    while(true)
    {

    }
}
