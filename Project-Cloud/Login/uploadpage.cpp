#include "uploadpage.h"
#include "ui_uploadpage.h"

Uploadpage::Uploadpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uploadpage)
{
    ui->setupUi(this);
}

Uploadpage::~Uploadpage()
{
    delete ui;
}
