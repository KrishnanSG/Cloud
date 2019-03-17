#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "friends.h"
#include "ui_friends.h"

Friends::Friends(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Friends)
{
    ui->setupUi(this);
    A.input(username);
}

Friends::~Friends()
{
    delete ui;
}

void Friends::on_home_clicked()
{
    HomePage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Friends::on_search_clicked()
{
    Search_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Friends::on_cloud_clicked()
{
    Uploadpage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Friends::on_notification_clicked()
{
    Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Friends::on_user_clicked()
{
    User_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}
