QT += core
QT -= gui

CONFIG += c++11

TARGET = FinanceExamples
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../ \
    ../../

SOURCES += main.cpp


LIBS += -L../lib/ -lQtYahooFinance
