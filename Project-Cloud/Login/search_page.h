#ifndef SEARCH_PAGE_H
#define SEARCH_PAGE_H

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

private:
    Ui::Search_Page *ui;
};

#endif // SEARCH_PAGE_H
