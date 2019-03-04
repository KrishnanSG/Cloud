#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "ui_homepage.h"
#include <QPixmap>
HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}


void HomePage::on_home_clicked()
{
    HomePage H;
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_search_clicked()
{
    Search_Page H;
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_cloud_clicked()
{
    Uploadpage H;
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_notification_clicked()
{
    Notifications_Page H;
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_user_clicked()
{
    User_Page H;
    H.show();
    this->close();
    H.exec();
}
