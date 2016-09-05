#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T14:33:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DebuggerDetector
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    debuggerdetectorinterface.cpp \
    debuggerdetectorwin.cpp \
    debuggerdetectorunix.cpp

HEADERS  += mainwindow.h \
    debuggerdetectorinterface.h \
    debuggerdetectorwin.h \
    debuggerdetectorunix.h

FORMS    += mainwindow.ui
