#-------------------------------------------------
#
# Project created by QtCreator 2015-07-04T21:01:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Image_viewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    openfile.cpp \
    painter.cpp

HEADERS  += mainwindow.h \
    openfile.h \
    painter.h

FORMS    += mainwindow.ui \
    openfile.ui
