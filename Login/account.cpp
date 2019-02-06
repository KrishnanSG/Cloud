#include "account.h"

QString Account::get_username()
{
    return username;
}

QString Account::get_password()
{
    return password;
}

Account::Account()
{
    username="";
    password="";
}

Account::Account(QString username, QString password)
{
    this->username=username;
    this->password=password;
}
