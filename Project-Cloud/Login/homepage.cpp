//#include "homepage.h"
#include "homepage.h"
#include "ui_homepage.h"
#include <QPixmap>
HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_pushButton_clicked()
{

    int w=ui->label_5->width();
    int h=ui->label_5->height();
    QPixmap pix = QPixmap("/home/harryhunt/123/user.png");
    ui->label_5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
