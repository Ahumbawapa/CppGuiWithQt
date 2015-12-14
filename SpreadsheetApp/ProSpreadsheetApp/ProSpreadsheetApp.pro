#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T14:01:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProSpreadsheetApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gotocelldialog.cpp \
    finddialog.cpp \
    sortdialog.cpp

HEADERS  += mainwindow.h \
    finddialog.h \
    gotocelldialog.h \
    sortdialog.h

FORMS += \
    gotocelldialog.ui \
    sortdialog.ui

RESOURCES += \
    spreadsheet.qrc

DISTFILES +=
