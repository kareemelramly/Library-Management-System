QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_dashbord.cpp \
    book_records.cpp \
    borrow_return_book.cpp \
    librarian.cpp \
    librarian_interface_page.cpp \
    library_member.cpp \
    login.cpp \
    main.cpp \
    member.cpp \
    member_interface_page.cpp \
    utils.cpp

HEADERS += \
    admin.h \
    admin_dashbord.h \
    book_records.h \
    borrow_return_book.h \
    librarian.h \
    librarian_interface_page.h \
    library_member.h \
    login.h \
    member.h \
    member_interface_page.h \
    utils.h

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

RESOURCES += \
    Resources.qrc
