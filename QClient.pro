QT       += core gui
QT+=network
QT+=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administerlink.cpp \
    enterspace.cpp \
    errorscene.cpp \
    friend.cpp \
    getmoney.cpp \
    loading.cpp \
    main.cpp \
    loginscene.cpp \
    mainscene.cpp \
    mylabel.cpp \
    mypushbutton.cpp \
    searchscene.cpp \
    talking.cpp

HEADERS += \
    administerlink.h \
    enterspace.h \
    errorscene.h \
    friend.h \
    getmoney.h \
    loading.h \
    loginscene.h \
    mainscene.h \
    mylabel.h \
    mypushbutton.h \
    searchscene.h \
    talking.h

FORMS += \
    administerlink.ui \
    enterspace.ui \
    friend.ui \
    loginscene.ui \
    mainscene.ui \
    searchscene.ui \
    talking.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
