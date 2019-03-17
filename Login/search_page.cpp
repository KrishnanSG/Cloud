#include "search_page.h"
#include "ui_search_page.h"
#include <QDir>
Search_Page::Search_Page(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_Page)
{
    A.input(username);
    ui->setupUi(this);
    ui->make_friend_button->hide();
    ui->view_profile_button->hide();
    ui->display_profile_label->hide();
    ui->display_username_label->hide();
}

Search_Page::~Search_Page()
{
    delete ui;
}


void Search_Page::on_home_clicked()
{
    HomePage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_search_clicked()
{
    Search_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_cloud_clicked()
{
    Uploadpage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_notification_clicked()
{
    Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void Search_Page::on_user_clicked()
{
    User_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}


void Search_Page::on_make_friend_button_clicked()
{
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+B.get_username());
    FILE *fp;
    fp=fopen("Request.txt","a");
    fprintf(fp,"%s\n",A.get_username());
    fclose(fp);
    fp=fopen("notification.txt","a");
    fprintf(fp,"%s has sent you a request\n",A.get_username());
    fclose(fp);
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
        ui->display_profile_label->show();
        ui->display_username_label->show();
        int img_count;
        int friend_found_status=0;
        FILE *fptr;
        fptr = fopen("friends.dat","ab+");
        Account temp_read;
        rewind(fptr);
        while(fscanf(fp,"%s%d",input_username,&img_count)!=EOF)
        {
            if(strcmp(input_username,temp_read.get_username())==0)
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
    }
    else
    {
        QMessageBox::critical(this,"Invalid Username","Username does not exist");
    }
}
