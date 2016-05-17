QT += core
QT += network
QT -= gui

CONFIG += c++11

LIBS += -L../lib/
win32 {
    debug: LIBS += -lWebServiced
    else: LIBS += -lWebService
} else {
    LIBS += -lWebService
}



TARGET = WebServiceExample
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += ../../qhttpserver/src/



TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += ../WebService
