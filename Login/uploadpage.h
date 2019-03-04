#ifndef UPLOADPAGE_H
#define UPLOADPAGE_H

#include <QDialog>

namespace Ui {
class Uploadpage;
}

class Uploadpage : public QDialog
{
    Q_OBJECT

public:
    explicit Uploadpage(QWidget *parent = nullptr);
    ~Uploadpage();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();

private:
    Ui::Uploadpage *ui;
};

#endif // UPLOADPAGE_H
