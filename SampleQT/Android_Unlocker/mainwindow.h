#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <iostream>
#include <QProcess>
#include <QDebug>
#include <QTimer>
#include "rapidxml-1.13/rapidxml.hpp"
#include <conio.h>
#include <sstream>
using namespace std;
using namespace rapidxml;




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    typedef struct {
         std::string name;
         std::string params;
    } program ;


    std::vector <program> m_programs;
    void processCommand(int pos);
    explicit MainWindow(QWidget *parent = 0);
    void execute(QString command);

    void execute_2(QString command);
    void execute_3(QString command);
    void execute_4(QString command);
    void execute_5(QString command);


    void select_initial_combo_entry(string menu_file,int selected);
    void get_menu_initial_entry(string menu_file,int item_no);
    string sellected_menu_entry;
    int totalProcessed;
    int totalPrograms;
     int currProgram ;


protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();

    void print_commands(string xml_filename);

    void on_textBrowser_textChanged();

    void on_textBrowser_5_textChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_textBrowser_2_textChanged();

    void on_textBrowser_3_textChanged();

    void on_pushButton_5_clicked();

    void on_progressBar_objectNameChanged(const QString &objectName);

    void on_progressBar_2_valueChanged(int value);

    void executeFinished();

    void executeFinished_2();
    void executeFinished_3();
    void executeFinished_4();
    void executeFinished_5();

    void executeError(QProcess::ProcessError);

    void executeError_2(QProcess::ProcessError);
    void executeError_3(QProcess::ProcessError);
    void executeError_4(QProcess::ProcessError);
    void executeError_5(QProcess::ProcessError);

    void appendOutput();

    void appendOutput_2();
    void appendOutput_3();
    void appendOutput_4();
    void appendOutput_5();




    void on_textEdit_textChanged();

    void on_pushButton_6_clicked();

    void on_frame_4_windowTitleChanged(const QString &title);

    void on_label_6_linkActivated(const QString &link);

    void update_main_label_text(void);
    void set_label_6_adb_text(void);
    void set_label_7_adb_text(void);
    void set_label_8_adb_text(void);
    void set_label_9_adb_text(void);


    void on_label_7_linkActivated(const QString &link);

    void on_label_9_linkActivated(const QString &link);

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_4_clicked();

    void command_executor(string file_name,int commands_no_run);
    void refresh(void);
    void on_pushButton_7_clicked();
    void display_initial_entry(string menu_file);
    void select_from_initial_entry(string menu_file,int item_no);
    void combochanged(int index);
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void combo_2_changed(int index);
    void commandsFinished(void);
    void programFinished(int exitCode);
    void readyRead(void);

private:
    Ui::MainWindow ui;
    QProcess process,process_2,process_3,process_4,process_5;
    QTimer process_timer,process_timer_2,process_timer_3,process_timer_4,process_timer_5;
    QString process_file,process_file_2,process_file_3,process_file_4,process_file_5;
    qint64 process_file_pos,process_file_pos_2,process_file_pos_3,process_file_pos_4,process_file_pos_5;

    int max_commands;
    int brute_force, timeout,s_timeout,to_exit;
    string adb_tools,menu_file;
    bool killed;

};

#endif // MAINWINDOW_H
