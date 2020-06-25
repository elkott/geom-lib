#-------------------------------------------------
#
# Project created by QtCreator 2020-06-17T21:39:32
#
#-------------------------------------------------

QT       -= core gui

TARGET = UCGeomLib
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/point_utils/pointutils.cpp \
        ucgeomlib.cpp

HEADERS += \
        include/point_utils/pointutils.h \
        include/preambles.h \
        ucgeomlib.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
