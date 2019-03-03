#ifndef SEARCH_PAGE_H
#define SEARCH_PAGE_H
#include "homepage.h"
#include "uploadpage.h"
#include "notifications_page.h"
#include "user_page.h"
#include <QDialog>

namespace Ui {
class Search_Page;
}

class Search_Page : public QDialog
{
    Q_OBJECT

public:
    explicit Search_Page(QWidget *parent = nullptr);
    ~Search_Page();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

private:
    Ui::Search_Page *ui;
};

#endif // SEARCH_PAGE_H
