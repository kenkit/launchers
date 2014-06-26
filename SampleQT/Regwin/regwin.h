#ifndef REGWIN_H
#define REGWIN_H

#include <QDialog>
#include "funcs.h"
namespace Ui {
class Regwin;
}

class Regwin : public QDialog
{
    Q_OBJECT

public:
     int registration,days_remaining;
    int days,first_run_date,expire_date;
    explicit Regwin(QWidget *parent = 0);
    ~Regwin();
     Funcs Reg;

private slots:
    void on_pushButton_2_clicked();

    void on_plainTextEdit_cursorPositionChanged();

    void on_plainTextEdit_textChanged();

    void on_pushButton_clicked();

    void register_message();
    void Invalid_key();
    void limited_days();
    void on_plainTextEdit_destroyed();

private:
    Ui::Regwin *ui;
};

#endif // REGWIN_H
