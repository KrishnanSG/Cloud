#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>

class Account
{
private:
    QString username;
    QString password;
public:
    QString get_username();
    QString get_password();

    Account();
    Account(QString username,QString password);
};

#endif // ACCOUNT_H
