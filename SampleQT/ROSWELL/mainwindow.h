#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <boost/algorithm/string/case_conv.hpp>
#include <fstream>

using namespace std;
using namespace boost;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int avg_relig,avg_tech,avg_bus,avg_pol,avg_scie;
    int SZ_REL;
    int SZ_TECH;

    int rl;
    int tch;
    int bus;
    int pol;
    int sci;

    string religion[1024];
    string technology[1024];
    string business[1024];
    string politics[1024];
    string science[1024];

   int Read_Dictionaries(char* filename,string DICTIONARY []);
   int Number_Of_Matches(string to_be_found,string find_in_me);
   int Subject_determiner(string str);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_progressBar_valueChanged(int value);
    void evaluator();
    void on_pushButton_clicked();

    void on_textEdit_textChanged();

    void on_textBrowser_textChanged();

    void on_pushButton_2_clicked();

    void on_textBrowser_2_textChanged();

    void on_actionAbout_triggered();

    void on_pushButton_3_clicked();

    void on_actionExit_triggered();

private:
    Ui::MainWindow ui;
};

#endif // MAINWINDOW_H
