#-------------------------------------------------
#
# Project created by QtCreator 2014-05-19T11:34:38
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Bridge
CONFIG   += console
CONFIG   -= app_bundle
CONFIG 	 += embed_manifest_exe

TEMPLATE = app

INCLUDEPATH += C:/Development/boost/boost_1_55_0/

LIBS += -LC:/Development/boost/boost_1_55_0/stage/lib

SOURCES += main.cpp \
    extensions/motordriver.cpp


HEADERS += \
    extensions/serialbase.h \
    extensions/motordriver.h

