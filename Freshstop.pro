#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T21:02:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Freshstop
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    freshstop.cpp \
    pricelist.cpp \
    csvreader.cpp

HEADERS  += login.h \
    freshstop.h \
    pricelist.h \
    csvreader.h

FORMS    += login.ui \
    freshstop.ui \
    pricelist.ui \
    csvreader.ui

RESOURCES += \
    files.qrc

OTHER_FILES += \
    CaltexFreshStopLogo-480x236.jpg

RC_FILE = Freshstop.rc
