#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T13:40:32
#
#-------------------------------------------------

QT += network

greaterThan(QT_MAJOR_VERSION, 4)

TARGET = QtYahooFinance
TEMPLATE = lib


SOURCES += \
    yahoofinance.cpp \

DEFINES += QT_YAHOO_FINANC_LIBRARY

INCLUDEPATH += ../../

HEADERS  += \
    historicaldata.h \
    yahoofinance.h \
    utiltieshelpers.h

CONFIG += lib

unix {
    target.path = /usr/lib
    INSTALLS += target
}

