# CPP Stock Backend

A simple C++ lib for writing to json. 

## Features
*A small lib to for writing json
*Closed princpal: new objects can be serialised without modification to the object or json code.
*Easily write objects, even if they are from 3rd party libs
*Just override one method

## How To use
To write a new type of object override  
void jsonWrite(T, std::string&, JsonWriter*); Where T is the new type.<\br>
To add a element to a jsonWrite use add. Use JsonStringGet() to get the actual json string.

##Example 
	#include <string>
	#include <iostream>

	#include "jsonwriter.h"
	struct Cat
	{
		Cat(std::string n) : name(n){}
		std::string name;
	};

	void jsonWrite(Cat& cat, std::string& jsonString, JsonWriter* parent)
	{
		parent->add("name", 3);
		parent->add("name", cat.name);
	}

	int main(int argc, char *argv[])
	{

		JsonWriter json;
		std::string abc = "abc";
		json.add(std::string("num"), abc);

		Cat myCat{"Loki"};
		json.add(std::string("myCat"),myCat);
		std::cout<<json.jsonStringGet()<<std::endl;

	}
