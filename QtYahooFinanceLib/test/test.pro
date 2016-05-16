#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T13:25:05
#
#-------------------------------------------------

QT       -= gui

TARGET = test
TEMPLATE = lib

DEFINES += TEST_LIBRARY

SOURCES += test.cpp

HEADERS += test.h\
        test_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
