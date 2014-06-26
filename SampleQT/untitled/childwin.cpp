#include "childwin.h"
#include "ui_childwin.h"

ChildWin::ChildWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChildWin)
{
    ui->setupUi(this);
}

ChildWin::~ChildWin()
{
    delete ui;
}
