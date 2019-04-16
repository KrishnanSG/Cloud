/********************************************************************************
** Form generated from reading UI file 'login_signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_SIGNUP_H
#define UI_LOGIN_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_SignUp
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *password;
    QLabel *label_6;
    QLineEdit *username;
    QPushButton *login;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *tab_2;
    QLineEdit *create_password;
    QPushButton *create;
    QLineEdit *create_username;
    QLineEdit *create_retype_password;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *profile_pic;

    void setupUi(QDialog *Login_SignUp)
    {
        if (Login_SignUp->objectName().isEmpty())
            Login_SignUp->setObjectName(QString::fromUtf8("Login_SignUp"));
        Login_SignUp->resize(1096, 682);
        Login_SignUp->setMinimumSize(QSize(1096, 682));
        Login_SignUp->setMaximumSize(QSize(1096, 682));
        Login_SignUp->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color: #2d3436;\n"
"}\n"
"QMessageBox{\n"
"background-color:white;\n"
"}"));
        frame = new QFrame(Login_SignUp);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 9, 571, 664));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-image: url(:/Final_Logo.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(Login_SignUp);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(576, 9, 511, 664));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 531, 661));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{\n"
"	background-color: rgba(242,241,239,175);\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        password = new QLineEdit(tab);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(130, 240, 261, 51));
        password->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:10px;\n"
"border-radius:10px;\n"
"background-color:rgba(238,238,236,100);\n"
"}"));
        password->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 250, 31, 31));
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"	border-image: url(:/SAVE_20190202_171340.png);\n"
"}"));
        username = new QLineEdit(tab);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(130, 170, 261, 41));
        username->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:10px;\n"
"border-radius:10px;\n"
"background-color:rgb(238,238,236,100)\n"
"}"));
        login = new QPushButton(tab);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(190, 330, 111, 31));
        login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:10px;\n"
"background-color:rgba(255,0,54,100)\n"
"}\n"
"QPushButton::hover{\n"
"color:white;\n"
"}"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 170, 31, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"	border-image: url(:/SAVE_20190202_171639.png);\n"
"}"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 190, 281, 20));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 270, 281, 20));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 20, 381, 41));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 560, 381, 41));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 50, 61, 541));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(410, 50, 61, 541));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        create_password = new QLineEdit(tab_2);
        create_password->setObjectName(QString::fromUtf8("create_password"));
        create_password->setGeometry(QRect(150, 350, 241, 41));
        create_password->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:10px;\n"
"border-radius:10px;\n"
"background-color:rgba(238,238,236,100);\n"
"}"));
        create_password->setEchoMode(QLineEdit::Password);
        create = new QPushButton(tab_2);
        create->setObjectName(QString::fromUtf8("create"));
        create->setGeometry(QRect(210, 500, 111, 31));
        create->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:10px;\n"
"background-color:rgba(255,0,54,100)\n"
"}\n"
"QPushButton::hover{\n"
"color:white;\n"
"}"));
        create_username = new QLineEdit(tab_2);
        create_username->setObjectName(QString::fromUtf8("create_username"));
        create_username->setGeometry(QRect(150, 290, 241, 41));
        create_username->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:10px;\n"
"border-radius:10px;\n"
"background-color:rgba(238,238,236,100);\n"
"}"));
        create_retype_password = new QLineEdit(tab_2);
        create_retype_password->setObjectName(QString::fromUtf8("create_retype_password"));
        create_retype_password->setGeometry(QRect(150, 410, 241, 41));
        create_retype_password->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"padding-left:10px;\n"
"background-color:rgba(238,238,236,100);\n"
"border-radius:10px;\n"
"}"));
        create_retype_password->setEchoMode(QLineEdit::Password);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 410, 31, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"	border-image: url(:/SAVE_20190202_171340.png);\n"
"}"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 290, 31, 31));
        label_8->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"	border-image: url(:/SAVE_20190202_171639.png);\n"
"}"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 570, 431, 41));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(440, 50, 61, 551));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 40, 61, 551));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 10, 431, 41));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(330, 350, 31, 31));
        label_16->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"	border-image: url(:/SAVE_20190202_171340.png);\n"
"}"));
        profile_pic = new QLabel(tab_2);
        profile_pic->setObjectName(QString::fromUtf8("profile_pic"));
        profile_pic->setGeometry(QRect(180, 90, 161, 161));
        profile_pic->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-radius:20px;\n"
"	min-height:20px;\n"
"	min-width:20px;\n"
"	border-image: url(:/SAVE_20190202_171639.png);\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, login);
        QWidget::setTabOrder(login, create);
        QWidget::setTabOrder(create, tabWidget);
        QWidget::setTabOrder(tabWidget, create_retype_password);
        QWidget::setTabOrder(create_retype_password, create_password);
        QWidget::setTabOrder(create_password, create_username);

        retranslateUi(Login_SignUp);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Login_SignUp);
    } // setupUi

    void retranslateUi(QDialog *Login_SignUp)
    {
        Login_SignUp->setWindowTitle(QApplication::translate("Login_SignUp", "Cloud", nullptr));
        password->setPlaceholderText(QApplication::translate("Login_SignUp", "Password", nullptr));
        label_6->setText(QString());
        username->setPlaceholderText(QApplication::translate("Login_SignUp", "Username", nullptr));
        login->setText(QApplication::translate("Login_SignUp", "Login", nullptr));
        label_5->setText(QString());
        label->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">________________________________</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">________________________________</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">______________________________________________________________</p></body></html>", nullptr));
        label_9->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">______________________________________________________________</p></body></html>", nullptr));
        label_10->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p></body></html>", nullptr));
        label_11->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Login_SignUp", "Log In", nullptr));
        create_password->setPlaceholderText(QApplication::translate("Login_SignUp", "Password", nullptr));
        create->setText(QApplication::translate("Login_SignUp", "Create", nullptr));
        create_username->setPlaceholderText(QApplication::translate("Login_SignUp", "Username", nullptr));
        create_retype_password->setPlaceholderText(QApplication::translate("Login_SignUp", "Retype Password", nullptr));
        label_7->setText(QString());
        label_8->setText(QString());
        label_12->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">______________________________________________________________</p></body></html>", nullptr));
        label_13->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p></body></html>", nullptr));
        label_14->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p><p align=\"center\">|</p></body></html>", nullptr));
        label_15->setText(QApplication::translate("Login_SignUp", "<html><head/><body><p align=\"center\">______________________________________________________________</p></body></html>", nullptr));
        label_16->setText(QString());
        profile_pic->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Login_SignUp", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_SignUp: public Ui_Login_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_SIGNUP_H
