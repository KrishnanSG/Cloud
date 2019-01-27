#include "welcome.h"
#include "ui_welcome.h"
#include <QDir>
#include <QFile>
Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    j=-1;
    static int i=0;
    QDir dir;
    QFileInfo var;
    dir.setPath("/home/krish525/123/");
    foreach (var,dir.entryInfoList()){
        if(var.isFile())
        {
            s[i] = var.absoluteFilePath();
            i++;
        }
    }

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(delay_in_pic()));

}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_clicked()
{
    timer->start(2000);
}

void Welcome::delay_in_pic()
{
    j++;
    if(j>2)
        j=0;
    QPixmap pic(s[j]);
    ui->label->setPixmap(pic.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio));
}

void Welcome::on_pushButton_2_clicked()
{
    timer->stop();
}
