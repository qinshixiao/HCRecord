#-------------------------------------------------
#
# Project created by QtCreator 2015-08-05T08:28:08
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HCRecord
TEMPLATE = app


SOURCES += main.cpp\
        maininterface.cpp \
    addinfo.cpp \
    detailedinfo.cpp

HEADERS  += maininterface.h \
    CreateDatebase.h \
    addinfo.h \
    detailedinfo.h

RESOURCES += \
    images.qrc
