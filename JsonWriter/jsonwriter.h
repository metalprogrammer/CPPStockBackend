#ifndef JSONWRITER_H
#define JSONWRITER_H

#include <string>
#include <vector>

/*
 * A simple Json writer
 * By Christopher Glynn Pelech, 2016
 * This is a simple two file C++ libary for JSON writing.
 * The guiding princple for the project is Closed software.  Adding a new type to be written is easy.
 * There is no extending of the JsonWriter or the class required. Simply override the method jsonWrite
 * jsonWrite for the apporiate type.
 * The full prototype is:
 * void jsonWrite(T, std::string&, JsonWriter*);
 * Where type T is your method.
 */

//Forward Dec of the JsonWriter Class;
class JsonWriter;

//Method Declaration of several primitive types
//Declared here so JsonWriter know that there is a method called jsonWrite
void jsonWrite(std::string& str, std::string& jsonString, JsonWriter* parent);

void jsonWrite(double val, std::string& jsonString, JsonWriter* parent );

void jsonWrite(int val, std::string& jsonString, JsonWriter* parent );

void jsonWrite(float val, std::string& jsonString, JsonWriter* parent );

//void jsonWrite(bool val, std::string& jsonString, JsonWriter* parent );


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
        writeCommaAsNeeded();

        writeNameLabel(std::string(name));

        addHelper<T>(t);

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
    void addArrayPointer(STRING_TYPE name, std::vector<T*> list)
    {
        writeCommaAsNeeded();

        writeNameLabel(name);
        jsonString += "[";
        for(int i = 0; i < list.size(); i++)
        {
            addHelper(*list[i]);
            if(i + 1 != list.size())
            {
                jsonString += ",";
            }
        }

        jsonString += "]";
        //addArrayHelper(std::string(name), list, list.size());
    }




    void writeIDArray(std::string name, int count)
    {
        writeCommaAsNeeded();

        writeNameLabel(std::string(name));

        jsonString += "[";

        for(int i = 0; i < count; i++)
        {
            jsonString += std::to_string(i + 1);

            if(i + 1 != count)
            {
                jsonString += ",";
            }
        }

        jsonString += "]";
    }


    template<typename STRING_TYPE>
    void writeNameLabel(STRING_TYPE& name )
    {
        jsonString += "\"" + std::string(name) + "\":";
    }

    void OverideNextCommaRule()
    {
        overrideNextCommaRule = true;
    }

    /*
     * Writes a "["
     */
    void BracketOpen()
    {
        jsonString += "[";
    }

    /*
     * Writes a "]"
     */
    void BracketClose()
    {
        jsonString += "]";
    }

    /*
     * Writes just the json type, doesn't write name labels
     */
    template<typename T>
    void addHelper(T t)
    {
       jsonWrite(static_cast<T>(t), jsonString, this);
    }

    //Write a comma if it is an apporiate time
    void writeCommaAsNeeded()
    {
        if(jsonString != "" && !overrideNextCommaRule)
        {
            jsonString += ",";
        }
        overrideNextCommaRule = false;
    }

private:
    std::string jsonString;



    template<typename T>
    void addArrayHelper(std::string name, T list, int size)
    {
       writeCommaAsNeeded();

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

    bool overrideNextCommaRule{false};

};


#endif // JSONWRITER_H
