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

    process_file_2 = QDir::tempPath() + QString("tmp_file2.txt");
    process_file_3 = QDir::tempPath() + QString("tmp_file3.txt");
    process_file_4 = QDir::tempPath() + QString("tmp_file4.txt");
    process_file_5 = QDir::tempPath() + QString("tmp_file5.txt");

      process.setProcessChannelMode(QProcess::MergedChannels);
      process.setStandardOutputFile(process_file);

      process_2.setProcessChannelMode(QProcess::MergedChannels);
      process_2.setStandardOutputFile(process_file_2);

      process_3.setProcessChannelMode(QProcess::MergedChannels);
      process_3.setStandardOutputFile(process_file_3);

      process_4.setProcessChannelMode(QProcess::MergedChannels);
      process_4.setStandardOutputFile(process_file_4);

      process_5.setProcessChannelMode(QProcess::MergedChannels);
      process_5.setStandardOutputFile(process_file_5);

      connect(&process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(executeFinished()));
      connect(&process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(executeError(QProcess::ProcessError)));


      connect(&process_2, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(executeFinished_2()));
      connect(&process_2, SIGNAL(error(QProcess::ProcessError)), this, SLOT(executeError_2(QProcess::ProcessError)));

      connect(&process_3, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(executeFinished_3()));
      connect(&process_3, SIGNAL(error(QProcess::ProcessError)), this, SLOT(executeError_3(QProcess::ProcessError)));


      connect(&process_4, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(executeFinished_4()));
      connect(&process_4, SIGNAL(error(QProcess::ProcessError)), this, SLOT(executeError_4(QProcess::ProcessError)));

      connect(&process_5, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(executeFinished_5()));
      connect(&process_5, SIGNAL(error(QProcess::ProcessError)), this, SLOT(executeError_5(QProcess::ProcessError)));

      process_timer.setInterval(0.1);
      process_timer.setSingleShot(false);



      process_timer_2.setInterval(0.1);
      process_timer_2.setSingleShot(false);

      process_timer_3.setInterval(0.1);
      process_timer_3.setSingleShot(false);

      process_timer_4.setInterval(0.1);
      process_timer_4.setSingleShot(false);

      process_timer_5.setInterval(0.1);
      process_timer_5.setSingleShot(false);

      connect(&process_timer, SIGNAL(timeout()), this, SLOT(appendOutput()));

       connect(&process_timer_2, SIGNAL(timeout()), this, SLOT(appendOutput_2()));
       connect(&process_timer_3, SIGNAL(timeout()), this, SLOT(appendOutput_3()));
       connect(&process_timer_4, SIGNAL(timeout()), this, SLOT(appendOutput_4()));
       connect(&process_timer_5, SIGNAL(timeout()), this, SLOT(appendOutput_5()));

/////////////////////

       QStringList j;
       j<<"1. Unlock Android Patter"<<"2. Reboot Recovery";
       ui.comboBox->addItems(j);



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
    QString text;

    text="wipe userdata";
    execute_2("fastboot "+text);
    set_label_6_adb_text();

}

void MainWindow::on_textBrowser_textChanged()
{

}

void MainWindow::on_textBrowser_5_textChanged()
{

}



void MainWindow::on_pushButton_2_clicked()
{
    /*
    ui.progressBar_2->setValue(0);
    ui.textBrowser_2->setText("Setting the keyvalues to 0.");
    ui.progressBar_2->setValue(30);
    ui.textBrowser_5->append("Executing the command please wait. \n");
    execute("adb shell echo sqlite3 /data/data/com.android.providers.settings/databases/settings.db \"update system set value=0 where name='lock_pattern_autolock';\ update system set value=0 where name='lockscreen.lockedoutpermanently';\"");

    ui.progressBar_2->setValue(100);

    */
   // ui.textBrowser_5->append("Command completed.\n");
}

void MainWindow::on_pushButton_3_clicked()
{
    /*
    ui.progressBar_3->setValue(0);

    ui.textBrowser_3->setText("Removing the keys.");
     ui.progressBar_3->setValue(100);
     */
}

void MainWindow::on_textBrowser_2_textChanged()
{

}

void MainWindow::on_textBrowser_3_textChanged()
{

}

void MainWindow::on_pushButton_5_clicked()
{


/*
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
*/
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


void MainWindow::execute_2(QString command)
{
    QFile::remove(process_file_2);
    process_file_pos_2 = 0;
    process_2.start(command);
    process_timer_2.start();
}
void MainWindow::execute_3(QString command)
{
    QFile::remove(process_file_3);
    process_file_pos_3 = 0;
    process_3.start(command);
    process_timer_3.start();
}
void MainWindow::execute_4(QString command)
{
    QFile::remove(process_file_4);
    process_file_pos_4 = 0;
    process_4.start(command);
    process_timer_4.start();
}
void MainWindow::execute_5(QString command)
{
    QFile::remove(process_file_5);
    process_file_pos_5 = 0;
    process_5.start(command);
    process_timer_5.start();
}
void MainWindow::appendOutput()
{

  update_main_label_text();


}

void MainWindow::appendOutput_2()
{

  set_label_6_adb_text();


}
void MainWindow::appendOutput_3()
{

  set_label_7_adb_text();



}
void MainWindow::appendOutput_4()
{

    set_label_8_adb_text();


}
void MainWindow::appendOutput_5()
{

 set_label_9_adb_text();


}
void MainWindow::executeFinished()
{
  process_timer.stop();
}

void MainWindow::executeFinished_2()
{
  process_timer_2.stop();
}
void MainWindow::executeFinished_3()
{
  process_timer_3.stop();
}
void MainWindow::executeFinished_4()
{
  process_timer_4.stop();
}
void MainWindow::executeFinished_5()
{
  process_timer_5.stop();
}


void MainWindow::executeError(QProcess::ProcessError)
{
    process_timer.stop();

}


void MainWindow::executeError_2(QProcess::ProcessError)
{
    process_timer_2.stop();

}
void MainWindow::executeError_3(QProcess::ProcessError)
{
    process_timer_3.stop();

}
void MainWindow::executeError_4(QProcess::ProcessError)
{
    process_timer_4.stop();

}
void MainWindow::executeError_5(QProcess::ProcessError)
{
    process_timer_5.stop();

}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_pushButton_6_clicked()
{

   QString text;

   text="shell";
   execute_2("adb "+text);
   set_label_6_adb_text();



   text="devices";
   execute_3("adb "+text);
   set_label_7_adb_text();


   text="localhost";
   execute_4("adb "+text);
   set_label_8_adb_text();

   text="devices";
   execute_5("ping "+text);
   set_label_9_adb_text();






}

void MainWindow::on_frame_4_windowTitleChanged(const QString &title)
{

}

void MainWindow::on_label_6_linkActivated(const QString &link)
{

}

void MainWindow::set_label_6_adb_text(void)
{
    QFile file(process_file_2);
    QString data;
    if (!file.open(QIODevice::ReadOnly)) return;

    if (file.size()>1)
    {
      file.seek(0);
      data=file.readLine();
      if(data.contains("error: device not found"))
        ui.label_6->setText("No device.");\
      else
           ui.label_6->setText(data);
      process_file_pos_2 = file.pos();
    }


    file.close();




}
void MainWindow::set_label_7_adb_text()
{
    QFile file(process_file_3);
    QString data;
    if (!file.open(QIODevice::ReadOnly)) return;

    if (file.size()>1)
    {
      file.seek(0);
      data=file.readLine();
      if(data.contains("error: device not found"))
        ui.label_7->setText("No device.");\
      else
           ui.label_7->setText(data);
      process_file_pos_3 = file.pos();
    }


    file.close();





}
void MainWindow::set_label_8_adb_text()
{
    QFile file(process_file_4);
    QString data;
    if (!file.open(QIODevice::ReadOnly)) return;

    if (file.size()>1)
    {
      file.seek(0);
      data=file.readLine();
      if(data.contains("error: device not found"))
        ui.label_8->setText("No device.");\
      else
           ui.label_8->setText(data);
      process_file_pos_4 = file.pos();
    }


    file.close();




}
void MainWindow::set_label_9_adb_text()
{
   QFile file(process_file_5);
    QString data;
    if (!file.open(QIODevice::ReadOnly)) return;

    if (file.size()>1)
    {
      file.seek(0);
      data=file.readLine();
      if(data.contains("error: device not found"))
        ui.label_9->setText("No device.");\
      else
           ui.label_9->setText(data);
      process_file_pos_5 = file.pos();
    }


    file.close();



}

void MainWindow::update_main_label_text()
{
    QFile file(process_file);
    if (!file.open(QIODevice::ReadOnly)) return;

    if (file.size()>process_file_pos)
    {
      file.seek(0);
       ui.textBrowser_5->moveCursor(QTextCursor::End);
      ui.textBrowser_5->insertPlainText(file.readAll());
      process_file_pos = file.pos();
    }
    file.close();

}
void MainWindow::on_label_7_linkActivated(const QString &link)
{

}

void MainWindow::on_label_9_linkActivated(const QString &link)
{

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}
