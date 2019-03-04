#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <c++/7/cstring>
#include <c++/7/iostream>
#include <QDebug>
class Account
{
private:
    char username[16];
    char password[16];
public:
    char * get_username();
    char * get_password();
    void input(char[16],char[16]);
  //  Account(char u[64],char p[64]);
    Account();
};

#endif // ACCOUNT_H
