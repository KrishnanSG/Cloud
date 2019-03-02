#ifndef LOADING_H
#define LOADING_H

#include <QDialog>
#include <QMovie>
namespace Ui {
class Loading;
}

class Loading : public QDialog
{
    Q_OBJECT

public:
    explicit Loading(QWidget *parent = nullptr);
    void task_started(QString);
    void task_completed(QString);
    ~Loading();


private:
    Ui::Loading *ui;
public:
    QMovie *movie = new QMovie(":/giphy.gif");

};
#endif // LOADING_H
