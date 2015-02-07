#include "mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
///////////////////////

    process_file = QDir::tempPath() + QString("tmp_file.txt");
      process.setProcessChannelMode(QProcess::MergedChannels);
      process.setStandardOutputFile(process_file);
      connect(&process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(executeFinished()));
      connect(&process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(executeError(QProcess::ProcessError)));

      process_timer.setInterval(100);
      process_timer.setSingleShot(false);
      connect(&process_timer, SIGNAL(timeout()), this, SLOT(appendOutput()));

/////////////////////



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

     ui.textBrowser->setText("Removing the \"gesture.key\" keyfile from your device.");
     ui.progressBar->setValue(30);
     ui.textBrowser_5->append("Executing the command please wait. \nMake sure your device is rooted for this to work. \n");
     ui.progressBar->setValue(80);
     execute("adb shell rm /data/system/gesture.key");
     ui.progressBar->setValue(100);
     //ui.textBrowser_5->append("Command completed\n");
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
    ui.textBrowser_2->setText("Setting the keyvalues to 0.");
    ui.progressBar_2->setValue(30);
    ui.textBrowser_5->append("Executing the command please wait. \n");
    execute("adb shell echo sqlite3 /data/data/com.android.providers.settings/databases/settings.db \"update system set value=0 where name='lock_pattern_autolock';\ update system set value=0 where name='lockscreen.lockedoutpermanently';\"");

    ui.progressBar_2->setValue(100);
   // ui.textBrowser_5->append("Command completed.\n");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui.progressBar_3->setValue(0);

    ui.textBrowser_3->setText("Removing the keys.");
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

     ui.progressBar->setValue(100);

     ui.progressBar_2->setValue(0);

    ui.progressBar_2->setValue(100);

    ui.progressBar_3->setValue(0);

    ui.textBrowser_3->setText("data3");
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
void MainWindow::execute(QString command)
{
    QFile::remove(process_file);
    process_file_pos = 0;
    process.start(command);
    process_timer.start();
}

void MainWindow::appendOutput()
{
  QFile file(process_file);
  if (!file.open(QIODevice::ReadOnly)) return;

  if (file.size()>process_file_pos)
  {
    file.seek(process_file_pos);
     ui.textBrowser_5->moveCursor(QTextCursor::End);
    ui.textBrowser_5->insertPlainText(file.readAll());
    process_file_pos = file.pos();
  }
  file.close();
}

void MainWindow::executeFinished()
{
  process_timer.stop();
  appendOutput();
}

void MainWindow::executeError(QProcess::ProcessError)
{
    process_timer.stop();
    appendOutput();
}


void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_pushButton_6_clicked()
{

   QString text=ui.textEdit->toPlainText();
   ui.textBrowser_5->append("=======================User Command=======================\n");
   ui.textBrowser_5->append("\n"+text);
   ui.textBrowser_5->append("==========================================================\n");

   execute("adb shell "+text);


   ui.textEdit->clear();
}
