/********************************************************************************
** Form generated from reading UI file 'report_paper.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_PAPER_H
#define UI_REPORT_PAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_report_paper
{
public:
    QTableWidget *overdue_books;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *borrowed_books;
    QPushButton *save_button;
    QPushButton *pushButton;

    void setupUi(QDialog *report_paper)
    {
        if (report_paper->objectName().isEmpty())
            report_paper->setObjectName("report_paper");
        report_paper->resize(814, 585);
        report_paper->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        overdue_books = new QTableWidget(report_paper);
        overdue_books->setObjectName("overdue_books");
        overdue_books->setGeometry(QRect(450, 90, 341, 421));
        QFont font;
        font.setPointSize(9);
        overdue_books->setFont(font);
        label = new QLabel(report_paper);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 50, 151, 21));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        label_2 = new QLabel(report_paper);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 50, 171, 21));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        borrowed_books = new QTableWidget(report_paper);
        borrowed_books->setObjectName("borrowed_books");
        borrowed_books->setGeometry(QRect(35, 91, 371, 421));
        save_button = new QPushButton(report_paper);
        save_button->setObjectName("save_button");
        save_button->setGeometry(QRect(390, 540, 83, 29));
        pushButton = new QPushButton(report_paper);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 10, 83, 29));

        retranslateUi(report_paper);

        QMetaObject::connectSlotsByName(report_paper);
    } // setupUi

    void retranslateUi(QDialog *report_paper)
    {
        report_paper->setWindowTitle(QCoreApplication::translate("report_paper", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("report_paper", "List of Overdue Books", nullptr));
        label_2->setText(QCoreApplication::translate("report_paper", "List of Borrowed Books", nullptr));
        save_button->setText(QCoreApplication::translate("report_paper", "save", nullptr));
        pushButton->setText(QCoreApplication::translate("report_paper", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class report_paper: public Ui_report_paper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_PAPER_H
