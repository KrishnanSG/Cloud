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
    QString str = QDir::homePath();
    QDir::setCurrent(str + "/pixel-database/"+username);
    ui->setupUi(this);
    QString filename="friends.txt";
    QFile file(filename);
    QTextStream in(&file);
    try {
           if(!file.open(QIODevice::ReadOnly)){
            throw 0;
            }
    } catch (int) {
        QMessageBox::warning(this,"..","Error opening file");
    }

    QString text=in.readAll();
    friends_count=text.count();
    try {
        if(friends_count<=0)
            throw -1;
        ui->plainTextEdit->setPlainText(text);
    } catch (int) {
        QMessageBox::warning(this,"..","No Friend to show.\nPlease make friends :)");
    }
    file.close();
    QDir::setCurrent(str+"/pixel-database");
}
/*
 here we are opening the current directory and  our friends.txt and we are
 reading this file for loading our friends list


 */
Friends::~Friends()
{
    delete ui;
}
