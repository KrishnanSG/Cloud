#include "login_signup.h"
#include "ui_login_signup.h"
#include "account.h"
#include <stdio.h>
#include <QMessageBox>
#include <QDateTime>
#include <qdebug.h>

Login_SignUp::Login_SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_SignUp)
{
    ui->setupUi(this);
}

Login_SignUp::~Login_SignUp()
{
    delete ui;
}

void Login_SignUp::on_login_clicked()
{
    QString input_username;
    QString input_password;
    input_username = ui->username->text();
    input_password = ui->password->text();
    FILE *fp;
    fp = fopen("database.txt","a+");
    Account temp;
    bool login_fail=true;
    while(fread(&temp,sizeof(Account),1,fp))
    {/*
        qDebug() << temp.get_username();
        qDebug() << temp.get_password();*/
        if(temp.get_username()==input_username)
        {
            if(temp.get_password()==input_password)
            {
                login_fail=false;
            }
            else
            {
                QMessageBox msg;
                msg.critical(this,"Login Failed","Wrong Password");

            }
        }
    }
    if(login_fail)
    {

        QMessageBox msg;
        msg.critical(this,"Login Failed","Account doesn't exist");
    }
    else
    {
        //next window
        QMessageBox msg;
        msg.critical(this,"Login Success","Success");
    }
}

void Login_SignUp::on_create_clicked()
{
    FILE *fp;
    fp = fopen("database.txt","a+");
    QString input_username;
    QString input_password;
    input_username = ui->create_username->text();
    input_password = ui->create_password->text();
    Account new_account(input_username,input_password);
    fwrite(&new_account,sizeof(Account),1,fp);
    fclose(fp);
    /*
    const QDateTime now = QDateTime::currentDateTime();
    ui->create_username->setText(now.toString("hh:mm:ss_dd-MM"));
    */
}
