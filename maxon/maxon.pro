QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ForceSensor/ForceSensor.cpp \
    MaxonMotor.cpp \
    functioncustom.cpp \
    main.cpp \
    mainwindow.cpp \
    omega.cpp \
    omega/OmegaFunction.cpp

HEADERS += \
    ForceSensor/ForceSensor.h \
    MaxonMotor.h \
    functioncustom.h \
    mainwindow.h \
    omega.h \
    omega/OmegaFunction.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    maxon.qrc

DISTFILES +=

win32: LIBS += -L$$PWD/maxondll/ -lEposCmd

INCLUDEPATH += $$PWD/maxondll
DEPENDPATH += $$PWD/maxondll

win32: LIBS += -L$$PWD/maxondll/ -lEposCmd64

INCLUDEPATH += $$PWD/maxondll
DEPENDPATH += $$PWD/maxondll

FORMS += \
    omega.ui

win32:LIBS += -L$$PWD/omegadll/lib/ -ldhdms64
win32: LIBS += -L$$PWD/omegadll/lib/ -ldrdms64

INCLUDEPATH += $$PWD/omegadll/include
DEPENDPATH += $$PWD/omegadll/include

win32: LIBS += -L$$PWD/modbusdll/lib/ -lmodbus

INCLUDEPATH += $$PWD/modbusdll/include
DEPENDPATH += $$PWD/modbusdll/include
