QT += core
QT -= gui

CONFIG += c++11

TARGET = BackEndApplication
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += "C:\Users\Chris Glynn Pelech\Documents\QTProjects\QTWebLibary\trunk\src"
LIBS += -LC:\BackendLibs\lib

win32 {
    debug: LIBS += -lqhttpserverd
    else: LIBS += -lqhttpserver
} else {
    LIBS += -lqhttpserver
}

SOURCES += main.cpp
