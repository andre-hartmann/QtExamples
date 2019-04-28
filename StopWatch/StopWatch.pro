QT = core gui widgets

TARGET = StopWatch
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        stopwatchtimer.cpp

HEADERS += \
        mainwindow.h \
        stopwatchtimer.h

FORMS += \
        mainwindow.ui
