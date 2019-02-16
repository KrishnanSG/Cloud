#ifndef LOGIN_SIGNUP_H
#define LOGIN_SIGNUP_H

#include <QDialog>
#include "loading.h"
#include <QFutureWatcher>

namespace Ui {
class Login_SignUp;
}

class Login_SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit Login_SignUp(QWidget *parent = nullptr);
    ~Login_SignUp();

private slots:
    void on_login_clicked();

    void on_create_clicked();

    void stop_animation();

private:
    Ui::Login_SignUp *ui;
    Loading L;
    QFutureWatcher<int> watcher;
    void threading();
};

#endif // LOGIN_SIGNUP_H
