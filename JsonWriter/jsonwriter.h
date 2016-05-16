#ifndef JSONWRITER_H
#define JSONWRITER_H

#include <string>
#include <vector>

namespace CoolJson
{
class JsonWriter;

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

void jsonWrite(bool val, std::string& jsonString, JsonWriter* parent )
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


class JsonWriter
{
public:
    JsonWriter()
    {
        clear();
    }

    std::string jsonStringGet()
    {
        return jsonString;
    }

    void clear()
    {
        jsonString = "";
    }

    template<typename T>
    void add(std::string name, T t)
    {
        if(jsonString != "")
        {
            jsonString += ",";
        }

        writeNameLabel(name);

        addHelper(t);

    }

    template<typename T>
    void addArray(std::string name, std::vector<T> list)
    {
        addArrayHelper(name, list, list.size());
    }


private:
    std::string jsonString;

    template<typename T>
    void addHelper(T t)
    {
       jsonWrite(t, jsonString, this);
    }

    template<typename T>
    void addArrayHelper(std::string name, T list, int size)
    {
        if(jsonString != "")
        {
            jsonString += ",";
        }

        jsonString += "[";

        for(int i = 0; i < size; i++)
        {
            //add()

            addHelper(list[i]);

            if(i + 1 < size)
            {
                jsonString += ",";
            }
        }

        jsonString += "]";
    }

    void writeNameLabel(std::string& name )
    {
        jsonString += "\"" + name + "\":";
    }

};


}

#endif // JSONWRITER_H
