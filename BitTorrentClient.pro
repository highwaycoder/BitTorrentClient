#-------------------------------------------------
#
# Project created by QtCreator 2015-03-09T19:14:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BitTorrentClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addtorrentwindow.cpp \
    appconfig.cpp \
    torrent.cpp

HEADERS  += mainwindow.h \
    addtorrentwindow.h \
    appconfig.h \
    torrent.h

FORMS    += mainwindow.ui \
    addtorrentwindow.ui

DISTFILES += \
    config.json
