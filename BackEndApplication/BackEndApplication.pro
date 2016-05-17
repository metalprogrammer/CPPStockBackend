QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = BackEndApplication
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../
INCLUDEPATH += ../qhttpserver/src/

LIBS += -L../QtYahooFinanceLib/lib/ -lQtYahooFinance
LIBS += -L../QtWebServiceApi/lib/   -lWebService

SOURCES += main.cpp \
    stocklisting.cpp \
    stockdatamanager.cpp \
    stockdata.cpp \
    ../JsonWriter/jsonwriter.cpp

HEADERS += \
    stocklisting.h \
    stockdata.h \
    stockdatamanager.h \
    service.h
