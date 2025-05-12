/********************************************************************************
** Form generated from reading UI file 'librarian_interface_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARIAN_INTERFACE_PAGE_H
#define UI_LIBRARIAN_INTERFACE_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_librarian_interface_page
{
public:
    QPushButton *pushButton_3;
    QFrame *frame;
    QPushButton *book_records_button;
    QLabel *welcome_2;
    QPushButton *generate_report_button;
    QLabel *welcome;
    QLabel *labelBehindText;
    QLabel *labelbackwelcome;

    void setupUi(QDialog *librarian_interface_page)
    {
        if (librarian_interface_page->objectName().isEmpty())
            librarian_interface_page->setObjectName("librarian_interface_page");
        librarian_interface_page->resize(795, 590);
        QFont font;
        font.setPointSize(8);
        librarian_interface_page->setFont(font);
        librarian_interface_page->setStyleSheet(QString::fromUtf8("\n"
"QDialog {\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        pushButton_3 = new QPushButton(librarian_interface_page);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(280, 600, 121, 41));
        frame = new QFrame(librarian_interface_page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 120, 641, 351));
        frame->setStyleSheet(QString::fromUtf8("\n"
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
        book_records_button = new QPushButton(frame);
        book_records_button->setObjectName("book_records_button");
        book_records_button->setGeometry(QRect(110, 180, 121, 41));
        welcome_2 = new QLabel(frame);
        welcome_2->setObjectName("welcome_2");
        welcome_2->setGeometry(QRect(50, 280, 501, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(true);
        welcome_2->setFont(font1);
        generate_report_button = new QPushButton(frame);
        generate_report_button->setObjectName("generate_report_button");
        generate_report_button->setGeometry(QRect(390, 180, 131, 41));
        welcome = new QLabel(frame);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(180, 80, 261, 41));
        welcome->setFont(font1);
        welcome->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"}"));
        welcome->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelBehindText = new QLabel(frame);
        labelBehindText->setObjectName("labelBehindText");
        labelBehindText->setGeometry(QRect(-70, 270, 761, 61));
        labelBehindText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(0, 0, 0, 200); /* #B2724B with 50% opacity */\n"
"    color: white;\n"
"    border: none;\n"
"}\n"
""));
        labelBehindText->setFrameShape(QFrame::Shape::NoFrame);
        labelBehindText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelbackwelcome = new QLabel(frame);
        labelbackwelcome->setObjectName("labelbackwelcome");
        labelbackwelcome->setGeometry(QRect(0, 70, 641, 51));
        labelbackwelcome->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(255,255,255, .5);\n"
"}"));
        labelBehindText->raise();
        labelbackwelcome->raise();
        book_records_button->raise();
        welcome_2->raise();
        generate_report_button->raise();
        welcome->raise();

        retranslateUi(librarian_interface_page);

        QMetaObject::connectSlotsByName(librarian_interface_page);
    } // setupUi

    void retranslateUi(QDialog *librarian_interface_page)
    {
        librarian_interface_page->setWindowTitle(QCoreApplication::translate("librarian_interface_page", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("librarian_interface_page", "Book Records", nullptr));
        book_records_button->setText(QCoreApplication::translate("librarian_interface_page", "Book Records", nullptr));
        welcome_2->setText(QCoreApplication::translate("librarian_interface_page", "Report generation status: ________________________________________", nullptr));
        generate_report_button->setText(QCoreApplication::translate("librarian_interface_page", "generate Report", nullptr));
        welcome->setText(QCoreApplication::translate("librarian_interface_page", "Welcome Librarian", nullptr));
        labelBehindText->setText(QString());
        labelbackwelcome->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class librarian_interface_page: public Ui_librarian_interface_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARIAN_INTERFACE_PAGE_H
