# CPP Stock Backend

A Backend C++ program for getting and formatting stock data for a front end.

## Features

* Serach for stocks
* Cache Searches
* Send Graph Data

## Installation
After cloning this project run the following in (parent)/CPPStockBackend
	git submodule init 
	git submodule update 
This will get all the files for qhttpserver. 
	
You will also need to install QT and QtCreator (optional but will simplify building). You can start downloading [here](https://www.qt.io/download-open-source/).

	
## Structure
The program uses several internal libs
BackendApplication<br>
*The main application
*Depends on all other folders
*Contains stock listings parsed from csv files
*Fetches stock data
*Searches for stock listing based on search terms
*Caches Search Results

JsonWriter<br>
*A small lib to for writing json
*Closed princpal: new objects can be serialised without modification to the object or json code.
*Just override one method

MiscHelpers
*A small file containing several helper functions

qhttpserver
* A qt based c++ webservice lib by [nikhilm](https://github.com/nikhilm)

QTHttpGet
* A small helper function for getting the results of http get requests for a given url

QtWebServiceApi
* A wrapper around qhttpserver
* Requires Qt but wraps around qhttpserver and abstracts away qt princpals
* Allows using it with C++ princpals only
* Easily use http headers for CORS

QtYahooFinanceLib
* Depends on QTHttpGet
* Gets data for a given stock from yahoo finance api.

##Building
The easiest way to build is:
*Open QtCreator and open the .pro file.
*Build->Run Qmake
*Build->Build All

Then you can Run BackEndApplication. 
The app will serve requests on http://localhost:8080


