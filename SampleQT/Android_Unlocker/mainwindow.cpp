#include "mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
}

int run_pipe(char*command_to_be_executed);

QString read_file(void)
{
    QFile file("DATA");
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text));
    QTextStream in(&file);
    QString line;
    do {
        line = in.readLine();

    } while (!in.atEnd());


    file.close();
    return line;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui.retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{

         ui.progressBar->setValue(0);

         run_pipe("adb devices");
         ui.textBrowser->setText(read_file());
         run_pipe("adb shell");
         ui.textBrowser->setText(read_file());
        // run_pipe("cd data/system");
         //ui.textBrowser->setText(read_file());
         //run_pipe("su");
        // ui.textBrowser->setText(read_file());
        // run_pipe("rm *.key");
        // ui.textBrowser->setText(read_file());

         ui.progressBar->setValue(100);
}

void MainWindow::on_textBrowser_textChanged()
{

}

void MainWindow::on_textBrowser_5_textChanged()
{

}



void MainWindow::on_pushButton_2_clicked()
{

    ui.progressBar_2->setValue(0);
    QString data="Running SQL Command Please wait.";
    system("dir");
     ui.textBrowser_2->setText(data);
    ui.progressBar_2->setValue(100);

}

void MainWindow::on_pushButton_3_clicked()
{
    ui.progressBar_3->setValue(0);
    QString data="Running ADB File Removal Command Please Wait.";
    system("adb shell rm /data/system/gesture.key");
     ui.textBrowser_3->setText(data);
     ui.progressBar_3->setValue(100);
}

void MainWindow::on_textBrowser_2_textChanged()
{

}

void MainWindow::on_textBrowser_3_textChanged()
{

}

void MainWindow::on_pushButton_5_clicked()
{
    ui.progressBar->setValue(0);
    QString data1="Wiping key file from Android System Please wait.";
    system("dir");
     ui.textBrowser->setText(data1);
     ui.progressBar->setValue(100);

     ui.progressBar_2->setValue(0);
     QString data2="Running SQL Command Please wait.";
     system("dir");
      ui.textBrowser_2->setText(data2);
    ui.progressBar_2->setValue(100);

    ui.progressBar_3->setValue(0);
     QString data3="Running ADB File Removal Command Please Wait.";
     system("dir");
      ui.textBrowser_3->setText(data3);
    ui.progressBar_3->setValue(100);

      ui.textBrowser_5->setText("Wiping key file from Android System Please wait.\n\
Running SQL Command Please wait.\n\
Running ADB File Removal Command Please Wait.");

}

void MainWindow::on_progressBar_objectNameChanged(const QString &objectName)
{

}

void MainWindow::on_progressBar_2_valueChanged(int value)
{

}

int run_pipe(char*command_to_be_executed)
{

 FILE   *pPipe;
using namespace std;
   ofstream myfile("DATA");
   char   psBuffer[128];


        /* Run DIR so that it writes its output to a pipe. Open this
         * pipe with read text attribute so that we can read it
         * like a text file.
         */
   if( (pPipe = _popen( command_to_be_executed, "rt" )) == NULL )
      exit( 1 );

   /* Read pipe until end of file, or an error occurs. */

   fgets(psBuffer, 128, pPipe);

     myfile<<(psBuffer);



   /* Close pipe and print return value of pPipe. */
       _pclose( pPipe );

   if (feof( pPipe))
   {
     _pclose( pPipe );
   }
   else
   {
     printf( "Error: Failed to read the pipe to the end.\n");
   }
   /*
   char * writable = new char[Pipedat.size() + 1];
   copy(Pipedat.begin(), Pipedat.end(), writable);
   writable[Pipedat.size()] = '\0';
   */
   return  0;
}
