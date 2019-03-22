#ifndef UPLOADPAGE_H
#define UPLOADPAGE_H

#include <QDialog>
#include <QMessageBox>
#include "account.h"

namespace Ui {
class Uploadpage;
}

class Uploadpage : public QDialog
{
    Q_OBJECT

public:
    explicit Uploadpage(char username[16],QWidget *parent = nullptr);

    ~Uploadpage();

private slots:

    void on_home_clicked();

    void on_search_clicked();

    void on_cloud_clicked();

    void on_notification_clicked();

    void on_user_clicked();


    void on_select_image_clicked();

    void on_picture_upload_clicked();

private:
    Ui::Uploadpage *ui;
    QString image_file;
    Account A;
    QString img_path;
};

#endif // UPLOADPAGE_H
