#include "search_page.h"
#include "user_page.h"
#include "ui_search_page.h"
#include <QDir>
#include <QtConcurrent/QtConcurrent>
#include <fstream>
#include <c++/7/ios>

Search_Page::Search_Page(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_Page)
{
    A.input(username);
    ui->setupUi(this);
    ui->make_friend_button->hide();
    ui->view_profile_button->hide();
    ui->display_username_label->hide();
}

Search_Page::~Search_Page()
{
    delete ui;
}


void Search_Page::on_home_clicked()
{
    done(1);
}

void Search_Page::on_search_clicked()
{
    done(2);
}

void Search_Page::on_cloud_clicked()
{
    done(3);
}

void Search_Page::on_notification_clicked()
{
    done(4);
}

void Search_Page::on_user_clicked()
{
    done(5);
}

void files(int action,QString user)
{
    if(action==1)
    {
        QProcess::execute("skicka download pixel-database/"+user+"/Request.txt" + " Request.txt");
        QProcess::execute("skicka download pixel-database/"+user+"/notification.txt" + " notification.txt");
    }
    else
    {
        QProcess::execute("skicka upload Request.txt pixel-database/"+user+"/Request.txt");
        QProcess::execute("skicka upload notification.txt pixel-database/"+user+"/notification.txt");
    }
}
/*
 for sending request we click the send_notification button
and we adding our user name in the request list
 */
void Search_Page::send_request()
{
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database");
    files(1,B.get_username());
    std::fstream fp;
    fp.open("Request.txt",std::ios::in | std::ios::ate);
    fp<<A.get_username();
    fp.close();
    fp.open("notification.txt",std::ios::in | std::ios::ate);
    fp<<A.get_username()<<" has sent you a request\n";
    fp.close();
    files(2,B.get_username());
    remove("Request.txt");
    remove("notification.txt");
}

void Search_Page::on_make_friend_button_clicked()
{
    QtConcurrent::run(this,&Search_Page::send_request);
    QMessageBox::information(this,"Click Ok to continue","Request Sent");
    ui->make_friend_button->hide();
}
/*
 while searching the username is searched in the database file and
shows the result
 */
void Search_Page::on_search_button_clicked()
{
    int user_found_status=0;
    char input_username[16];
    QString input_user=ui->enter_username_lineEdit->text();
    std::strcpy(input_username,input_user.toStdString().c_str());
    B.input(input_username);
    QDir::setCurrent(QDir::homePath()+"/pixel-database");
    std::fstream fp;
    fp.open("database.dat",std::ios::in | std::ios::out |std::ios::binary);
    Account temp;
    fp.seekg(0,std::ios::beg);
    while(fp.read( (char*) &temp  ,sizeof (temp)))
    {
        if(strcmp(input_username,temp.get_username())==0)
        {
            user_found_status=1;
            break;
        }
        else {
            user_found_status=0;
        }
    }
    fp.close();
    if(user_found_status==1)
    {
        ui->view_profile_button->hide();
        //ui->display_profile_label->show();
        ui->display_username_label->show();
        int friend_found_status=0;
        std::fstream fptr;
        QDir::setCurrent(QDir::homePath()+"/pixel-database/"+A.get_username());
        fptr.open("friends.txt",std::ios::in | std::ios::ate);
        char temp_read[16];
        fptr.seekg(0,std::ios::beg);
        while(fptr>>temp_read)
        {
            if(strcmp(input_username,temp_read)==0)
            {
                friend_found_status=1;
                break;
            }
            else {
                friend_found_status=0;
            }
        }
        fptr.close();
        ui->display_username_label->setText(input_username);
        if(friend_found_status==1)
        {
            ui->make_friend_button->hide();
            ui->view_profile_button->show();
        }
        else
        {
            ui->make_friend_button->show();
            ui->view_profile_button->hide();
        }
        if(strcmp(input_username,A.get_username())==0)
        {
            ui->make_friend_button->hide();
        }
        QDir::setCurrent(QDir::homePath()+"/pixel-database");
    }
    else
    {
        QMessageBox::critical(this,"Invalid Username","Username does not exist");
    }
}
/*
 if we want to see the  profile we click the view profile and
 the user_page of the user is shown
 */
void Search_Page::on_view_profile_button_clicked()
{
    User_Page U(B.get_username(),true);
    U.show();
    U.exec();
}
