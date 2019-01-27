#include "login.h"
#include "welcome.h"
#include "create.h"
#include "ui_login.h"
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    ui->lineEdit->setText(password);
    if (username==password)
    {
        hide();
        Welcome w;
        w.showMaximized();
        w.exec();
        show();
    }
}

void Login::on_create_account_clicked()
{
    hide();
    Create c;
    c.showMaximized();
    c.exec();
    show();
}
