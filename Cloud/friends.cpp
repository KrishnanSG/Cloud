#include "homepage.h"
#include "search_page.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include "friends.h"
#include "ui_friends.h"

Friends::Friends(char username[16],QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Friends)
{
    Account A;
    A.input(username);
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+A.get_username());
    ui->setupUi(this);
    A.input(username);
    QString filename="friends.txt";
    QFile file(filename);
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QString text=in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
    QDir::setCurrent(str+"/pixel-database");
}

Friends::~Friends()
{
    delete ui;
}
