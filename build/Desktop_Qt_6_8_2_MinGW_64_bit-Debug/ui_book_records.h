/********************************************************************************
** Form generated from reading UI file 'book_records.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_RECORDS_H
#define UI_BOOK_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_book_records
{
public:
    QGroupBox *groupBox;
    QLabel *label_5;
    QTableWidget *booksList;
    QPushButton *backButton;
    QFrame *frame;
    QLabel *label;
    QPushButton *edit_book_button;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *search_button;
    QPushButton *add_book_button;
    QPushButton *delete_book_button;
    QFontComboBox *functionality_2;
    QFontComboBox *functionality;
    QLineEdit *searchName;

    void setupUi(QDialog *book_records)
    {
        if (book_records->objectName().isEmpty())
            book_records->setObjectName("book_records");
        book_records->resize(814, 585);
        book_records->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        groupBox = new QGroupBox(book_records);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 0, 491, 571));
        groupBox->setStyleSheet(QString::fromUtf8("#groupbox{color:white;}"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 30, 131, 41));
        label_5->setStyleSheet(QString::fromUtf8("#label_5{color:white}"));
        booksList = new QTableWidget(groupBox);
        booksList->setObjectName("booksList");
        booksList->setGeometry(QRect(10, 80, 491, 421));
        QFont font;
        font.setPointSize(9);
        booksList->setFont(font);
        backButton = new QPushButton(groupBox);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 10, 83, 29));
        frame = new QFrame(book_records);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(530, 40, 301, 471));
        frame->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"background:rgba(0,0,0,200);\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 91, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        edit_book_button = new QPushButton(frame);
        edit_book_button->setObjectName("edit_book_button");
        edit_book_button->setGeometry(QRect(130, 420, 93, 29));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 350, 91, 20));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 240, 201, 20));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        search_button = new QPushButton(frame);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(80, 160, 93, 29));
        add_book_button = new QPushButton(frame);
        add_book_button->setObjectName("add_book_button");
        add_book_button->setGeometry(QRect(80, 300, 93, 29));
        delete_book_button = new QPushButton(frame);
        delete_book_button->setObjectName("delete_book_button");
        delete_book_button->setGeometry(QRect(30, 420, 93, 29));
        functionality_2 = new QFontComboBox(frame);
        functionality_2->setObjectName("functionality_2");
        functionality_2->setGeometry(QRect(20, 380, 221, 26));
        functionality = new QFontComboBox(frame);
        functionality->setObjectName("functionality");
        functionality->setGeometry(QRect(20, 80, 221, 26));
        searchName = new QLineEdit(frame);
        searchName->setObjectName("searchName");
        searchName->setGeometry(QRect(20, 120, 221, 28));

        retranslateUi(book_records);

        QMetaObject::connectSlotsByName(book_records);
    } // setupUi

    void retranslateUi(QDialog *book_records)
    {
        book_records->setWindowTitle(QCoreApplication::translate("book_records", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label_5->setText(QCoreApplication::translate("book_records", "List of Books", nullptr));
        backButton->setText(QCoreApplication::translate("book_records", "Back", nullptr));
        label->setText(QCoreApplication::translate("book_records", "Functionality", nullptr));
        edit_book_button->setText(QCoreApplication::translate("book_records", "Edit Book", nullptr));
        label_4->setText(QCoreApplication::translate("book_records", "Book Name", nullptr));
        label_3->setText(QCoreApplication::translate("book_records", " low-stock books is in red", nullptr));
        search_button->setText(QCoreApplication::translate("book_records", "Search", nullptr));
        add_book_button->setText(QCoreApplication::translate("book_records", "Add Book", nullptr));
        delete_book_button->setText(QCoreApplication::translate("book_records", "Delete Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class book_records: public Ui_book_records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_RECORDS_H
