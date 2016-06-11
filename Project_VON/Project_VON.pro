#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T10:07:58
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project_VON
TEMPLATE = app



SOURCES += main.cpp \
           fenster.cpp \
    soundthread.cpp \
    bilderSucheThread.cpp \
    bilderausordnertherad.cpp

HEADERS  += \
    fenster.h \
    soundthread.h \
    bilderSucheThread.h \
    bilderausordnertherad.h

FORMS    +=

RESOURCES += \
    ressoucen.qrc

TRANSLATIONS   += Project_VON_en.ts \
                  Project_VON_de.ts

sourcedirs = kernel \
             tools \
             widgets

