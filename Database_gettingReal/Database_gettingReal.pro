#-------------------------------------------------
#
# Project created by QtCreator 2016-06-04T22:21:06
#
#-------------------------------------------------

QT       += core gui sql testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Database_gettingReal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datenbank.cpp \
    datenbanktest.cpp

HEADERS  += mainwindow.h \
    datenbank.h \
    datenbanktest.h
