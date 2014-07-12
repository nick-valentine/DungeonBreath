#-------------------------------------------------
#
# Project created by QtCreator 2014-07-04T12:10:00
#
#-------------------------------------------------

QT       += core gui

CONFIG += static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LevelEditor
TEMPLATE = app

#on linux comment out with #
INCLUDEPATH = C:\Qt\Qt5.3.1\Tools\mingw482_32\include

LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += main.cpp\
        toolswindow.cpp \
    tileboard.cpp \
    actorboard.cpp

HEADERS  += toolswindow.h \
    tileboard.h \
    actorboard.h

FORMS    += toolswindow.ui
