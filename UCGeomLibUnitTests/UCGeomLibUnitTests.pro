include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../UCGeomLib/include/point_utils/pointutils.h \
        tst_armadillo_tests.h \
        tst_pointutils.h \
        tst_ucgeomlib.h

SOURCES += \
        ../UCGeomLib/src/point_utils/pointutils.cpp \
        main.cpp

target.path = /usr/lib

unix:!macx: LIBS += -L$$PWD/../../../../../../../opt/intel/mkl/lib/intel64/ -lmkl_intel_lp64 -lmkl_core -lmkl_intel_thread -liomp5 -lmkl_rt

INCLUDEPATH += $$PWD/../../../../../../../opt/intel/mkl/include
DEPENDPATH += $$PWD/../../../../../../../opt/intel/mkl/include


unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -larmadillo

INCLUDEPATH += $$PWD/../../../../../usr/include/armadillo_bits
DEPENDPATH += $$PWD/../../../../../usr/include/armadillo_bits
