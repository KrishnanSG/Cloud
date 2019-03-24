#ifndef LOADING_H
#define LOADING_H

#include <QDialog>
#include <QMovie>
#include <QFutureSynchronizer>
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
    bool download_started = false;
    QMovie *movie;// = new QMovie(":/giphy.gif");
    void input_path_for_movie(QString path)
    {
        movie = new QMovie(path);
    }

};
#endif // LOADING_H
