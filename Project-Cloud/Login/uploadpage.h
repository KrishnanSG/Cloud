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

private:
    Ui::Uploadpage *ui;
};

#endif // UPLOADPAGE_H
