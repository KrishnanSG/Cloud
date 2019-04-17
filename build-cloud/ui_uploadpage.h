/********************************************************************************
** Form generated from reading UI file 'uploadpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADPAGE_H
#define UI_UPLOADPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Uploadpage
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
    QLabel *display_image;
    QPushButton *select_image;
    QPushButton *picture_upload;

    void setupUi(QDialog *Uploadpage)
    {
        if (Uploadpage->objectName().isEmpty())
            Uploadpage->setObjectName(QString::fromUtf8("Uploadpage"));
        Uploadpage->resize(1070, 715);
        Uploadpage->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: rgb(236, 240, 241);\n"
"}\n"
"QPushButton::hover{\n"
"color:white;\n"
"}"));
        label = new QLabel(Uploadpage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, 0, 2001, 131));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color:rgb(255,0,54);\n"
"}"));
        label_2 = new QLabel(Uploadpage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 151, 131));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{border-image: url(:/Final_Logo.png);\n"
"}"));
        frame = new QFrame(Uploadpage);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-10, 640, 2001, 81));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: rgb(50,50,50);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        home = new QPushButton(frame);
        home->setObjectName(QString::fromUtf8("home"));
        home->setGeometry(QRect(210, 10, 61, 61));
        home->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/home.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        search = new QPushButton(frame);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(360, 16, 41, 51));
        search->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/search.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        cloud = new QPushButton(frame);
        cloud->setObjectName(QString::fromUtf8("cloud"));
        cloud->setGeometry(QRect(500, 10, 61, 61));
        cloud->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:10px;\n"
"	border-image: url(:/cloud-computing.png);\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        notification = new QPushButton(frame);
        notification->setObjectName(QString::fromUtf8("notification"));
        notification->setGeometry(QRect(660, 16, 51, 51));
        notification->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/notification.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        user = new QPushButton(frame);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(790, 14, 61, 51));
        user->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/man-user.png);\n"
"border-radius:10px;\n"
"min-height:20px;\n"
"min-width:20px;\n"
"}"));
        display_image = new QLabel(Uploadpage);
        display_image->setObjectName(QString::fromUtf8("display_image"));
        display_image->setGeometry(QRect(60, 190, 641, 391));
        display_image->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border:1px solid black;\n"
"}"));
        display_image->setScaledContents(true);
        display_image->setAlignment(Qt::AlignCenter);
        select_image = new QPushButton(Uploadpage);
        select_image->setObjectName(QString::fromUtf8("select_image"));
        select_image->setGeometry(QRect(790, 290, 191, 61));
        select_image->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:30px;\n"
"background-color:rgb(52, 152, 219);\n"
"	font: 18pt \"Ubuntu\";\n"
"}"));
        picture_upload = new QPushButton(Uploadpage);
        picture_upload->setObjectName(QString::fromUtf8("picture_upload"));
        picture_upload->setGeometry(QRect(790, 430, 191, 61));
        picture_upload->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:30px;\n"
"background-color:rgb(233,0,54);\n"
"	font: 18pt \"Ubuntu\";\n"
"}"));

        retranslateUi(Uploadpage);

        QMetaObject::connectSlotsByName(Uploadpage);
    } // setupUi

    void retranslateUi(QDialog *Uploadpage)
    {
        Uploadpage->setWindowTitle(QApplication::translate("Uploadpage", "Upload", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        home->setText(QString());
        search->setText(QString());
        cloud->setText(QString());
        notification->setText(QString());
        user->setText(QString());
        display_image->setText(QApplication::translate("Uploadpage", "<html><head/><body><p align=\"center\">Image Preview</p></body></html>", nullptr));
        select_image->setText(QApplication::translate("Uploadpage", "Select", nullptr));
        picture_upload->setText(QApplication::translate("Uploadpage", "Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Uploadpage: public Ui_Uploadpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADPAGE_H
