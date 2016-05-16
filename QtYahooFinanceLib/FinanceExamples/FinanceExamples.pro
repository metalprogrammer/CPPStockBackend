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



win32:CONFIG(release, debug|release): LIBS += -L../../../backend/QtYahooFinanceLib/QtYahooFinance/release -lQtYahooFinance
else:win32:CONFIG(debug, debug|release): LIBS += -L../../../backend/QtYahooFinanceLib/QtYahooFinance/debug/ -lQtYahooFinance
else:unix: LIBS += -L$$OUT_PWD/../QtYahooFinance/ -lQtYahooFinance
