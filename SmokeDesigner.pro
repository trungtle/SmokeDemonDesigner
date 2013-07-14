#-------------------------------------------------
#
# Project created by QtCreator 2013-05-03T09:14:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmokeDesigner
TEMPLATE = app


SOURCES += \
    SmokeHoverPoints.cpp \
    SmokeIDComponent.cpp \
    SmokeMainWindow.cpp \
    SmokeCmd.cpp \
    Main.cpp \
    SmokeGameObject.cpp \
    SmokeGameObjectComponent.cpp \
    SmokeGraphicsItem.cpp \
    SmokeGraphicsScene.cpp \
    SmokeGraphicsView.cpp \
    SmokeTransformationComponent.cpp

HEADERS  += \
    SmokeHoverPoints.h \
    SmokeIDComponent.h \
    SmokeMainWindow.h \
    SmokeCmd.h \
    SmokeGameObject.h \
    SmokeGameObjectComponent.h \
    SmokeGraphicsItem.h \
    SmokeGraphicsScene.h \
    SmokeGraphicsView.h \
    SmokeTransformationComponent.h

FORMS    += \
    main_window.ui

RESOURCES += \
    SmokeDesigner.qrc
