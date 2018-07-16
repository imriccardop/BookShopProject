#-------------------------------------------------
#
# Project created by QtCreator 2017-08-18T10:23:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BookShopProject
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
            View/mainwindow.cpp\
            Model/book.cpp \
            Model/booklist.cpp \
            Model/userstandard.cpp \
            Model/useradvanced.cpp \
            Model/useradmin.cpp \
            Model/userlist.cpp \
            Model/user.cpp \
            View/loginwindow.cpp \
            View/accountuserwindow.cpp \
            View/bookwindow.cpp \
            View/adminwindow.cpp \
            View/accountwindow.cpp


HEADERS  += View/mainwindow.h\
            Model/book.h \
            Model/booklist.h \
            Model/userstandard.h \
            Model/useradvanced.h \
            Model/useradmin.h \
            Model/userlist.h \
            Model/user.h \
            View/loginwindow.h \
            View/accountuserwindow.h \
            View/bookwindow.h \
            View/adminwindow.h \
            View/accountwindow.h

FORMS    += mainwindow.ui \
            loginwindow.ui \
            accountuserwindow.ui \
            bookwindow.ui \
            adminwindow.ui \
            accountwindow.ui
