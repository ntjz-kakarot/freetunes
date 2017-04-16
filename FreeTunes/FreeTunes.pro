#-------------------------------------------------
#
# Project created by QtCreator 2015-07-09T12:47:28
#
#-------------------------------------------------

QT       += core gui network webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

TARGET = FreeTunes
TEMPLATE = app


SOURCES += main.cpp\
        player.cpp \
    web.cpp \
    track.cpp

HEADERS  += player.h \
    web.h \
    track.h

FORMS    += player.ui
