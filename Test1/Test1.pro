#-------------------------------------------------
#
# Project created by QtCreator 2012-05-28T00:53:21
#
#-------------------------------------------------

QT       += testlib network sql svg webkit phonon gui

TARGET = tst_test1test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_test1test.cpp \
 ../zip.cpp \
    ../mainwindow.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
   ../zip.h \
    ../mainwindow.h
