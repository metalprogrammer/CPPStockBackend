#-------------------------------------------------
#
# Project created by QtCreator 2016-05-13T19:04:56
#
#-------------------------------------------------

QT       -= gui

TARGET = WebServiceApi
TEMPLATE = lib

DEFINES += WEBSERVICEAPI_LIBRARY

SOURCES += webserviceapi.cpp

HEADERS += webserviceapi.h\
        webserviceapi_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
