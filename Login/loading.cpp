#include "loading.h"
#include "ui_loading.h"
#include <QtConcurrent/QtConcurrent>
Loading::Loading(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loading)
{
    ui->setupUi(this);

}
void Loading::download()
{
    ui->label->setMovie(movie);
    ui->label->show();
    show();
    exec();
}

void Loading::downloaded()
{
    movie->stop();
    ui->label_2->setText("Files Uploaded");
}

Loading::~Loading()
{
    delete ui;
}
