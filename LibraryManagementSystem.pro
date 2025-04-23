QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminpage.cpp \
    librarian.cpp \
    librarian.cpp \
    librarymember.cpp \
    main.cpp \
    mainwindow.cpp \
    member.cpp \
    utils.cpp

HEADERS += \
    admin.h \
    adminpage.h \
    librarian.h \
    librarian.h \
    librarymember.h \
    mainwindow.h \
    member.h \
    utils.h

FORMS+= \
    adminpage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
