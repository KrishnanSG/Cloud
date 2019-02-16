#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <c++/7/cstring>
#include <c++/7/iostream>

class Account
{
private:
/*
    QString username;
    QString password;*/


public:
    char username[64];
    char password[64];
    char * get_username();
    char * get_password();
    Account(char u[],char p[]);
    Account();
};

#endif // ACCOUNT_H
