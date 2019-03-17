#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "ui_notifications_page.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>

Notifications_Page::Notifications_Page(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notifications_Page)
{
    ui->setupUi(this);
    //ui->textEdit->setText("2019/03/03 12:36:30 - Harry Hunt uploaded 5 pictures\n2019/03/03 11:12:50 - Krish525 uploaded 10 pictures");
    ui->display_notifications->setReadOnly(true);
    A.input(username);
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    QString filename="notification.txt";
    QFile file(filename);
    //if (inputFile.open(QIODevice::ReadOnly))
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->display_notifications->setPlainText(text);
    file.close();
    qDebug()<<text;
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    FILE *fp;
    fp=fopen("Request.txt","r");
    char requested_user[16];
    fscanf(fp,"%s",requested_user);
    fclose(fp);
    QString Temp=requested_user;
    if(strcmp(requested_user,"")==0){
        ui->display_username->hide();
        ui->display_profile->hide();}
    ui->display_username->setText(Temp);
    file.close();
    qDebug()<<text;
    qDebug()<<Temp;
    QDir::setCurrent(str + "/pixel-database");
}

Notifications_Page::~Notifications_Page()
{
    delete ui;
}


void Notifications_Page::on_home_clicked()
{
    HomePage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_search_clicked()
{
    Search_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_cloud_clicked()
{
    Uploadpage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_notification_clicked()
{
    Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_user_clicked()
{
    User_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_Accept_Request_Button_clicked()
{
    FILE *fp;
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    fp=fopen("Request.txt","r");
    char requested_user[16];
    fscanf(fp,"%s",requested_user);
    fclose(fp);
    QString Temp=requested_user;
    QDir::setCurrent(str + "/pixel-database");
    fp = fopen("database.dat","ab+");
    Account temp;
    rewind(fp);
    while(fread(&temp,sizeof (temp),1,fp))
    {
        if(strcmp(requested_user,temp.get_username())==0)
        {
            break;
        }
    }
    char requested_users_name[16];
    char notification_string[100];
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    fclose(fp);
    fp=fopen("friends.txt","a+");
    fprintf(fp,"%s\n",requested_user);
    //fwrite((&temp,sizeof(temp)),1,fp);
    fclose(fp);
    fp=fopen("Request.txt","a+");
    FILE *fptr=fopen("Data.txt","w");
    fscanf(fp,"%s",requested_users_name);
    while(fscanf(fp,"%s",requested_users_name)!=EOF)
    {
        fprintf(fptr,"%s\n",requested_users_name);
    }
    fclose(fp);
    fclose(fptr);
    remove("Request.txt");
    rename("Data.txt","Request.txt");
    fp=fopen("notification.txt","a+");
    fptr=fopen("Data.txt","w");
    fscanf(fp,"%s",notification_string);
    while(fscanf(fp,"%s",notification_string)!=EOF)
    {
        fprintf(fptr,"%s\n",notification_string);
    }
    fclose(fp);
    fclose(fptr);
    remove("notification.txt");
    rename("Data.txt","notification.txt");
    QMessageBox::information(this,"The request has been accepted","Accepted");
    QDir::setCurrent(str + "/pixel-database");
    Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Notifications_Page::on_Delete_Request_clicked()
{
    int file_empty_status=0;
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    char requested_users_name[16];
    char notification_string[100];
    FILE *fp;
    fp=fopen("notification.txt","a+");
    FILE *fptr=fopen("Data.txt","w");
    fgets(notification_string,100, fp);
    qDebug()<<notification_string;
    while(1)
    {
       if (fgets(notification_string,100, fp) == NULL){
           file_empty_status=1;
           ui->display_profile->hide();
           ui->display_username->hide();
           ui->Accept_Request_Button->hide();
           ui->Delete_Request->hide();
            break;
       }
       fprintf(fptr,"%s",notification_string);
    }
    fclose(fp);
    fclose(fptr);
    remove("notification.txt");
    rename("Data.txt","notification.txt");
    fp=fopen("Request.txt","a+");
    fptr=fopen("Data.txt","w");
    fgets(requested_users_name,16, fp);
    while(1)
    {
        if (fgets(requested_users_name,16, fp) == NULL)
        {
            break;
        }
        fprintf(fptr,"%s",requested_users_name);
        qDebug()<<requested_users_name<<"Hi";
    }
    fclose(fp);
    fclose(fptr);
    remove("Request.txt");
    rename("Data.txt","Request.txt");

    QDir::setCurrent(str + "/pixel-database");
    Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}
