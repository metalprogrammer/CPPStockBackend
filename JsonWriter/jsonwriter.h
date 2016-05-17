#ifndef JSONWRITER_H
#define JSONWRITER_H

#include <string>
#include <vector>

namespace CoolJson
{
class JsonWriter;

void jsonWrite(std::string& str, std::string& jsonString, JsonWriter* parent);

void jsonWrite(double val, std::string& jsonString, JsonWriter* parent );

void jsonWrite(int val, std::string& jsonString, JsonWriter* parent );

void jsonWrite(float val, std::string& jsonString, JsonWriter* parent );

void jsonWrite(bool val, std::string& jsonString, JsonWriter* parent );


class JsonWriter
{
public:
    JsonWriter()
    {
        clear();
    }

    std::string jsonStringGet()
    {
        return "{" + jsonString + "}";
    }

    void clear()
    {
        jsonString = "";
    }

    template<typename T,typename STRING_TYPE>
    void add(STRING_TYPE name, T t)
    {
        if(jsonString != "")
        {
            jsonString += ",";
        }

        writeNameLabel(std::string(name));

        addHelper(t);

    }

    void objOpen()
    {
        jsonString += "{";
    }

    void objClose()
    {
        jsonString += "}";
    }

    template<typename T,typename STRING_TYPE>
    void addArray(STRING_TYPE name, std::vector<T> list)
    {
        addArrayHelper(std::string(name), list, list.size());
    }

    template<typename T,typename STRING_TYPE>
    void writeJSONWebFormatArray(STRING_TYPE name, std::vector<T>& list, STRING_TYPE dataListName)
    {
        if(jsonString != "")
        {
            jsonString += ",";
        }

        writeNameLabel(std::string(name));

        jsonString += "[";

        for(int i = 0; i < list.size(); i++)
        {
            jsonString += std::to_string(i + 1);

            if( i + 1 != list.size())
            {
                jsonString += ",";
            }
        }

        jsonString += "]";

        objClose();
        addArray(std::string(dataListName), list);
    }

    template<typename T,typename STRING_TYPE>
    void writeJSONWebFormatArray(STRING_TYPE id, STRING_TYPE name, std::vector<T>& list, STRING_TYPE dataListName)
    {
        objOpen();
        add(std::string("id"), id);
        writeJSONWebFormatArray(name,list,dataListName);
    }




    void writeNameLabel(std::string& name )
    {
        jsonString += "\"" + name + "\":";
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

};


}

#endif // JSONWRITER_H
