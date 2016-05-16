QT += core
QT -= gui

CONFIG += c++11

TARGET = WebService
CONFIG += console
CONFIG -= app_bundle

QT += network

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    ../qthttpgetheaderonly.h

