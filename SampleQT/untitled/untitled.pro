#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T14:28:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    childwin.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    childwin.h

FORMS    += \
    childwin.ui

RESOURCES += \
    imagecomposition.qrc
