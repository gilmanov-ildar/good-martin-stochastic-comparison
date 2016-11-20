TARGET = martin-test
TEMPLATE = app

QT += core
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += main.cpp \
    Step.cpp \
    StepList.cpp \
    Session.cpp \
    SessionList.cpp

HEADERS += \
    Step.h \
    StepList.h \
    Session.h \
    SessionList.h
