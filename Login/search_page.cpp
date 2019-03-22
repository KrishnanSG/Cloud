#include "search_page.h"
#include "ui_search_page.h"
#include <QDir>
#include <QtConcurrent/QtConcurrent>

Search_Page::Search_Page(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_Page)
{
    A.input(username);
    ui->setupUi(this);
    ui->make_friend_button->hide();
    ui->view_profile_button->hide();
    //ui->display_profile_label->hide();
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

void Search_Page::send_notification()
{
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database");//+B.get_username());
    //ui->make_friend_button->setText("Sending...");
    files(1,B.get_username());
    FILE *fp;
    fp=fopen("Request.txt","a");
    fprintf(fp,"%s\n",A.get_username());
    fclose(fp);
    fp=fopen("notification.txt","a");
    fprintf(fp,"%s has sent you a request\n",A.get_username());
    fclose(fp);
    files(2,B.get_username());
    remove("Request.txt");
    remove("notification.txt");
}

void Search_Page::on_make_friend_button_clicked()
{
    QtConcurrent::run(this,&Search_Page::send_notification);
    QMessageBox::information(this,"Click Ok to continue","Request Sent");
    ui->make_friend_button->hide();
}

void Search_Page::on_search_button_clicked()
{
    int user_found_status=0;
    char input_username[16];
    QString input_user=ui->enter_username_lineEdit->text();
    std::strcpy(input_username,input_user.toStdString().c_str());
    B.input(input_username);
    QDir::setCurrent(QDir::homePath()+"/pixel-database");
    FILE *fp;
    fp = fopen("database.dat","ab+");
    Account temp;
    rewind(fp);
    while(fread(&temp,sizeof (temp),1,fp))
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
    fclose(fp);
    if(user_found_status==1)
    {
        ui->view_profile_button->hide();
        //ui->display_profile_label->show();
        ui->display_username_label->show();
        //int img_count;
        int friend_found_status=0;
        FILE *fptr;
        QDir::setCurrent(QDir::homePath()+"/pixel-database/"+A.get_username());
        fptr = fopen("friends.txt","a+");
        char temp_read[16];
        rewind(fptr);
        while(fscanf(fp,"%s",temp_read)!=EOF)
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
        ui->display_username_label->setText(input_username);
        if(friend_found_status==1)
        {
            ui->make_friend_button->hide();
        }
        else {
        ui->make_friend_button->show();
        }
        if(strcmp(input_username,A.get_username())==0)
        {
            ui->make_friend_button->hide();
        }
        ui->view_profile_button->show();
        QDir::setCurrent(QDir::homePath()+"/pixel-database");
    }
    else
    {
        QMessageBox::critical(this,"Invalid Username","Username does not exist");
    }
}
