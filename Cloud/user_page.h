#ifndef USER_PAGE_H
#define USER_PAGE_H

#include <QDialog>
#include <QPixmap>
#include "account.h"
#include <QVector>

namespace Ui {
class User_Page;
}

class User_Page : public QDialog
{
    Q_OBJECT

public:
    explicit User_Page(char username[16],QWidget *parent = nullptr);
    ~User_Page();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

    void on_friends_clicked();

    void on_prev_pic_clicked();

    void on_next_pic_clicked();

private:
    Ui::User_Page *ui;
    Account A;
    QVector <QString> image_path_vector;
    int current_pic;
};

#endif // USER_PAGE_H
