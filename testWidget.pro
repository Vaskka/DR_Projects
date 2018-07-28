#-------------------------------------------------
#
# Project created by QtCreator 2018-07-27T09:49:04
#
#-------------------------------------------------

QT       += core gui widgets
LIBS += -lmysqlclient

TARGET = testWidget
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mymainwindow.cpp \
    user.cpp \
    utils.cpp \
    base_database.cpp \
    queryset.cpp \
    executer.cpp \
    executer_filter.cpp \
    selectexecuter.cpp \
    insertexecuter.cpp \
    updateexecuter.cpp \
    deleteexecuter.cpp \
    logindialog.cpp \
    warrantsearchdialog.cpp \
    warrantinsertdialog.cpp \
    casesearchdialog.cpp \
    claimsearchdialog.cpp \
    compensatesearchdialog.cpp \
    incsearchdialog.cpp

HEADERS += \
        mainwindow.h \
    mymainwindow.h \
    user.h \
    base_database.h \
    queryset.h \
    executer.h \
    executer_filter.h \
    selectexecuter.h \
    insertexecuter.h \
    updateexecuter.h \
    deleteexecuter.h \
    logindialog.h \
    warrantsearchdialog.h \
    warrantinsertdialog.h \
    casesearchdialog.h \
    claimsearchdialog.h \
    compensatesearchdialog.h \
    incsearchdialog.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    warrantsearchdialog.ui \
    warrantinsertdialog.ui \
    casesearchdialog.ui \
    claimsearchdialog.ui \
    compensatesearchdialog.ui \
    incsearchdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
