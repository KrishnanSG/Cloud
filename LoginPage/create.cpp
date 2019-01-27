#include "create.h"
#include "ui_create.h"
#include <QFileDialog>
#include <QMessageBox>
#include "account.h"
#include <stdio.h>
Create::Create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create)
{
    ui->setupUi(this);
}

Create::~Create()
{
    delete ui;
}

void Create::on_upload_clicked()
{
    QString filename = QFileDialog::getOpenFileName();
    QPixmap pic(filename);
    ui->picture->setPixmap(pic.scaled(ui->picture->width(),ui->picture->height(),Qt::KeepAspectRatio));
}

void Create::on_create_clicked()
{
    ACCOUNT new_account;
    FILE *file;
    file=fopen("/home/krish525/LoginPage/database.dat","ab+");
    QString user,pass,pin;
    user=ui->username->text();
    pass=ui->password->text();
    pin=ui->pin->text();
    new_account.setdata(user,pass,pin);
    //fwrite(&new_account,sizeof (new_account),1,file);
    fclose(file);
    hide();
}
