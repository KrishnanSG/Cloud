/*#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
*/
#include "user_page.h"
#include "ui_user_page.h"
#include "friends.h"
#include <QDir>
#include <QFile>
#include <QDebug>

User_Page::User_Page(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_Page)
{
    A.input(username);
    QDir dir;
    dir.setPath(QDir::homePath()+"/pixel-database/"+QString(A.get_username()));
    QFileInfo var;
    foreach (var,dir.entryInfoList()){
        if(var.isFile())
        {
            image_path_vector.append(var.absoluteFilePath());
        }
    }
    image_path_vector.shrink_to_fit();
    int len = image_path_vector.length();
    ui->setupUi(this);
    ui->display_username->setText(A.get_username());
    if(len>3)
    {
        current_pic=len-4;
        qDebug()<<len;
        QPixmap pic(image_path_vector[current_pic]);
        ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
        ui->prev_pic->hide();
    }
    else
    {
        ui->display->setText("\tNo Images Uploaded");
        ui->prev_pic->hide();
        ui->next_pic->hide();
    }
}

User_Page::~User_Page()
{
    delete ui;
}


void User_Page::on_home_clicked()
{
    done(1);
}

void User_Page::on_search_clicked()
{
    done(2);
}

void User_Page::on_cloud_clicked()
{
    done(3);
}

void User_Page::on_notification_clicked()
{
    done(4);
}

void User_Page::on_user_clicked()
{
    done(5);
}

void User_Page::on_friends_clicked()
{
    Friends H(A.get_username());
    H.show();
    //this->close();
    H.exec();
}

void User_Page::on_prev_pic_clicked()
{
    int len=image_path_vector.length();
    current_pic++;
    if(current_pic>len-4)
    {
        current_pic=len-4;
    }
    if(current_pic==len-4)
    {
        ui->prev_pic->hide();
        ui->next_pic->show();
    }
    else
    {
        ui->prev_pic->show();
        ui->next_pic->show();
    }
    QPixmap pic(image_path_vector[current_pic]);
    ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
}

void User_Page::on_next_pic_clicked()
{
    current_pic--;
    if(current_pic<0)
    {
        current_pic=0;
    }
    if(current_pic==0)
    {
        ui->next_pic->hide();
        ui->prev_pic->show();
    }
    else
    {
        ui->prev_pic->show();
        ui->next_pic->show();
    }
    QPixmap pic(image_path_vector[current_pic]);
    ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
}
