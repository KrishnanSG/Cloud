#include "account.h"
using namespace std;
Account::Account()
{
    strcpy(username," ");
    strcpy(password," ");
    image_count=0;
}

char *Account::get_username()
{
    return username;
}

char *Account::get_password()
{
    return password;
}

int Account::get_image_count()
{
    return image_count;
}

void Account::add_image()
{
    image_count++;
}

void Account::input(char u[16], char p[16])
{
    strcpy(username,u);
    strcpy(password,p);
}

void Account::input(char u[16])
{
    strcpy(username,u);
}
/*
 here we storing the user's account details such as username
 password ,image_count
*/
