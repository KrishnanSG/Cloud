#include "login_signup.h"
#include <QApplication>
#include <QDir>
/* The Application starts here
 * First the application window is initialised and the request is sent to
   the os for processing the gui window signals and actions.
 * An object of Login_Signup is created, this is ensures that when the
   login object is destroyed all the corresponding obecjts are also destroyed
 * Once the login validiation is done the control is transfered to
   the controller object.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_SignUp w;
    return a.exec();
}
