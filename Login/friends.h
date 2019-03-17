#ifndef FRIENDS_H
#define FRIENDS_H

#include <QDialog>
#include "account.h"

namespace Ui {
class Friends;
}

class Friends : public QDialog
{
    Q_OBJECT

public:
    explicit Friends(char username[16],QWidget *parent = nullptr);
    ~Friends();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

private:
    Ui::Friends *ui;
    Account A;
};

#endif // FRIENDS_H
