#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "ui_uploadpage.h"

Uploadpage::Uploadpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uploadpage)
{
    ui->setupUi(this);
}

Uploadpage::~Uploadpage()
{
    delete ui;
}

void Uploadpage::on_home_clicked()
{
    HomePage H;
    H.show();
    this->close();
    H.exec();
}

void Uploadpage::on_search_clicked()
{
    Search_Page H;
    H.show();
    this->close();
    H.exec();
}

void Uploadpage::on_cloud_clicked()
{
    Uploadpage H;
    H.show();
    this->close();
    H.exec();
}

void Uploadpage::on_notification_clicked()
{
    Notifications_Page H;
    H.show();
    this->close();
    H.exec();
}

void Uploadpage::on_user_clicked()
{
    User_Page H;
    H.show();
    this->close();
    H.exec();
}

