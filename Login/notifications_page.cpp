#include "notifications_page.h"
#include "ui_notifications_page.h"

Notifications_Page::Notifications_Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notifications_Page)
{
    ui->setupUi(this);
}

Notifications_Page::~Notifications_Page()
{
    delete ui;
}
