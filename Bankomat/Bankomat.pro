#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T17:00:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bankomat
TEMPLATE = app

win32:RC_ICONS += Ikona.ico

SOURCES += main.cpp\
        widget.cpp \
    crdzen.cpp \
    ckarta.cpp \
    ckonto.cpp \
    ckasetapieniedzy.cpp \
    cwyplacacz.cpp \
    widgetoprogramie.cpp \
    widgetdodajpieniadze.cpp \
    widgetdodajkonto.cpp \
    widgetokno.cpp \
    cprzycisk.cpp

HEADERS  += widget.h \
    crdzen.h \
    ckarta.h \
    ckonto.h \
    ckasetapieniedzy.h \
    cwyplacacz.h \
    widgetoprogramie.h \
    widgetdodajpieniadze.h \
    widgetdodajkonto.h \
    widgetokno.h \
    cprzycisk.h

FORMS    += widget.ui \
    widgetoprogramie.ui \
    widgetdodajpieniadze.ui \
    widgetdodajkonto.ui

RESOURCES += \
    obrazy.qrc
