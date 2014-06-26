#ifndef DELTAFORCE_H
#define DELTAFORCE_H

#include <QMainWindow>


namespace Ui {
class DeltaForce;
}

class DeltaForce : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeltaForce(QWidget *parent = 0);
    ~DeltaForce();

    void Lcd_Display(int);
    void Lcd_Display(char*);
    double days_remaining;
    int registration;


private slots:


    void on_DeltaForce_windowIconTextChanged(const QString &iconText);

    void on_DeltaForce_customContextMenuRequested(const QPoint &pos);

    void on_DeltaForce_iconSizeChanged(const QSize &iconSize);
    void about();

    void on_pushButton_3_clicked();

    void on_action_About_triggered();

    void on_action_Exit_triggered();

    void on_lcdNumber_overflow();

    void UpdateLcd();

    void on_pushButton_2_clicked();
    void on_action_Register_triggered();

    void on_pushButton_4_clicked();

    void register_message();

    void on_pushButton_clicked();



signals:
    void showOtherWindow();

private:
    Ui::DeltaForce *ui;
};

#endif // DELTAFORCE_H
