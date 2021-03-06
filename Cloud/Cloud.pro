#-------------------------------------------------
#
# Project created by QtCreator 2019-02-04T19:01:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cloud
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
        login_signup.cpp \
    search_page.cpp\
    account.cpp \
    uploadpage.cpp\
    loading.cpp \
    homepage.cpp \
    notifications_page.cpp \
    user_page.cpp \
    friends.cpp \
    controller.cpp

HEADERS += \
        login_signup.h \
    search_page.h\
    uploadpage.h\
    account.h \
    loading.h \
    homepage.h \
    notifications_page.h \
    user_page.h \
    friends.h \
    controller.h

FORMS += \
        login_signup.ui \
    search_page.ui\
    loading.ui \
    uploadpage.ui\
    homepage.ui \
    notifications_page.ui \
    user_page.ui \
    friends.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
