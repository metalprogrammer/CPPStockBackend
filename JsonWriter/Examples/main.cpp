#include "../jsonwriter.h"
#include <string>
#include <iostream>


struct Cat
{
    Cat(std::string n) : name(n){}
    std::string name;
};

namespace CoolJson
{
    void jsonWrite(Cat& cat, std::string& jsonString, JsonWriter* parent)
    {
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
    json.add("num", abc);

    Cat myCat{"Loki"};
    json.add("myCat",myCat);

    std::cout<<json.jsonStringGet();
    while(true)
    {

    }
}
