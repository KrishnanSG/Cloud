#ifndef CREATE_H
#define CREATE_H
#include <QDialog>
namespace Ui {
class Create;
}

class Create : public QDialog
{
    Q_OBJECT

public:
    explicit Create(QWidget *parent = nullptr);
    ~Create();

private slots:
    void on_upload_clicked();

    void on_create_clicked();

private:
    Ui::Create *ui;
};

#endif // CREATE_H
