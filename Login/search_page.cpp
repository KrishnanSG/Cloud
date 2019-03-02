#include "search_page.h"
#include "ui_search_page.h"

Search_Page::Search_Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_Page)
{
    ui->setupUi(this);
}

Search_Page::~Search_Page()
{
    delete ui;
}
