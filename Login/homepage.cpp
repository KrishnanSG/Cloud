#include "homepage.h"
#include "ui_homepage.h"
#include <QPixmap>
#include <QDebug>
#include <QProcess>
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>

int download_friend(QString name)      // for files
{
    QProcess::execute("skicka download pixel-database/"+name+" "+name);
    return 0;
}

void HomePage::load_friends_data()
{
    FILE *friends_list;
    QDir::setCurrent(QDir::homePath()+"/pixel-database/"+QString(A.get_username()));
    char friends_folder[10];
    char t[16];
    strcpy(t,A.get_username());
    friends_list = fopen("friends.txt","r");
    while(fscanf(friends_list,"%s",friends_folder)!=EOF)
    {
        QtConcurrent::run(download_friend,QString(friends_folder));
    }
    fclose(friends_list);
    QDir::setCurrent(QDir::homePath()+"/pixel-database/");
    /// starts downloading friends data
}

HomePage::HomePage(char username[16], QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    A.input(username);
    FILE *friends_list;
    char friends_folder[10];
    QDir::setCurrent(QDir::homePath()+"/pixel-database/"+QString(A.get_username()));
    friends_list = fopen("friends.txt","r");
    QDir dir;
    dir.mkpath(QDir::homePath()+"/pixel-database/"+QString("Feedpage_pics"));
    dir.setPath(QDir::homePath()+"/pixel-database/"+QString("Feedpage_pics"));
    static int prev_count=0;
    load_friends_data();
    while(fscanf(friends_list,"%s",friends_folder)!=EOF)
    {
        QProcess::execute("copy_pics.sh "+QString(friends_folder)+QString(" Feedpage_pics"));
    }
    fclose(friends_list);


    //-
    QFileInfo var;
    foreach (var,dir.entryInfoList()){
        if(var.isFile())
        {
            image_path_vector.append(var.absoluteFilePath());
            image_username.append(var.fileName().mid(11));
        }
    }
    image_path_vector.shrink_to_fit();
    int new_count=image_path_vector.length();
    if(new_count-prev_count)
    {
        show();
        if(new_count-prev_count==1)
            QMessageBox::information(this,"New Picture","Your friend has uploaded a picture");
        else
            QMessageBox::information(this,"New Pictures","Your friends have uploaded "+QString(new_count-prev_count+48)+ " pictures");
    }
    qDebug() <<QDir::currentPath()<<" FeedPage New Images:"<<new_count-prev_count;
    QDir::setCurrent(QDir::homePath()+"/pixel-database");
    if(new_count-prev_count)
        prev_count=new_count;
    int len = image_path_vector.length()+3;
    if(len>3)
    {
        current_pic=len-4;
        qDebug()<<len;
        QPixmap pic(image_path_vector[current_pic]);
        ui->display_username->setText(image_username[current_pic]);
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
    done(1);
}

void HomePage::on_search_clicked()
{
    done(2);
}

void HomePage::on_cloud_clicked()
{
    done(3);
}

void HomePage::on_notification_clicked()
{
    done(4);
}

void HomePage::on_user_clicked()
{
    done(5);
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
    ui->display_username->setText(image_username[current_pic]);
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
    ui->display_username->setText(image_username[current_pic]);
    ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
}
