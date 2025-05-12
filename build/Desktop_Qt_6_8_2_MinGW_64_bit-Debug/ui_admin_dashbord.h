/********************************************************************************
** Form generated from reading UI file 'admin_dashbord.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_DASHBORD_H
#define UI_ADMIN_DASHBORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin_Dashbord
{
public:
    QFrame *frame;
    QGroupBox *groupBox;
    QPushButton *delete_user_button;
    QLabel *label_5;
    QTableWidget *usersTable;
    QLabel *label_4;
    QFrame *frame_2;
    QLabel *label;
    QLineEdit *passwordEdit;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QPushButton *signupButton;
    QGroupBox *groupBox2;
    QRadioButton *librarianRadioButton;
    QRadioButton *memberRadioButton;
    QLabel *role_login;
    QLabel *label_3;
    QLabel *label_6;

    void setupUi(QDialog *Admin_Dashbord)
    {
        if (Admin_Dashbord->objectName().isEmpty())
            Admin_Dashbord->setObjectName("Admin_Dashbord");
        Admin_Dashbord->resize(804, 602);
        Admin_Dashbord->setStyleSheet(QString::fromUtf8("\n"
"QDialog{\n"
"    background-image: url(\":/Images/ylswjsy7stw-2048x1201.jpg\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
""));
        frame = new QFrame(Admin_Dashbord);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, -110, 771, 691));
        frame->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 140, 391, 571));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:none;\n"
"}"));
        delete_user_button = new QPushButton(groupBox);
        delete_user_button->setObjectName("delete_user_button");
        delete_user_button->setGeometry(QRect(120, 510, 93, 29));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 30, 131, 41));
        usersTable = new QTableWidget(groupBox);
        usersTable->setObjectName("usersTable");
        usersTable->setGeometry(QRect(10, 90, 331, 381));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(330, 70, 131, 41));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(439, 270, 301, 361));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background:rgba(0,0,0,200);\n"
"}\n"
"\n"
"\n"
"QLabel {\n"
"    font-family: \"Segoe UI\";       /* Or any font you like */\n"
"    font-size: 16px;               /* Adjust size as needed */\n"
"    font-weight: bold;             /* This makes it bold */\n"
"    color: white;                  /* Optional: sets text color */\n"
"}\n"
"QRadioButton {\n"
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
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 40, 111, 20));
        passwordEdit = new QLineEdit(frame_2);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(30, 180, 241, 26));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        usernameEdit = new QLineEdit(frame_2);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(30, 100, 241, 26));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 63, 20));
        signupButton = new QPushButton(frame_2);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(110, 310, 93, 29));
        groupBox2 = new QGroupBox(frame_2);
        groupBox2->setObjectName("groupBox2");
        groupBox2->setGeometry(QRect(40, 240, 221, 61));
        librarianRadioButton = new QRadioButton(groupBox2);
        librarianRadioButton->setObjectName("librarianRadioButton");
        librarianRadioButton->setGeometry(QRect(110, 20, 110, 24));
        memberRadioButton = new QRadioButton(groupBox2);
        memberRadioButton->setObjectName("memberRadioButton");
        memberRadioButton->setGeometry(QRect(0, 20, 110, 24));
        role_login = new QLabel(frame_2);
        role_login->setObjectName("role_login");
        role_login->setGeometry(QRect(30, 220, 63, 20));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 140, 121, 20));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(270, 120, 261, 81));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        label_6->setFont(font);
        label_6->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background:rgba(0,0,0, 200);\n"
"}\n"
""));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Admin_Dashbord);

        QMetaObject::connectSlotsByName(Admin_Dashbord);
    } // setupUi

    void retranslateUi(QDialog *Admin_Dashbord)
    {
        Admin_Dashbord->setWindowTitle(QCoreApplication::translate("Admin_Dashbord", "Dialog", nullptr));
        groupBox->setTitle(QString());
        delete_user_button->setText(QCoreApplication::translate("Admin_Dashbord", "Delete User", nullptr));
        label_5->setText(QCoreApplication::translate("Admin_Dashbord", "List of Users", nullptr));
        label_4->setText(QCoreApplication::translate("Admin_Dashbord", "Welcome Admin", nullptr));
        label->setText(QCoreApplication::translate("Admin_Dashbord", "New User", nullptr));
        label_2->setText(QCoreApplication::translate("Admin_Dashbord", "Name", nullptr));
        signupButton->setText(QCoreApplication::translate("Admin_Dashbord", "Add", nullptr));
        groupBox2->setTitle(QCoreApplication::translate("Admin_Dashbord", "GroupBox", nullptr));
        librarianRadioButton->setText(QCoreApplication::translate("Admin_Dashbord", "Librarian", nullptr));
        memberRadioButton->setText(QCoreApplication::translate("Admin_Dashbord", "Member", nullptr));
        role_login->setText(QCoreApplication::translate("Admin_Dashbord", "Role", nullptr));
        label_3->setText(QCoreApplication::translate("Admin_Dashbord", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("Admin_Dashbord", "Welcome, admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin_Dashbord: public Ui_Admin_Dashbord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_DASHBORD_H
