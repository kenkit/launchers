#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_graphicsView_windowIconTextChanged(const QString &iconText);

    void on_actionRegister_triggered();

    void on_lcdNumber_overflow();

    void on_lcdNumber_windowTitleChanged(const QString &title);



    void on_label_2_linkActivated(const QString &link);

    void on_label_linkActivated(const QString &link);

    void on_label_2_linkHovered(const QString &link);

    void on_pushButton_2_clicked();
    void actionAbout();
    void about();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
