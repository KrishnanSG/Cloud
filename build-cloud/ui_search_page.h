/********************************************************************************
** Form generated from reading UI file 'search_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_PAGE_H
#define UI_SEARCH_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Search_Page
{
public:
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QPushButton *home;
    QPushButton *search;
    QPushButton *cloud;
    QPushButton *notification;
    QPushButton *user;
    QLineEdit *enter_username_lineEdit;
    QPushButton *search_button;
    QPushButton *make_friend_button;
    QLabel *display_username_label;
    QPushButton *view_profile_button;

    void setupUi(QDialog *Search_Page)
    {
        if (Search_Page->objectName().isEmpty())
            Search_Page->setObjectName(QString::fromUtf8("Search_Page"));
        Search_Page->resize(1070, 715);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Search_Page->sizePolicy().hasHeightForWidth());
        Search_Page->setSizePolicy(sizePolicy);
        Search_Page->setMinimumSize(QSize(1070, 715));
        Search_Page->setMaximumSize(QSize(1070, 800));
        Search_Page->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: rgb(236, 240, 241);\n"
"}\n"
"QPushButton::hover{\n"
"color:white;\n"
"}"));
        label = new QLabel(Search_Page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 2001, 131));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color:rgb(255,0,54);\n"
"}"));
        label_2 = new QLabel(Search_Page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 151, 131));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{border-image: url(:/Final_Logo.png);\n"
"}"));
        frame = new QFrame(Search_Page);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 640, 2001, 81));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: rgb(50,50,50);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        home = new QPushButton(frame);
        home->setObjectName(QString::fromUtf8("home"));
        home->setGeometry(QRect(190, 10, 61, 61));
        home->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/home.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        search = new QPushButton(frame);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(340, 16, 41, 51));
        search->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/search.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        cloud = new QPushButton(frame);
        cloud->setObjectName(QString::fromUtf8("cloud"));
        cloud->setGeometry(QRect(480, 10, 61, 61));
        cloud->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:10px;\n"
"	border-image: url(:/cloud-computing.png);\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        notification = new QPushButton(frame);
        notification->setObjectName(QString::fromUtf8("notification"));
        notification->setGeometry(QRect(640, 16, 51, 51));
        notification->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/notification.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        user = new QPushButton(frame);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(770, 14, 61, 51));
        user->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/man-user.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        enter_username_lineEdit = new QLineEdit(Search_Page);
        enter_username_lineEdit->setObjectName(QString::fromUtf8("enter_username_lineEdit"));
        enter_username_lineEdit->setGeometry(QRect(280, 180, 321, 41));
        enter_username_lineEdit->setLayoutDirection(Qt::LeftToRight);
        enter_username_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius:10px;\n"
"padding-left:10px;\n"
"}"));
        search_button = new QPushButton(Search_Page);
        search_button->setObjectName(QString::fromUtf8("search_button"));
        search_button->setGeometry(QRect(660, 180, 151, 41));
        search_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:20px;\n"
"background-color:rgb(52, 152, 219);\n"
"font: 14pt \"Ubuntu\";\n"
"}"));
        make_friend_button = new QPushButton(Search_Page);
        make_friend_button->setObjectName(QString::fromUtf8("make_friend_button"));
        make_friend_button->setGeometry(QRect(570, 340, 151, 41));
        make_friend_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:20px;\n"
"background-color:rgb(52, 152, 219);\n"
"font: 14pt \"Ubuntu\";\n"
"}"));
        display_username_label = new QLabel(Search_Page);
        display_username_label->setObjectName(QString::fromUtf8("display_username_label"));
        display_username_label->setGeometry(QRect(250, 340, 251, 41));
        QFont font;
        font.setPointSize(15);
        display_username_label->setFont(font);
        display_username_label->setIndent(68);
        view_profile_button = new QPushButton(Search_Page);
        view_profile_button->setObjectName(QString::fromUtf8("view_profile_button"));
        view_profile_button->setGeometry(QRect(770, 340, 151, 41));
        view_profile_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:20px;\n"
"background-color:rgb(52, 152, 219);\n"
"font: 14pt \"Ubuntu\";\n"
"}"));
        label->raise();
        frame->raise();
        label_2->raise();
        enter_username_lineEdit->raise();
        search_button->raise();
        make_friend_button->raise();
        display_username_label->raise();
        view_profile_button->raise();

        retranslateUi(Search_Page);

        QMetaObject::connectSlotsByName(Search_Page);
    } // setupUi

    void retranslateUi(QDialog *Search_Page)
    {
        Search_Page->setWindowTitle(QApplication::translate("Search_Page", "Search", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        home->setText(QString());
        search->setText(QString());
        cloud->setText(QString());
        notification->setText(QString());
        user->setText(QString());
        enter_username_lineEdit->setText(QString());
        enter_username_lineEdit->setPlaceholderText(QApplication::translate("Search_Page", "                  Enter Username", nullptr));
        search_button->setText(QApplication::translate("Search_Page", "Search", nullptr));
        make_friend_button->setText(QApplication::translate("Search_Page", "Friend", nullptr));
        display_username_label->setText(QApplication::translate("Search_Page", "Username", nullptr));
        view_profile_button->setText(QApplication::translate("Search_Page", "View Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search_Page: public Ui_Search_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_PAGE_H
