# CPP Stock Backend

Simple C++ function for getting the result of a http request

## Example
	#include <QCoreApplication>
	#include "../qthttpgetheaderonly.h"
	#include <iostream>
	#include <QTcpSocket>
	#include <string>


	int main(int argc, char *argv[])
	{
		QTcpSocket *socket;
		QCoreApplication a(argc, argv);
		std::string url = "http://download.finance.yahoo.com/d/quotes.csv?s=AAPL+GOOG+MSFT&f=nabm/";
		std::string result = httpGet(url);
		std::cout<<result<<std::endl;
		return a.exec();
	}
