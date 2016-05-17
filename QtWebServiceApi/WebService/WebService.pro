#-------------------------------------------------
#
# Project created by QtCreator 2016-05-16T16:10:18
#
#-------------------------------------------------

QT += network
QT       -= gui

TARGET = WebService
TEMPLATE = lib

DEFINES += WEBSERVICE_LIBRARY


unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    webservice.h

SOURCES += \
    webservice.cpp

INCLUDEPATH += ../../qhttpserver/src/

LIBS += -L../../qhttpserver/lib -lqhttpserver

!win32:VERSION = 0.1.0

CONFIG += dll debug_and_release

CONFIG(debug, debug|release) {
    win32: TARGET = $$join(TARGET,,,d)
}


OBJECTS_DIR = ../build
MOC_DIR = ../build
DESTDIR = ../lib

target.path = $$LIBDIR
headers.path = $$INCLUDEDIR
headers.files = $$PUBLIC_HEADERS
INSTALLS += target headers
