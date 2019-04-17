/********************************************************************************
** Form generated from reading UI file 'loading.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_H
#define UI_LOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Loading
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Loading)
    {
        if (Loading->objectName().isEmpty())
            Loading->setObjectName(QString::fromUtf8("Loading"));
        Loading->setEnabled(true);
        Loading->resize(604, 405);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Loading->sizePolicy().hasHeightForWidth());
        Loading->setSizePolicy(sizePolicy);
        Loading->setMinimumSize(QSize(604, 405));
        Loading->setMaximumSize(QSize(604, 405));
        label = new QLabel(Loading);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 601, 331));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Loading);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 340, 581, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(Loading);

        QMetaObject::connectSlotsByName(Loading);
    } // setupUi

    void retranslateUi(QDialog *Loading)
    {
        Loading->setWindowTitle(QApplication::translate("Loading", "Loading", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Loading", "<html><head/><body><p align=\"center\">Connecting to Server...</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loading: public Ui_Loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_H
