QT += core
QT -= gui

CONFIG += c++11

TARGET = Examples
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += ../jsonwriter.cpp
SOURCES += main.cpp

INCLUDEPATH += ../

HEADERS += \
    cat.h
