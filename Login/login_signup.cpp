#include "login_signup.h"
#include "ui_login_signup.h"
#include "account.h"
#include "homepage.h"
#include "uploadpage.h"
#include "search_page.h"
#include "notifications_page.h"
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>
#include <QDebug>
#include <cstdio>
#include "user_page.h"
#include "friends.h"
void Login_SignUp::threading()
{
    Loading L;
    L.exec();
    L.show();
}

int database()
{
    QProcess::execute("skicka download pixel-database/database.dat database.dat");
    return 0;
}

int database_upload()
{
    QProcess::execute("skicka upload database.dat pixel-database");
    qDebug() << "Uploaded";
    return 0;
}

void Login_SignUp::stop_animation()
{
    qDebug() << watcher.isFinished();
    L.movie->stop();
    L.task_completed("Completed");

    L.close();
    show();
}

Login_SignUp::Login_SignUp(QWidget *parent) :QDialog(parent),ui(new Ui::Login_SignUp)
{
    ui->setupUi(this);
// -------  To check internet connection -------------

    QString str = QDir::homePath();
    QDir working_directory;
    QDir::setCurrent(str);
    QProcess::execute("online.sh");
    FILE *f;
    f=fopen("internet.txt","r");
    int a;
    fscanf(f,"%d",&a);
    fclose(f);
    remove("internet.txt");

    // the script is not writing if we use process
// -------------- *** ----------------------------
    if(a==0)
    {
        QMessageBox m;
        m.critical(this,"No Internet","Please check your internet connection");
        QFile a;
        exit(0);
    }
    else
    {

        //hide();
        QString str = QDir::homePath();
        QDir working_directory;
        QDir::setCurrent(str);
        if(working_directory.exists(str + "/pixel-database"))
        {
            QDir deleting(str + "/pixel-database");
            deleting.removeRecursively();
        }
        working_directory.mkpath("pixel-database");
        QProcess::execute("move.sh skicka pixel-database/skicka");
        QDir::setCurrent(str + "/pixel-database");
        qDebug() << QDir::currentPath();
        connect(&watcher, SIGNAL(finished()), this, SLOT(stop_animation()));
        L.movie->start();
        QFuture<void> f2 = QtConcurrent::run(&this->L,&Loading::task_started,QString("Connecting to Server..."));
        QFuture<int> f1 = QtConcurrent::run(database);
        watcher.setFuture(f1);
    }
}

Login_SignUp::~Login_SignUp()
{
    delete ui;
}

void Login_SignUp::on_login_clicked()
{
    char input_username[16];
    char input_password[16];
    QString input_user = ui->username->text();
    QString input_pass = ui->password->text();

    // -------------- The below code converts QString to char[] ---------------

    std::strcpy(input_username,input_user.toStdString().c_str());
    std::strcpy(input_password,input_pass.toStdString().c_str());

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
        // ---------------- Login Success -------------------

        HomePage h;
        h.show();
        close();
        h.exec();

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
    char input_username[16];
    strcpy(input_username," ");
    char input_password[16];
    strcpy(input_password," ");
    QString input_user = ui->create_username->text();
    QString input_pass = ui->create_password->text();
    QString input_retype_pass = ui->create_retype_password->text();

    bool account_creation = false;

    if(input_user.count()<2 || input_user.count()>10)
    {
        QMessageBox::critical(this,"Invalid Username","Please select a username of length between 2 and 10");
    }
    else
    {
        if(input_pass.count()<2 || input_pass.count()>10)
        {
            QMessageBox::critical(this,"Invalid Password","Please select a password of length between 2 and 10");
        }
        else
        {
            if(input_pass!=input_retype_pass)
            {
                QMessageBox::critical(this,"Password Mismatch","Retype confirm password");
            }
            else
            {
                account_creation = true;
            }

        }
    }
    // -------------- The below code converts QString to char[] ---------------

    if(account_creation==true)
    {

        std::strcpy(input_username,input_user.toStdString().c_str());
        std::strcpy(input_password,input_pass.toStdString().c_str());
        // ----------------------- ********* --------------------------------------
        FILE *reading;
        reading = fopen("database.dat","ab+");
        Account temp_read;
        temp_read.input(input_username,input_password);
        bool creation_status=true;
        rewind(reading);
        while(fread(&temp_read,sizeof (temp_read),1,reading))
        {
            if(strcmp(input_username,temp_read.get_username())==0)
            {
                creation_status=false;
                break;
            }
        }
        fclose(reading);
        temp_read.input(input_username,input_password);
        if(creation_status)
        {
            FILE *writing;
            writing = fopen("database.dat","ab");
            fwrite(&temp_read,sizeof (temp_read),1,writing);
            fclose(writing);
            QMessageBox::information(this,"Created","Account created");

            L.movie->start();
            QFuture<void> f2 = QtConcurrent::run(&this->L,&Loading::task_started,QString("Uploading Data"));
            QFuture<int> f1 = QtConcurrent::run(database_upload);
            watcher.setFuture(f1);
        }
        else
        {
            QMessageBox::critical(this,"Invalid Username","Username exists. Please login or retype username");
            qDebug() << QDir::currentPath();
        }
    }
}

