#-------------------------------------------------
#
# Project created by QtCreator 2013-05-03T09:14:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmokeDesigner
TEMPLATE = app


SOURCES += main.cpp \
    smokesceneview.cpp \
    mainwindow.cpp \
    smokecmd.cpp \
    smokegameobject.cpp \
    spinboxdelegate.cpp

HEADERS  += \
    smokesceneview.h \
    mainwindow.h \
    smokecmd.h \
    smokegameobject.h \
    spinboxdelegate.h

FORMS    += \
    main_window.ui

RESOURCES += \
    SmokeDesigner.qrc
