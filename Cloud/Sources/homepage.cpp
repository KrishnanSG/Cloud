#include "homepage.h"
#include "ui_homepage.h"
#include <QPixmap>
#include <QDebug>
#include <QProcess>
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>
#include <fstream>
#include <c++/7/ios>

int download_friend(QString name)      // for files
{
    QProcess::execute("skicka download pixel-database/"+name+" "+name);
    return 0;
}

void HomePage::create_feedpage_data()
{
    std::fstream friends_list;
    QDir::setCurrent(QDir::homePath()+"/pixel-database/"+QString(A.get_username()));
    char friends_folder[10];
    char t[16];
    strcpy(t,A.get_username());
    friends_list.open("friends.txt",std::ios::in);
    try {
        if(!friends_list)
            throw (100);
        while(friends_list>>friends_folder)
        {
            QtConcurrent::run(download_friend,QString(friends_folder));
        }
    } catch (int) {
        QMessageBox::critical(this,"file not open","Error in opening file");
    }
    friends_list.close();
    QDir::setCurrent(QDir::homePath()+"/pixel-database/");
    /// starts downloading friends data
}
/*

 we downloaded the friends data above
 again by going to our current directory and friends list
 with their updates we processing the user's homepage


 */
HomePage::HomePage(char username[16], QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    A.input(username);
    std::fstream friends_list;
    char friends_folder[10];
    QDir::setCurrent(QDir::homePath()+"/pixel-database/"+QString(A.get_username()));
    QDir dir;
    dir.mkpath(QDir::homePath()+"/pixel-database/"+QString("Feedpage_pics"));
    dir.setPath(QDir::homePath()+"/pixel-database/"+QString("Feedpage_pics"));
    static int prev_count=0;
    create_feedpage_data();
    try {
        friends_list.open("friends.txt",std::ios::in);
        if(!friends_list)
            throw(100);
        while(friends_list>>friends_folder)
        {
            QProcess::execute("copy_pics.sh "+QString(friends_folder)+QString(" Feedpage_pics"));
        }
        friends_list.close();

    } catch (int) {
        QMessageBox::critical(this,"File not open","Error in opening file");
    }

/*
 by getting the data path in a vector data structure we are showing the other
 user uploads by traversing the vector using QPixmap in the following lables
*/
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
        ui->prev_pic->hide();
    }
    else
    {
        ui->display->setText("\tNo Images Uploaded");
        ui->prev_pic->hide();
        ui->next_pic->hide();
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
        ui->prev_pic->hide();
        ui->next_pic->show();
    }
    else
    {
        ui->prev_pic->show();
        ui->next_pic->show();
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
        ui->next_pic->hide();
        ui->prev_pic->show();
    }
    else
    {
        ui->prev_pic->show();
        ui->next_pic->show();
    }
    QPixmap pic(image_path_vector[current_pic]);
    ui->display_username->setText(image_username[current_pic]);
    ui->display->setPixmap(pic.scaled(ui->display->width(),ui->display->height(),Qt::KeepAspectRatio));
}
/*
 here when up or down button is clicked we moving the vector
 pointer forth and back and the process is carried out


 */
