#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "ui_homepage.h"
#include <QPixmap>
#include <QDebug>
#include <QProcess>

HomePage::HomePage(char username[16], QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    A.input(username);
    FILE *friends_list;
    char friends_folder[10];
    char t[16];
    strcpy(t,A.get_username());
    QDir::setCurrent(QDir::homePath()+"/pixel-database/"+QString(A.get_username()));
    friends_list = fopen("friends.txt","r");
    QDir dir;
    if(dir.exists(QDir::homePath() + "/pixel-database/Feedpage_pics"))
    {
        QDir deleting(QDir::homePath() + "/pixel-database/Feedpage_pics");
        deleting.removeRecursively();
    }
    QDir::setCurrent(QDir::homePath()+"/pixel-database");
    dir.mkpath(QDir::homePath()+"/pixel-database/"+QString("Feedpage_pics"));
    while(fscanf(friends_list,"%s",friends_folder)!=EOF)
    {
        QProcess::execute("copy_pics.sh "+QString(friends_folder)+QString(" Feedpage_pics"));
    }
    fclose(friends_list);

    dir.setPath(QDir::homePath()+"/pixel-database/"+QString("Feedpage_pics"));
    //-
    QFileInfo var;
    foreach (var,dir.entryInfoList()){
        if(var.isFile())
        {
            image_path_vector.append(var.absoluteFilePath());
        }
    }
    image_path_vector.shrink_to_fit();
    int len = image_path_vector.length()+3;
    if(len>3)
    {
        current_pic=len-4;
        qDebug()<<len;
        QPixmap pic(image_path_vector[current_pic]);
        ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
        ui->prev_pic->setEnabled(false);
    }
    else
    {
        ui->display->setText("\tNo Images Uploaded");
        ui->prev_pic->setEnabled(false);
        ui->next_pic->setEnabled(false);
    }
    //-
}

HomePage::~HomePage()
{
    delete ui;
}


void HomePage::on_home_clicked()
{
    HomePage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_search_clicked()
{
    Search_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_cloud_clicked()
{
    Uploadpage H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_notification_clicked()
{
    Notifications_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_user_clicked()
{
    User_Page H(A.get_username());
    H.show();
    this->close();
    H.exec();
}

void HomePage::on_prev_pic_clicked()
{
    int len=image_path_vector.length()+3;
    current_pic++;
    if(current_pic>len-4)
    {
        current_pic=len-4;
    }
    if(current_pic==len-4)
    {
        ui->prev_pic->setEnabled(false);
        ui->next_pic->setEnabled(true);
    }
    else
    {
        ui->prev_pic->setEnabled(true);
        ui->next_pic->setEnabled(true);
    }
    QPixmap pic(image_path_vector[current_pic]);
    ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
}

void HomePage::on_next_pic_clicked()
{
    current_pic--;
    if(current_pic<0)
    {
        current_pic=0;
    }
    if(current_pic==0)
    {
        ui->next_pic->setEnabled(false);
        ui->prev_pic->setEnabled(true);
    }
    else
    {
        ui->prev_pic->setEnabled(true);
        ui->next_pic->setEnabled(true);
    }
    QPixmap pic(image_path_vector[current_pic]);
    ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
}
