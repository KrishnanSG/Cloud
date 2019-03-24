#include "loading.h"
#include "ui_loading.h"
#include <QtConcurrent/QtConcurrent>
#include <QDebug>
Loading::Loading(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loading)
{
    ui->setupUi(this);

}

void Loading::task_started(QString s)
{
    ui->label_2->setText(s);
    ui->label->setMovie(movie);
    ui->label->show();
    show();
    if(download_started==false)
        exec();

}

void Loading::task_completed(QString s)
{
    movie->stop();
    ui->label_2->setText(s);
}

Loading::~Loading()
{
    delete ui;
}
