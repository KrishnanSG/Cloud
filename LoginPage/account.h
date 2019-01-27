#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
class ACCOUNT
{
    QString username;
    QString password;
    QString pin;
public:
    QString get_username();
    QString get_password();
    QString get_pin();
    void setdata(QString,QString,QString);
    ACCOUNT();
    ~ACCOUNT();
};

#endif // ACCOUNT_H
