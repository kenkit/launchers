#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <iostream>

using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_textBrowser_textChanged();

    void on_textBrowser_5_textChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_textBrowser_2_textChanged();

    void on_textBrowser_3_textChanged();

    void on_pushButton_5_clicked();

    void on_progressBar_objectNameChanged(const QString &objectName);

    void on_progressBar_2_valueChanged(int value);

private:
    Ui::MainWindow ui;
};

#endif // MAINWINDOW_H
