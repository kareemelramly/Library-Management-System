/********************************************************************************
** Form generated from reading UI file 'borrow_return_book.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROW_RETURN_BOOK_H
#define UI_BORROW_RETURN_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_borrow_return_book
{
public:
    QFrame *frame;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *borrow_book_button;
    QLabel *label_5;
    QListView *book_list;
    QPushButton *pushButton;
    QLabel *fines_money;
    QLabel *labelback;
    QPushButton *return_book_button;
    QComboBox *borrowed_books_combo_box;

    void setupUi(QDialog *borrow_return_book)
    {
        if (borrow_return_book->objectName().isEmpty())
            borrow_return_book->setObjectName("borrow_return_book");
        borrow_return_book->resize(811, 571);
        borrow_return_book->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        frame = new QFrame(borrow_return_book);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, -70, 711, 631));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:transparent;\n"
"}\n"
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
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(570, 250, 131, 21));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 70, 491, 571));
        borrow_book_button = new QPushButton(groupBox);
        borrow_book_button->setObjectName("borrow_book_button");
        borrow_book_button->setGeometry(QRect(200, 510, 93, 29));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 30, 131, 41));
        book_list = new QListView(groupBox);
        book_list->setObjectName("book_list");
        book_list->setGeometry(QRect(20, 70, 441, 431));
        book_list->setStyleSheet(QString::fromUtf8("QListView{\n"
"background:rgba(255, 255,255, .8);\n"
"}"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 83, 29));
        fines_money = new QLabel(frame);
        fines_money->setObjectName("fines_money");
        fines_money->setGeometry(QRect(610, 300, 31, 20));
        labelback = new QLabel(frame);
        labelback->setObjectName("labelback");
        labelback->setGeometry(QRect(550, 230, 131, 121));
        labelback->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(0,0,0,200);\n"
"}"));
        return_book_button = new QPushButton(frame);
        return_book_button->setObjectName("return_book_button");
        return_book_button->setGeometry(QRect(570, 480, 93, 29));
        borrowed_books_combo_box = new QComboBox(frame);
        borrowed_books_combo_box->setObjectName("borrowed_books_combo_box");
        borrowed_books_combo_box->setGeometry(QRect(530, 420, 161, 21));
        labelback->raise();
        label->raise();
        groupBox->raise();
        fines_money->raise();
        return_book_button->raise();
        borrowed_books_combo_box->raise();

        retranslateUi(borrow_return_book);

        QMetaObject::connectSlotsByName(borrow_return_book);
    } // setupUi

    void retranslateUi(QDialog *borrow_return_book)
    {
        borrow_return_book->setWindowTitle(QCoreApplication::translate("borrow_return_book", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("borrow_return_book", "Total Fines", nullptr));
        groupBox->setTitle(QCoreApplication::translate("borrow_return_book", "GroupBox", nullptr));
        borrow_book_button->setText(QCoreApplication::translate("borrow_return_book", "Borrow Book", nullptr));
        label_5->setText(QCoreApplication::translate("borrow_return_book", "List of Books", nullptr));
        pushButton->setText(QCoreApplication::translate("borrow_return_book", "Back", nullptr));
        fines_money->setText(QCoreApplication::translate("borrow_return_book", "0", nullptr));
        labelback->setText(QString());
        return_book_button->setText(QCoreApplication::translate("borrow_return_book", "Return Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class borrow_return_book: public Ui_borrow_return_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_RETURN_BOOK_H
