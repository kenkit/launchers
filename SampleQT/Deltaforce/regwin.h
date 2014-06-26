#ifndef REGWIN_H
#define REGWIN_H

#include <QDialog>

namespace Ui {
class Regwin;
}

class Regwin : public QDialog
{
    Q_OBJECT

public:
    explicit Regwin(QWidget *parent = 0);
    ~Regwin();

private:
    Ui::Regwin *ui;
};

#endif // REGWIN_H
