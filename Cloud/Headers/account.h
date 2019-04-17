#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <c++/7/cstring>
#include <c++/7/iostream>
#include <QDebug>
class Account
{
private:

    char password[16];

protected:
    char username[16];
    int  image_count;
public:
    char * get_username();
    char * get_password();
    int get_image_count();
    void add_image();
    void input(char [16]);
    void input(char[16],char[16]);
    Account();
};

#endif // ACCOUNT_H
