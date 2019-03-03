#include "search_page.h"
#include "ui_search_page.h"

Search_Page::Search_Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_Page)
{
    ui->setupUi(this);
}

Search_Page::~Search_Page()
{
    delete ui;
}


void Search_Page::on_home_clicked()
{
    HomePage H;
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_search_clicked()
{
    Search_Page H;
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_cloud_clicked()
{
    Uploadpage H;
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_notification_clicked()
{
    Notifications_Page H;
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_user_clicked()
{
    User_Page H;
    H.show();
    this->close();
    H.exec();
}

