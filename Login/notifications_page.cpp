#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "ui_notifications_page.h"

Notifications_Page::Notifications_Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notifications_Page)
{
    ui->setupUi(this);
    ui->textEdit->setText("2019/03/03 12:36:30 - Harry Hunt uploaded 5 pictures\n2019/03/03 11:12:50 - Krish525 uploaded 10 pictures");
    ui->textEdit->setReadOnly(true);
}

Notifications_Page::~Notifications_Page()
{
    delete ui;
}


void Notifications_Page::on_home_clicked()
{
    HomePage H;
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_search_clicked()
{
    Search_Page H;
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_cloud_clicked()
{
    Uploadpage H;
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_notification_clicked()
{
    Notifications_Page H;
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_user_clicked()
{
    User_Page H;
    H.show();
    this->close();
    H.exec();
}
