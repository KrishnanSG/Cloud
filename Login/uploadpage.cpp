/*#include "homepage.h"
#include "search_page.h"
#include "notifications_page.h"
#include "user_page.h"*/
#include "uploadpage.h"
#include "ui_uploadpage.h"
#include "QProcess"
#include <QFileDialog>
#include <QPixmap>
#include <QDir>
#include "QDebug"
#include <QDateTime>
#include <QtConcurrent/QtConcurrent>

Uploadpage::Uploadpage(char username[16], QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uploadpage)
{
    ui->setupUi(this);
    A.input(username);
}

Uploadpage::~Uploadpage()
{
    delete ui;
}

void upload_img(QString path,QString user)
{
    QProcess::execute("skicka upload "+user+"/"+path+" pixel-database/"+user);
}

void upload_img(QString path)
{
    QProcess::execute("skicka upload "+path+" pixel-database/");
}
void Uploadpage::on_home_clicked()
{
    done(1);
}

void Uploadpage::on_search_clicked()
{
    done(2);
}

void Uploadpage::on_cloud_clicked()
{
    done(3);
}

void Uploadpage::on_notification_clicked()
{
    done(4);
}

void Uploadpage::on_user_clicked()
{
    done(5);
}

void Uploadpage::on_select_image_clicked()
{
    QString str = QDir::homePath();
    QDir::setCurrent(str);
    image_file = QFileDialog::getOpenFileName(this,tr("Select Image"),QDir::homePath(),tr("Images (*.png *.jpg *.bmp *.jpeg)"));
    img_path = QDateTime::currentDateTime().toString("ddMMhhmmss_")+QString(A.get_username());
    QProcess::execute("copy_uploaded.sh "+image_file+" pixel-database/"+QString(A.get_username())+"/"+img_path);
    qDebug()<<QString(A.get_username());
    QDir::setCurrent(str+"/pixel-database");
    QPixmap picture(QString(A.get_username())+"/"+img_path);
    ui->display_image->setPixmap(picture.scaled(ui->display_image->width(),ui->display_image->height(),Qt::KeepAspectRatio));
}
void Uploadpage::on_picture_upload_clicked()
{
    if(image_file.isEmpty())
    {
        QMessageBox::warning(this,"No Image Selected","Please select an image to upload");
    }
    else
    {
        QDir::setCurrent(QDir::homePath()+"/pixel-database/");
        QtConcurrent::run(upload_img,img_path,A.get_username());
        FILE *upload_file;
        upload_file = fopen("database.dat","rb+");
        Account temp_read;
        int record_number=-1;
        while(fread(&temp_read,sizeof(temp_read),1,upload_file))
        {
            record_number++;
            qDebug() <<temp_read.get_username()<<":"<<temp_read.get_image_count();
            if(strcmp(temp_read.get_username(),A.get_username())==0)
            {
                rewind(upload_file);
                fseek(upload_file,sizeof(temp_read)*(record_number),SEEK_SET);
                temp_read.add_image();
                qDebug() << temp_read.get_image_count();
                fwrite(&temp_read,sizeof(temp_read),1,upload_file);
                break;
            }
        }
        QMessageBox::information(this,"Uploaded","Image Uploaded");
        fclose(upload_file);
        QtConcurrent::run(upload_img,QString("database.dat"));
    }
}
