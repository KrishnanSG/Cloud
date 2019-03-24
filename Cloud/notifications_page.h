#ifndef NOTIFICATIONS_PAGE_H
#define NOTIFICATIONS_PAGE_H

#include <QDialog>
#include "account.h"

namespace Ui {
class Notifications_Page;
}

class Notifications_Page : public QDialog
{
    Q_OBJECT

public:
    explicit Notifications_Page(char username[16],QWidget *parent = nullptr);
    ~Notifications_Page();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

    void on_Accept_Request_Button_clicked();

    void on_Delete_Request_clicked();

private:
    Ui::Notifications_Page *ui;
    Account A;
    void request_accepted();
    void request_declined();
};

#endif // NOTIFICATIONS_PAGE_H
