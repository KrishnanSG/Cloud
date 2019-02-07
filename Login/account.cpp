#include "account.h"
using namespace std;
Account::Account(char u[], char p[])
{
    strcpy(username,u);
    strcpy(password,p);
}

Account::Account()
{
    strcpy(username,"");
    strcpy(password,"");
}

char *Account::get_username()
{
    return username;
}

char *Account::get_password()
{
    return password;
}
