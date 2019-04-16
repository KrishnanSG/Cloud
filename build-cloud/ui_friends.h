/********************************************************************************
** Form generated from reading UI file 'friends.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDS_H
#define UI_FRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Friends
{
public:
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Friends)
    {
        if (Friends->objectName().isEmpty())
            Friends->setObjectName(QString::fromUtf8("Friends"));
        Friends->resize(1070, 700);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Friends->sizePolicy().hasHeightForWidth());
        Friends->setSizePolicy(sizePolicy);
        Friends->setMinimumSize(QSize(1070, 700));
        Friends->setMaximumSize(QSize(1070, 700));
        Friends->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: rgb(236, 240, 241);\n"
"}\n"
"QPushButton::hover{\n"
"color:white;\n"
"}"));
        label = new QLabel(Friends);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 2001, 131));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color:rgb(255,0,54);\n"
"}"));
        label_2 = new QLabel(Friends);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 151, 131));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{border-image: url(:/Final_Logo.png);\n"
"}"));
        plainTextEdit = new QPlainTextEdit(Friends);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(700, 210, 311, 441));
        plainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ForbiddenCursor)));
        plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
""));
        plainTextEdit->setReadOnly(true);
        label_3 = new QLabel(Friends);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 170, 551, 491));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-image: url(:/friends_pic.jpg);\n"
"}"));
        label_4 = new QLabel(Friends);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(700, 160, 311, 51));
        QFont font;
        font.setPointSize(20);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(Friends);

        QMetaObject::connectSlotsByName(Friends);
    } // setupUi

    void retranslateUi(QDialog *Friends)
    {
        Friends->setWindowTitle(QApplication::translate("Friends", "Friends", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        plainTextEdit->setPlaceholderText(QApplication::translate("Friends", "No Friends To Show", nullptr));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("Friends", "<html><head/><body><p align=\"center\">Your Friends</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Friends: public Ui_Friends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDS_H
