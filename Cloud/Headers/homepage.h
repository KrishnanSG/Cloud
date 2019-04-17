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

    virtual void on_home_clicked();

    virtual void on_search_clicked();

    virtual void on_cloud_clicked();

    virtual void on_notification_clicked();

    virtual void on_user_clicked();

    virtual void on_prev_pic_clicked();

    virtual void on_next_pic_clicked();

private:
        Ui::HomePage *ui;
        Account A;
        QVector <QString> image_username;
        void create_feedpage_data();

protected:

        QVector <QString> image_path_vector;
        int current_pic;
};

#endif // HOMEPAGE_H
