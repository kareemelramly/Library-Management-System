/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_login_page;
    QLineEdit *usernameEdit;
    QLabel *Username_label;
    QLabel *Password_label;
    QLineEdit *passwordEdit;
    QLabel *labelBehindText;
    QPushButton *loginButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"QWidget#centralwidget {\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(240, 120, 341, 391));
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
        label_login_page = new QLabel(frame);
        label_login_page->setObjectName("label_login_page");
        label_login_page->setGeometry(QRect(120, 100, 121, 41));
        label_login_page->setAutoFillBackground(false);
        label_login_page->setStyleSheet(QString::fromUtf8(""));
        label_login_page->setAlignment(Qt::AlignmentFlag::AlignCenter);
        usernameEdit = new QLineEdit(frame);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(40, 180, 291, 26));
        usernameEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Username_label = new QLabel(frame);
        Username_label->setObjectName("Username_label");
        Username_label->setGeometry(QRect(40, 150, 81, 16));
        Password_label = new QLabel(frame);
        Password_label->setObjectName("Password_label");
        Password_label->setGeometry(QRect(40, 220, 81, 16));
        passwordEdit = new QLineEdit(frame);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(40, 250, 291, 26));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        passwordEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelBehindText = new QLabel(frame);
        labelBehindText->setObjectName("labelBehindText");
        labelBehindText->setGeometry(QRect(20, 0, 321, 391));
        labelBehindText->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        labelBehindText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(0, 0, 0, 200); /* #B2724B with 50% opacity */\n"
"    color: white;\n"
"    border: none;\n"
"}\n"
""));
        labelBehindText->setFrameShape(QFrame::Shape::NoFrame);
        labelBehindText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        loginButton = new QPushButton(frame);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(130, 340, 93, 29));
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(40, 300, 112, 26));
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton { color: white; }"));
        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(200, 300, 112, 26));
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton { color: white; }"));
        labelBehindText->raise();
        label_login_page->raise();
        usernameEdit->raise();
        Username_label->raise();
        Password_label->raise();
        passwordEdit->raise();
        loginButton->raise();
        radioButton->raise();
        radioButton_2->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_login_page->setText(QCoreApplication::translate("MainWindow", "User Login", nullptr));
        Username_label->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        Password_label->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        labelBehindText->setText(QString());
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "DarkMode", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "WhiteMode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
