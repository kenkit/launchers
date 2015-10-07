#-------------------------------------------------
#
# Project created by QtCreator 2014-05-20T11:22:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Android_Unlocker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \


HEADERS  += mainwindow.h \
    ../../../rapidxml-1.13/rapidxml.hpp \
    ../../../rapidxml-1.13/rapidxml_iterators.hpp \
    ../../../rapidxml-1.13/rapidxml_print.hpp \
    ../../../rapidxml-1.13/rapidxml_utils.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    imagecomposition.qrc

OTHER_FILES += \
    myapp.rc
win32: LIBS +=

INCLUDEPATH += \
    ../../../
