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
    char username[32];
    char password[32];
    char * get_username();
    char * get_password();
    Account(char u[],char p[]);
    Account();
};

#endif // ACCOUNT_H
