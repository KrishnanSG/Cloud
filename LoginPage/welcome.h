#ifndef WELCOME_H
#define WELCOME_H
#include <QTimer>
#include <QDialog>

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_pushButton_clicked();
    void delay_in_pic();

    void on_pushButton_2_clicked();

private:
    Ui::Welcome *ui;
    int j;
    QString s[3];
    QTimer *timer;
};

#endif // WELCOME_H
