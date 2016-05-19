QT += core
QT -= gui

CONFIG += c++11

TARGET = FinanceExamples
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../

SOURCES += main.cpp


LIBS += -L../lib/
win32 {
    debug: LIBS += -lQtYahooFinanced
    else: LIBS += -lQtYahooFinance
} else {
    LIBS += -lQtYahooFinance
}
