/********************************************************************************
** Form generated from reading UI file 'notifications_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATIONS_PAGE_H
#define UI_NOTIFICATIONS_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Notifications_Page
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
    QPushButton *Accept_Request_Button;
    QPlainTextEdit *display_notifications;
    QLabel *display_username;
    QPushButton *Delete_Request;

    void setupUi(QDialog *Notifications_Page)
    {
        if (Notifications_Page->objectName().isEmpty())
            Notifications_Page->setObjectName(QString::fromUtf8("Notifications_Page"));
        Notifications_Page->resize(1070, 715);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Notifications_Page->sizePolicy().hasHeightForWidth());
        Notifications_Page->setSizePolicy(sizePolicy);
        Notifications_Page->setMinimumSize(QSize(1070, 715));
        Notifications_Page->setMaximumSize(QSize(1070, 800));
        Notifications_Page->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: rgb(236, 240, 241);\n"
"}\n"
"QPushButton::hover{\n"
"color:white;\n"
"}"));
        label = new QLabel(Notifications_Page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 2001, 131));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color:rgb(255,0,54);\n"
"}"));
        label_2 = new QLabel(Notifications_Page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 151, 131));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{border-image: url(:/Final_Logo.png);\n"
"}"));
        frame = new QFrame(Notifications_Page);
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
        Accept_Request_Button = new QPushButton(Notifications_Page);
        Accept_Request_Button->setObjectName(QString::fromUtf8("Accept_Request_Button"));
        Accept_Request_Button->setGeometry(QRect(520, 180, 151, 41));
        Accept_Request_Button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:20px;\n"
"background-color:rgb(52, 152, 219);\n"
"font: 14pt \"Ubuntu\";\n"
"}"));
        display_notifications = new QPlainTextEdit(Notifications_Page);
        display_notifications->setObjectName(QString::fromUtf8("display_notifications"));
        display_notifications->setEnabled(true);
        display_notifications->setGeometry(QRect(170, 260, 691, 341));
        QFont font;
        font.setPointSize(18);
        display_notifications->setFont(font);
        display_notifications->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ForbiddenCursor)));
        display_notifications->setReadOnly(true);
        display_username = new QLabel(Notifications_Page);
        display_username->setObjectName(QString::fromUtf8("display_username"));
        display_username->setGeometry(QRect(170, 180, 321, 41));
        QFont font1;
        font1.setPointSize(15);
        display_username->setFont(font1);
        display_username->setIndent(119);
        Delete_Request = new QPushButton(Notifications_Page);
        Delete_Request->setObjectName(QString::fromUtf8("Delete_Request"));
        Delete_Request->setGeometry(QRect(710, 180, 151, 41));
        Delete_Request->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:20px;\n"
"background-color:rgb(233,0,54);\n"
"font: 14pt \"Ubuntu\";\n"
"}"));
        label->raise();
        frame->raise();
        label_2->raise();
        Accept_Request_Button->raise();
        display_notifications->raise();
        display_username->raise();
        Delete_Request->raise();

        retranslateUi(Notifications_Page);

        QMetaObject::connectSlotsByName(Notifications_Page);
    } // setupUi

    void retranslateUi(QDialog *Notifications_Page)
    {
        Notifications_Page->setWindowTitle(QApplication::translate("Notifications_Page", "Notifications", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        home->setText(QString());
        search->setText(QString());
        cloud->setText(QString());
        notification->setText(QString());
        user->setText(QString());
        Accept_Request_Button->setText(QApplication::translate("Notifications_Page", "Accept", nullptr));
        display_notifications->setPlaceholderText(QApplication::translate("Notifications_Page", "No new notifications", nullptr));
        display_username->setText(QApplication::translate("Notifications_Page", "Username", nullptr));
        Delete_Request->setText(QApplication::translate("Notifications_Page", "Decline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notifications_Page: public Ui_Notifications_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATIONS_PAGE_H
