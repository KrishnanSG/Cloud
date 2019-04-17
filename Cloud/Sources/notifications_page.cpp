#include "notifications_page.h"
#include "ui_notifications_page.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QProcess>
#include <QtConcurrent/QtConcurrent>
#include <fstream>
#include <c++/7/ios>

/*
 In notification page we are opening the user's notification.txt
 and reading the messages and printing the required messages.
 */
void put_files(QString local,QString remote)      // for files
{
    QProcess::execute("skicka upload "+local+ " pixel-database/"+remote);
}


Notifications_Page::Notifications_Page(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notifications_Page)
{
    ui->setupUi(this);
    ui->display_notifications->setReadOnly(true);
    A.input(username);
    QString str = QDir::homePath();
    QDir::setCurrent(str+"/pixel-database");
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
    std::fstream fp;
    try {
        fp.open("Request.txt",std::ios::in);
        if(!fp)
            throw 100;
        char requested_user[16];
        strcpy(requested_user,"");
        fp>>requested_user;
        fp.close();
        if(strcmp(requested_user,"")==0)
        {
            //ui->display_profile->hide();
            ui->display_username->hide();
            ui->Accept_Request_Button->hide();
            ui->Delete_Request->hide();
        }
        ui->display_username->setText(QString(requested_user));
    } catch (int) {
        QMessageBox::critical(this,"File not open","Error while opening");
    }
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
// extracting the user friend with notification.txt
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
/*
 if the request here is accepted we are opening that user and friends
 list and adding both names in the corresponding file

 */
void Notifications_Page::request_accepted()
{
    qDebug()<<"In request accepted";
    std::fstream fp;
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    fp.open("Request.txt",std::ios::in | std::ios::ate);
    char requested_user[16];
    fp<<requested_user;
    fp.close();
    QString Temp=requested_user;
    QDir::setCurrent(str + "/pixel-database");
    fp.open("database.dat",std::ios::in | std::ios::ate);
    Account temp;
    fp.seekg(0,std::ios::beg);
    char requested_users_name[16];
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    fp.close();
    fp.open("friends.txt",std::ios::in | std::ios::ate);
    fp<<requested_user;
    fp.close();
    fp.open("Request.txt",std::ios::in | std::ios::ate);
    std::fstream fptr;
    fptr.open("Data.txt",std::ios::out);
    fp>>requested_users_name;
    while(fp>>requested_users_name)
    {
        fptr<<requested_users_name;
    }
    fp.close();
    fptr.close();
    remove("Request.txt");
    rename("Data.txt","Request.txt");
    fp.open("notification.txt",std::ios::out);
    fp.close();

    qDebug()<<QDir::currentPath();

    //------Sending to another user ------------

    QDir::setCurrent(str + "/pixel-database/");
    QtConcurrent::run(put_files,QString(A.get_username())+"/Request.txt",QString(A.get_username())+"/Request.txt");
    QtConcurrent::run(put_files,QString(A.get_username())+"/notification.txt",QString(A.get_username())+"/notification.txt");
    QtConcurrent::run(put_files,QString(A.get_username())+"/friends.txt",QString(A.get_username())+"/friends.txt");
    QMessageBox::information(this,"The request has been accepted","Accepted");
    extract_files(1,requested_user);
    fp.open("friends.txt",std::ios::app);
    fp<<A.get_username();
    fp.close();
    fp.open("notification.txt",std::ios::app);
    fp<<A.get_username()<<" has accepted your request\n";
    fp.close();
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
}

void Notifications_Page::request_declined()
{
    int file_empty_status=0;
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    char requested_users_name[16]="";
    std::fstream fp,fptr;
    fp.open("Request.txt",std::ios::in | std::ios::app);
    fptr.open("Data.txt",std::ios::out);
    fp>>requested_users_name;
    while(fp>>requested_users_name)
    {
        fptr<<requested_users_name;
    }
    fp.close();
    fptr.close();
    remove("Request.txt");
    rename("Data.txt","Request.txt");
    fp.open("notification.txt",std::ios::out);
    fp.close();
    QDir::setCurrent(str + "/pixel-database");
    QtConcurrent::run(put_files,QString(A.get_username())+"/Request.txt",QString(A.get_username())+"/Request.txt");
    QtConcurrent::run(put_files,QString(A.get_username())+"/notification.txt",QString(A.get_username())+"/notification.txt");
    QMessageBox::warning(this,"Request Declined","You declined the request");

}
/*
  if we reject the request the corresponding request is deleted from the file

 */
void Notifications_Page::on_Delete_Request_clicked()
{
    QtConcurrent::run(this,&Notifications_Page::request_declined);
    // Threading
}
