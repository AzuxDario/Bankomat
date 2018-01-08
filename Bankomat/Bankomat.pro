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

include(Widgets/Widgets.pri)
include(WidgetsProviders/WidgetsProviders.pri)
include(Account/Account.pri)
include(Controls/Controls.pri)
include(CashMachine/CashMachine.pri)
include(Layout/Layout.pri)
include(Const/Const.pri)

SOURCES += main.cpp
	
HEADERS  +=
	
FORMS    +=

RESOURCES += \
    obrazy.qrc
