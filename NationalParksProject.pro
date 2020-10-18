QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    adminscreen.cpp \
    customer.cpp \
    databasesetup.cpp \
    main.cpp \
    mainwindow.cpp \
    nationalparks.cpp \
    parks.cpp \
    parksdisplay.cpp

HEADERS += \
    adminlogin.h \
    adminscreen.h \
    customer.h \
    databasesetup.h \
    mainwindow.h \
    nationalparks.h \
    parks.h \
    parksdisplay.h

FORMS += \
    adminlogin.ui \
    adminscreen.ui \
    mainwindow.ui \
    parksdisplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
