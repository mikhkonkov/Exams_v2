#-------------------------------------------------
#
# Project created by QtCreator 2012-08-26T17:39:09
#
#-------------------------------------------------

QT       += core xml xmlpatterns

TARGET = Serializators
TEMPLATE = app

CONFIG += console

SOURCES += \
    main.cpp \
    abstractserializator.cpp \
    examstestserializator.cpp \
    fieldschecker.cpp \
    reviewedtestserializator.cpp \
    pluginconfigserializator.cpp

HEADERS  += \
    serializators.h \
    abstractserializator.h \
    examstestserializator.h \
    fieldschecker.h \
    reviewedtestserializator.h \
    pluginconfigserializator.h

RESOURCES += \
    serializators.qrc

# Подключаем классы данных

SOURCES += \
    ../DataClasses/reviewedtesttask.cpp \
    ../DataClasses/testtask.cpp \
    ../DataClasses/examstest.cpp \
    ../DataClasses/exception.cpp \
    ../DataClasses/reviewedtest.cpp \
    ../DataClasses/abstracttest.cpp \
    ../DataClasses/abstracttesttask.cpp \
    ../Plugins/plugininfo.cpp

HEADERS  +=  \
    ../DataClasses/reviewedtesttask.h \
    ../DataClasses/dataclasses.h \
    ../DataClasses/testtask.h \
    ../DataClasses/examstest.h \
    ../DataClasses/exception.h \
    ../DataClasses/reviewedtest.h \
    ../DataClasses/abstracttest.h \
    ../DataClasses/abstracttesttask.h \
    ../Plugins/plugininfo.h







