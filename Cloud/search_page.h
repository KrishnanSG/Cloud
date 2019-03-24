#ifndef SEARCH_PAGE_H
#define SEARCH_PAGE_H
/*#include "homepage.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"*/
#include "account.h"
#include <QMessageBox>
#include <QDialog>
namespace Ui {
class Search_Page;
}

class Search_Page : public QDialog
{
    Q_OBJECT

public:
    explicit Search_Page(char username[16],QWidget *parent = nullptr);
    ~Search_Page();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

    void on_search_button_clicked();

    void on_make_friend_button_clicked();

    void on_view_profile_button_clicked();

private:
    Ui::Search_Page *ui;
    Account A,B;
    QString username;
    void send_notification();
};

#endif // SEARCH_PAGE_H
