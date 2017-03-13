#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T14:52:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = my_flag
TEMPLATE = app

desktops.path = /usr/share/applications
desktops.files = *.desktop
INSTALLS += desktops


SOURCES += main.cpp\
        my_flag.cpp

HEADERS  += my_flag.h

FORMS    += my_flag.ui
