#include "login_signup.h"
#include <QApplication>
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_SignUp w;
    return a.exec();
}
