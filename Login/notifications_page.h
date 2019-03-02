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

private:
    Ui::Notifications_Page *ui;
};

#endif // NOTIFICATIONS_PAGE_H
