/*#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "user_page.h"
*/
#include "notifications_page.h"
#include "ui_notifications_page.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QProcess>
#include <QtConcurrent/QtConcurrent>

void put_files(QString local,QString remote)      // for files
{
    QProcess::execute("skicka upload "+local+ " pixel-database/"+remote);
}


Notifications_Page::Notifications_Page(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notifications_Page)
{
    FILE *fp;
    ui->setupUi(this);
    ui->display_notifications->setReadOnly(true);
    A.input(username);
    QString str = QDir::homePath();
    QDir::setCurrent(str+"/pixel-database");
    //download_files(QString("pixel-database/"+QString(A.get_username())+"/Request.txt"),QString("Request.txt"));
    //download_files(QString("pixel-database/"+QString(A.get_username())+"/notification.txt"),QString("notification.txt"));
    Account Temp_read;
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
    //FILE *fp;
    fp=fopen("Request.txt","r");
    char requested_user[16];
    strcpy(requested_user,"");
    fscanf(fp,"%s",requested_user);
    fclose(fp);
    if(strcmp(requested_user,"")==0)
    {
        //ui->display_profile->hide();
        ui->display_username->hide();
        ui->Accept_Request_Button->hide();
        ui->Delete_Request->hide();
    }
    ui->display_username->setText(QString(requested_user));
    file.close();
    QDir::setCurrent(str + "/pixel-database");
}

Notifications_Page::~Notifications_Page()
{
    delete ui;
}


void Notifications_Page::on_home_clicked()
{
    done(1);
}

void Notifications_Page::on_search_clicked()
{
    done(2);
}

void Notifications_Page::on_cloud_clicked()
{
    done(3);
}

void Notifications_Page::on_notification_clicked()
{
    done(4);
}

void Notifications_Page::on_user_clicked()
{
    done(5);
}

void extract_files(int action,QString user)
{
    if(action==1)
    {
        qDebug()<<"In Download Phase"<<" "<<user<<" "<<QDir::currentPath();
        QProcess::execute("skicka download pixel-database/"+user+"/friends.txt" + " friends.txt");
        QProcess::execute("skicka download pixel-database/"+user+"/notification.txt" + " notification.txt");
    }
    else
    {
        qDebug()<<"In Upload Phase"<<" "<<user <<" "<<QDir::currentPath();
        QProcess::execute("skicka upload friends.txt pixel-database/"+user+"/friends.txt");
        QProcess::execute("skicka upload notification.txt pixel-database/"+user+"/notification.txt");
    }
}

void Notifications_Page::request_accepted()
{
    qDebug()<<"In request accepted";
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
    /*int img_count=0;
    while(fread(&temp,sizeof (temp),1,fp))
    {
        if(strcmp(requested_user,temp.get_username())==0)
        {
            img_count=temp.get_image_count();
            break;
        }
    }*/
    char requested_users_name[16];
    //char notification_string[100];
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
    fp=fopen("notification.txt","w");
    fclose(fp);

    qDebug()<<"After Message";
    qDebug()<<QDir::currentPath();
    //qDebug()<<"Extract for Upload"
    //------Sending to another user ------------
    //ui->make_friend_button->setText("Sending...");
    QDir::setCurrent(str + "/pixel-database/");
    QtConcurrent::run(put_files,QString(A.get_username())+"/Request.txt",QString(A.get_username())+"/Request.txt");
    QtConcurrent::run(put_files,QString(A.get_username())+"/notification.txt",QString(A.get_username())+"/notification.txt");
    QtConcurrent::run(put_files,QString(A.get_username())+"/friends.txt",QString(A.get_username())+"/friends.txt");
    QMessageBox::information(this,"The request has been accepted","Accepted");
    extract_files(1,requested_user);
    fp=fopen("friends.txt","a");
    fprintf(fp,"%s\n",A.get_username());
    fclose(fp);
    fp=fopen("notification.txt","a");
    fprintf(fp,"%s has accepted your request\n",A.get_username());
    fclose(fp);
    qDebug()<<"Ex for Upl";
    extract_files(2,requested_user);
    remove("friends.txt");
    remove("notification.txt");
    //-----------------
}

void Notifications_Page::on_Accept_Request_Button_clicked()
{
    qDebug()<<"In Accept Request";
    QtConcurrent::run(this,&Notifications_Page::request_accepted);
    /*Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();*/
}

void Notifications_Page::request_declined()
{
    int file_empty_status=0;
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    char requested_users_name[16];
    //char notification_string[100];
    FILE *fp;
    fp=fopen("Request.txt","a+");
    FILE *fptr=fopen("Data.txt","w");
    if(fgets(requested_users_name,16, fp)==NULL)
    {
        fprintf(fp,"");
        file_empty_status=1;
    }
    while(file_empty_status==0)
    {
        if (fgets(requested_users_name,16, fp) == NULL)
        {
            file_empty_status=1;
            qDebug()<<requested_users_name;
            break;
        }
        fprintf(fptr,"%s",requested_users_name);
    }
    fclose(fp);
    fclose(fptr);
    remove("Request.txt");
    rename("Data.txt","Request.txt");
    fp=fopen("notification.txt","w");
    fclose(fp);
    QDir::setCurrent(str + "/pixel-database");
    QtConcurrent::run(put_files,QString(A.get_username())+"/Request.txt",QString(A.get_username())+"/Request.txt");
    QtConcurrent::run(put_files,QString(A.get_username())+"/notification.txt",QString(A.get_username())+"/notification.txt");
    QMessageBox::warning(this,"Request Declined","You declined the request");
    //done(4);
}

void Notifications_Page::on_Delete_Request_clicked()
{
    QtConcurrent::run(this,&Notifications_Page::request_declined);
/*    Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();*/
}
