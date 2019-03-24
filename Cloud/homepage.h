#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QDialog>
#include <QObject>
#include "account.h"
#include <QVector>
#include <QDir>
#include <QFile>

namespace Ui {
class HomePage;
}

class HomePage : public QDialog
{
    Q_OBJECT

public:
    explicit HomePage(char username[16], QWidget *parent = nullptr);
    ~HomePage();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

    void on_prev_pic_clicked();

    void on_next_pic_clicked();

private:
        Ui::HomePage *ui;
        Account A;
        QVector <QString> image_path_vector;
        QVector <QString> image_username;
        int current_pic;
        //Ui::HomePage *ui;
        void load_friends_data();
};

#endif // HOMEPAGE_H
