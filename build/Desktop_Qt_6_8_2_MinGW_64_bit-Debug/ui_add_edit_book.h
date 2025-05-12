/********************************************************************************
** Form generated from reading UI file 'add_edit_book.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_EDIT_BOOK_H
#define UI_ADD_EDIT_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add_edit_book
{
public:
    QFrame *frame;
    QLineEdit *title_line_edit;
    QLineEdit *ID_label;
    QLabel *Username_label;
    QLineEdit *category_line_edit;
    QLabel *Password_label_3;
    QLineEdit *author_line_edit;
    QLabel *ID_label_2;
    QLabel *Password_label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *add_edit_book)
    {
        if (add_edit_book->objectName().isEmpty())
            add_edit_book->setObjectName("add_edit_book");
        add_edit_book->resize(808, 580);
        add_edit_book->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        frame = new QFrame(add_edit_book);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(100, 60, 661, 461));
        frame->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(0,0,0,200);\n"
"color:white\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        title_line_edit = new QLineEdit(frame);
        title_line_edit->setObjectName("title_line_edit");
        title_line_edit->setGeometry(QRect(70, 130, 291, 26));
        title_line_edit->setEchoMode(QLineEdit::EchoMode::Normal);
        ID_label = new QLineEdit(frame);
        ID_label->setObjectName("ID_label");
        ID_label->setGeometry(QRect(70, 60, 291, 26));
        Username_label = new QLabel(frame);
        Username_label->setObjectName("Username_label");
        Username_label->setGeometry(QRect(70, 30, 81, 21));
        Username_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        category_line_edit = new QLineEdit(frame);
        category_line_edit->setObjectName("category_line_edit");
        category_line_edit->setGeometry(QRect(70, 270, 291, 26));
        category_line_edit->setEchoMode(QLineEdit::EchoMode::Normal);
        Password_label_3 = new QLabel(frame);
        Password_label_3->setObjectName("Password_label_3");
        Password_label_3->setGeometry(QRect(70, 240, 81, 21));
        Password_label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        author_line_edit = new QLineEdit(frame);
        author_line_edit->setObjectName("author_line_edit");
        author_line_edit->setGeometry(QRect(70, 200, 291, 26));
        author_line_edit->setEchoMode(QLineEdit::EchoMode::Normal);
        ID_label_2 = new QLabel(frame);
        ID_label_2->setObjectName("ID_label_2");
        ID_label_2->setGeometry(QRect(70, 100, 81, 21));
        ID_label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Password_label_2 = new QLabel(frame);
        Password_label_2->setObjectName("Password_label_2");
        Password_label_2->setGeometry(QRect(70, 170, 81, 21));
        Password_label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(490, 230, 131, 61));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(490, 100, 131, 61));

        retranslateUi(add_edit_book);

        QMetaObject::connectSlotsByName(add_edit_book);
    } // setupUi

    void retranslateUi(QDialog *add_edit_book)
    {
        add_edit_book->setWindowTitle(QCoreApplication::translate("add_edit_book", "Dialog", nullptr));
        title_line_edit->setText(QString());
        Username_label->setText(QCoreApplication::translate("add_edit_book", "ID", nullptr));
        Password_label_3->setText(QCoreApplication::translate("add_edit_book", "Category", nullptr));
        ID_label_2->setText(QCoreApplication::translate("add_edit_book", "Title", nullptr));
        Password_label_2->setText(QCoreApplication::translate("add_edit_book", "Author", nullptr));
        pushButton_2->setText(QCoreApplication::translate("add_edit_book", "clear", nullptr));
        pushButton->setText(QCoreApplication::translate("add_edit_book", "add/Edit Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_edit_book: public Ui_add_edit_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_EDIT_BOOK_H
