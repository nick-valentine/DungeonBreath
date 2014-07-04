#-------------------------------------------------
#
# Project created by QtCreator 2014-07-04T12:10:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LevelEditor
TEMPLATE = app

LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += main.cpp\
        toolswindow.cpp \
    tileboard.cpp

HEADERS  += toolswindow.h \
    tileboard.h

FORMS    += toolswindow.ui
