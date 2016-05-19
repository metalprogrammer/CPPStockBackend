# CPP Stock Backend

A C++ webservice api and a wrapper to qhttpserver abstracting away many qt concepts and allows quick building of the service.

## Features
* A wrapper around qhttpserver
* Requires Qt but wraps around qhttpserver and abstracts away qt princpals
* Allows using it with C++ princpals only
* Easily use http headers for CORS

## Usage
First you need a callback function to use when the Webservice is recives a  Http request. The function headers:
 std::string func(std::vector<std::string> list). List is a list of string formed from the http request seperated by the char "/". Using C++11 the function can be a member funciton and be bound to an instance.<br>
 
The return of the function is the text that is written out in the http response.
Currently all services run on port 8080.

##Example
	#include <QCoreApplication>
	#include "webservice.h"
	#include <string>
	#include <vector>

	std::string func(std::vector<std::string> list)
	{
		std::string output = "Args: ";
		foreach( std::string str, list)
		{
			output += str + ", ";
		}

		return output;
	}

	int main(int argc, char **argv)
	{
		QCoreApplication app(argc, argv);
		WebService hello(func);
		app.exec();
	}

