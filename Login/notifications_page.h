#ifndef NOTIFICATIONS_PAGE_H
#define NOTIFICATIONS_PAGE_H

#include <QDialog>

namespace Ui {
class Notifications_Page;
}

class Notifications_Page : public QDialog
{
    Q_OBJECT

public:
    explicit Notifications_Page(QWidget *parent = nullptr);
    ~Notifications_Page();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

private:
    Ui::Notifications_Page *ui;
};

#endif // NOTIFICATIONS_PAGE_H
