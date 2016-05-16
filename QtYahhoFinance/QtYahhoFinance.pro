#-------------------------------------------------
#
# Project created by QtCreator 2016-05-13T19:03:09
#
#-------------------------------------------------

QT       -= gui

TARGET = QtYahhoFinance
TEMPLATE = lib

DEFINES += QTYAHHOFINANCE_LIBRARY

SOURCES += qtyahhofinance.cpp \
    yahoofinance.cpp

HEADERS += qtyahhofinance.h\
        qtyahhofinance_global.h \
    historicaldata.h \
    yahoofinance.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
