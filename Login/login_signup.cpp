#include "login_signup.h"
#include "ui_login_signup.h"
#include "account.h"
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <cstdio>

Login_SignUp::Login_SignUp(QWidget *parent) :QDialog(parent),ui(new Ui::Login_SignUp)
{
    ui->setupUi(this);
}

Login_SignUp::~Login_SignUp()
{
    delete ui;
}

void Login_SignUp::on_login_clicked()
{
    char input_username[32];
    char input_password[32];
    QString input_user = ui->username->text();
    QString input_pass = ui->password->text();

    // -------------- The below code converts QString to char[] ---------------

    std::copy(input_user.toStdString().begin(),input_user.toStdString().end(),input_username);
    std::copy(input_pass.toStdString().begin(),input_pass.toStdString().end(),input_password);

    // ----------------------- ********* --------------------------------------

    FILE *fp;
    fp = fopen("database.dat","ab+");
    Account temp;
    rewind(fp);
    int login_status=0;    // 0-account doesn't exist 1-password incorrect 2-success
    while(fread(&temp,sizeof (temp),1,fp))
    {
        if(strcmp(input_username,temp.get_username())==0)
        {
            if(strcmp(input_password,temp.get_password())==0)
            {
                login_status=2;
                break;
            }
            else
            {
                login_status=1;
            }
        }
    }
    if(login_status==2)
    {
        QMessageBox::information(this,"Success","Click ok to continue");
    }
    else if(login_status==1)
    {
        QMessageBox::critical(this,"Incorrect Password","Check your password");
    }
    else
    {
        QMessageBox::critical(this,"Login Failed","Invaild Username or account doesnot exist");
    }
    fclose(fp);
}
void Login_SignUp::on_create_clicked()
{
    char input_username[32];
    strcpy(input_username,"");
    char input_password[32];
    strcpy(input_password,"");
    QString input_user = ui->create_username->text();
    QString input_pass = ui->create_password->text();

    // -------------- The below code converts QString to char[] ---------------

    std::copy(input_user.toStdString().begin(),input_user.toStdString().end(),input_username);
    std::copy(input_pass.toStdString().begin(),input_pass.toStdString().end(),input_password);

    // ----------------------- ********* --------------------------------------

    FILE *fp;
    fp = fopen("database.dat","ab+");
    Account temp(input_username,input_password);
    bool creation_status=true;
    rewind(fp);
    while(fread(&temp,sizeof (temp),1,fp))
    {
        if(strcmp(input_username,temp.get_username())==0)
        {
            creation_status=false;
            break;
        }
    }
    if(creation_status)
    {
        fwrite(&temp,sizeof (temp),1,fp);
        QMessageBox::information(this,"Created","Accout created");
    }
    else
    {
        QMessageBox::critical(this,"Invalid Username","Username exists. Please login or retype username");
    }
    fclose(fp);
}
