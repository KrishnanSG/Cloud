#ifndef FRIENDS_H
#define FRIENDS_H
#include <QDialog>

namespace Ui {
class Friends;
}

class Friends : public QDialog
{
    Q_OBJECT

public:
    explicit Friends(char username[16],QWidget *parent = nullptr);
    ~Friends();

private:
    Ui::Friends *ui;
    int friends_count;
};

#endif // FRIENDS_H
