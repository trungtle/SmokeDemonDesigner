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
    mainwindow.cpp \
    smokecmd.cpp \
    smokegameobject.cpp \
    smokegraphicsview.cpp \
    smokegraphicsitem.cpp \
    smokegameobjectcomponent.cpp \
    smokegraphicsscene.cpp \
    smoketransformationcomponent.cpp

HEADERS  += \
    mainwindow.h \
    smokecmd.h \
    smokegameobject.h \
    smokegraphicsview.h \
    smokegraphicsitem.h \
    smokegameobjectcomponent.h \
    smokegraphicsscene.h \
    smoketransformationcomponent.h

FORMS    += \
    main_window.ui

RESOURCES += \
    SmokeDesigner.qrc
