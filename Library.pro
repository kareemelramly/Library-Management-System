QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_dashbord.cpp \
    book_records.cpp \
    borrow_return_book.cpp \
    librarian_interface_page.cpp \
    login.cpp \
    main.cpp \
    member_interface_page.cpp

HEADERS += \
    admin_dashbord.h \
    book_records.h \
    borrow_return_book.h \
    librarian_interface_page.h \
    login.h \
    member_interface_page.h

FORMS += \
    add_edit_book.ui \
    admin_dashbord.ui \
    book_records.ui \
    borrow_return_book.ui \
    librarian_interface_page.ui \
    login.ui \
    member_interface_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
