#-------------------------------------------------
#
# Project created by QtCreator 2014-07-02T19:41:03
#
#-------------------------------------------------

QT       += core gui

TARGET = LevelEditor
TEMPLATE = app

LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += main.cpp\
        mainwindow.cpp \
    SFMLCanvas.cpp \
    MyCanvas.cpp

HEADERS  += mainwindow.h \
    SFMLCanvas.h \
    MyCanvas.h

FORMS    += mainwindow.ui
