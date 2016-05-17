include(../QtYahooFinanceLib.pri)

QFINANCE = ..
QT += network
TEMPLATE = lib


DEFINES += QT_YAHOO_FINANC_LIBRARY

INCLUDEPATH += ../../

HEADERS  += \
    historicaldata.h \
    yahoofinance.h \
    utiltieshelpers.h
SOURCES += \
    yahoofinance.cpp \

TARGET = QtYahooFinance

!win32:VERSION = 0.1.0

CONFIG += dll debug_and_release

CONFIG(debug, debug|release) {
    win32: TARGET = $$join(TARGET,,,d)
}


OBJECTS_DIR = $$QFINANCE/build
MOC_DIR = $$QFINANCE/build
DESTDIR = $$QFINANCE/lib

target.path = $$LIBDIR
headers.path = $$INCLUDEDIR
headers.files = $$PUBLIC_HEADERS
INSTALLS += target headers


