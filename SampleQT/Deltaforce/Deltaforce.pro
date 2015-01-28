#-------------------------------------------------
#
# Project created by QtCreator 2014-04-23T08:51:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Deltaforce
TEMPLATE = app


SOURCES += main.cpp\
        deltaforce.cpp \
    ../Regwin/regwin.cpp

HEADERS  += deltaforce.h \
    ../Regwin/regwin.h \
    funcs.h

FORMS    += deltaforce.ui \
    ../Regwin/regwin.ui

RESOURCES += \
    imagecomposition.qrc

SUBDIRS += \
    ../Regwin/Regwin.pro

INCLUDEPATH +=C:/Users/User/Desktop/boost_1_54_0/

win32: LIBS +=

win32:RC_FILE += myapp.rc

OTHER_FILES +=

win32: LIBS += C:/Users/User/Desktop/launchers/launchers/Tekken/libs.a
