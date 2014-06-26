#ifndef CHILDWIN_H
#define CHILDWIN_H

#include <QMainWindow>

namespace Ui {
class ChildWin;
}

class ChildWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChildWin(QWidget *parent = 0);
    ~ChildWin();

private:
    Ui::ChildWin *ui;
};

#endif // CHILDWIN_H
