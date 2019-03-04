#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "ui_user_page.h"
#include "friends.h"

User_Page::User_Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_Page)
{
    ui->setupUi(this);
}

User_Page::~User_Page()
{
    delete ui;
}


void User_Page::on_home_clicked()
{
    HomePage H;
    H.show();
    this->close();
    H.exec();
}

void User_Page::on_search_clicked()
{
    Search_Page H;
    H.show();
    this->close();
    H.exec();
}

void User_Page::on_cloud_clicked()
{
    Uploadpage H;
    H.show();
    this->close();
    H.exec();
}

void User_Page::on_notification_clicked()
{
    Notifications_Page H;
    H.show();
    this->close();
    H.exec();
}

void User_Page::on_user_clicked()
{
    User_Page H;
    H.show();
    this->close();
    H.exec();
}


void User_Page::on_pushButton_8_clicked()
{
    Friends H;
    H.show();
    this->close();
    H.exec();
}
