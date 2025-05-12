/********************************************************************************
** Form generated from reading UI file 'member_interface_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBER_INTERFACE_PAGE_H
#define UI_MEMBER_INTERFACE_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_User_Interface_Page
{
public:
    QFrame *frame;
    QLabel *number_of_overdue;
    QLabel *number_of_borrowed;
    QLabel *label_3;
    QLabel *welcome_label;
    QLabel *label;
    QPushButton *borrow_book;
    QLabel *number_of_books;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *welcomeback;

    void setupUi(QDialog *User_Interface_Page)
    {
        if (User_Interface_Page->objectName().isEmpty())
            User_Interface_Page->setObjectName("User_Interface_Page");
        User_Interface_Page->resize(814, 581);
        User_Interface_Page->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        frame = new QFrame(User_Interface_Page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, 40, 851, 491));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:transparent;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"QLabel {\n"
"    font-family: \"Segoe UI\";       /* Or any font you like */\n"
"    font-size: 16px;               /* Adjust size as needed */\n"
"    font-weight: bold;             /* This makes it bold */\n"
"    color: white;                  /* Optional: sets text color */\n"
"}\n"
"QLineEdit {\n"
"    color: #FFFFFF;  /* White text color */\n"
"    background: transparent;\n"
"    border: none;\n"
"    border-bottom: 2px solid white;\n"
"    padding: 2px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-bottom: 2px solid #FFD700; /* gold underline when focused */\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        number_of_overdue = new QLabel(frame);
        number_of_overdue->setObjectName("number_of_overdue");
        number_of_overdue->setGeometry(QRect(240, 430, 21, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        number_of_overdue->setFont(font);
        number_of_overdue->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        number_of_borrowed = new QLabel(frame);
        number_of_borrowed->setObjectName("number_of_borrowed");
        number_of_borrowed->setGeometry(QRect(240, 300, 21, 61));
        number_of_borrowed->setFont(font);
        number_of_borrowed->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 370, 341, 61));
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        welcome_label = new QLabel(frame);
        welcome_label->setObjectName("welcome_label");
        welcome_label->setGeometry(QRect(360, 0, 171, 71));
        welcome_label->setFont(font);
        welcome_label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        welcome_label->setIndent(10);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 120, 341, 61));
        label->setFont(font);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        borrow_book = new QPushButton(frame);
        borrow_book->setObjectName("borrow_book");
        borrow_book->setGeometry(QRect(590, 270, 151, 41));
        borrow_book->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        number_of_books = new QLabel(frame);
        number_of_books->setObjectName("number_of_books");
        number_of_books->setGeometry(QRect(240, 180, 21, 61));
        number_of_books->setFont(font);
        number_of_books->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(180, 240, 341, 61));
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 130, 221, 361));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(0,0,0,200);\n"
"}"));
        welcomeback = new QLabel(frame);
        welcomeback->setObjectName("welcomeback");
        welcomeback->setGeometry(QRect(-80, 0, 991, 71));
        welcomeback->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(98, 60, 59, .50);\n"
"}"));
        welcomeback->raise();
        label_2->raise();
        number_of_overdue->raise();
        number_of_borrowed->raise();
        label_3->raise();
        welcome_label->raise();
        label->raise();
        borrow_book->raise();
        number_of_books->raise();
        label_5->raise();

        retranslateUi(User_Interface_Page);

        QMetaObject::connectSlotsByName(User_Interface_Page);
    } // setupUi

    void retranslateUi(QDialog *User_Interface_Page)
    {
        User_Interface_Page->setWindowTitle(QCoreApplication::translate("User_Interface_Page", "Dialog", nullptr));
        number_of_overdue->setText(QCoreApplication::translate("User_Interface_Page", "0", nullptr));
        number_of_borrowed->setText(QCoreApplication::translate("User_Interface_Page", "0", nullptr));
        label_3->setText(QCoreApplication::translate("User_Interface_Page", "Overdue Books", nullptr));
        welcome_label->setText(QCoreApplication::translate("User_Interface_Page", "Welcome User", nullptr));
        label->setText(QCoreApplication::translate("User_Interface_Page", "Total Number of Books", nullptr));
        borrow_book->setText(QCoreApplication::translate("User_Interface_Page", "Borrow/Return Book", nullptr));
        number_of_books->setText(QCoreApplication::translate("User_Interface_Page", "0", nullptr));
        label_5->setText(QCoreApplication::translate("User_Interface_Page", "Borrowed Books", nullptr));
        label_2->setText(QString());
        welcomeback->setText(QCoreApplication::translate("User_Interface_Page", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_Interface_Page: public Ui_User_Interface_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBER_INTERFACE_PAGE_H
