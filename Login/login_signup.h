#ifndef LOGIN_SIGNUP_H
#define LOGIN_SIGNUP_H

#include <QDialog>
#include "loading.h"
#include <QFutureWatcher>
#include <QFutureSynchronizer>
#include <QFileDialog>

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

    void on_upload_clicked();

private:
    Ui::Login_SignUp *ui;
    Loading L;
    QFutureWatcher<int> watcher;
    char current_user[16];
    int login_status=0;    // 0-account doesn't exist 1-password incorrect 2-success
    void load_friends_data();
    void threading();
};

#endif // LOGIN_SIGNUP_H
