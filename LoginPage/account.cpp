#include "account.h"

QString ACCOUNT::get_username()
{
    return username;
}

QString ACCOUNT::get_password()
{
    return password;
}

QString ACCOUNT::get_pin()
{
    return pin;
}

void ACCOUNT::setdata(QString u, QString p, QString n)
{
    username=u;
    password=p;
    pin=n;
}

ACCOUNT::ACCOUNT()
{

}

ACCOUNT::~ACCOUNT()
{

}
