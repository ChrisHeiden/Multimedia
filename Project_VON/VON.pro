#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T21:07:50
#
#-------------------------------------------------

QT       += core gui sql\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VON
TEMPLATE = app


SOURCES += main.cpp\
           erstesfenster.cpp \
           sound.cpp \
           datenbank.cpp \
           bildersuche.cpp \
           WindowManager.cpp \
           zweitesfenster.cpp \
           farben.cpp \
    hilfe.cpp \
    drittesfenster.cpp

HEADERS  += erstesfenster.h \
            sound.h \
            datenbank.h \
            bildersuche.h \
            WindowManager.h \
            zweitesfenster.h \
            farben.h \
            hilfe.h \
            drittesfenster.h

CONFIG += c++11

RESOURCES += \
    ressourcen.qrc

TRANSLATIONS += VON_Ueberstzung_Deutsch_zu_Englisch.ts\
                VON_Deutsch.ts


