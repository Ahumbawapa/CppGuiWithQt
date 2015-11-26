#-------------------------------------------------
#
# Project created by QtCreator 2015-11-23T15:12:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpreadSheet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    finddialog.cpp \
    gotocelldialog.cpp \
    sortdialog.cpp

HEADERS  += mainwindow.h \
    finddialog.h \
    gotocelldialog.h \
    sortdialog.h

FORMS    += \
    gotocelldialog.ui \
    sortdialog.ui

RESOURCES += \
    spreadsheet.qrc
