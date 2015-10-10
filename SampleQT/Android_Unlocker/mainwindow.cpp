#include "mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <windows.h>
#include <QtCore/qcoreevent.h>
//REMAINING WAIT FOR PROCESS TO COMPLETE TO RESUME EXECUTION



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{



    std::vector <program> m_programs;

    ui.setupUi(this);


    //////////////////
   QProcess * m_process = new QProcess(this);
    connect(m_process,SIGNAL(finished(int)),this,SLOT(programFinished(int)));
    connect(m_process,SIGNAL(readyReadStandardOutput()),this,SLOT(readyRead()));

    totalPrograms = 0;
    totalProcessed = 0;





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
       connect(ui.comboBox_2, SIGNAL(activated(int)), this, SLOT(combochanged(int)));
       connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(combo_2_changed(int)));


/////////////////////
       max_commands=0; brute_force=100; timeout=4000;s_timeout=300;to_exit=0;

       QTimer *timer = new QTimer(this);
           connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
           timer->start(1000); //time specified in ms

      /*
       QString k;
       char buffer[10];
       for(int i=1;i<10;i++)
       {

          string adds=itoa (i,buffer,10);

           ui.comboBox->addItem(k.fromStdString(adds)+".Items");

       }
    */

adb_tools="adb_tools.xml";
menu_file="items.xml";

killed=false;

display_initial_entry(menu_file);
select_from_initial_entry( menu_file,1);
//refresh();

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
    text="shell \"su -c id\"";
    execute_4("adb "+text);
    set_label_8_adb_text();
    //ROOT STATUS

}

void MainWindow::command_executor(string file_name,int commands_no_run)
{
    char buffer_2 [33];

    string command=itoa(commands_no_run+1,buffer_2,10);

    cout << "Parsing commands..." << endl;

    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile (file_name.c_str());
    cout<<file_name.c_str()<<endl;
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    theFile.close();
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("Instructubles");
    // Iterate over the brewerys
    string commansd="Commands_";
    string iter;
    string ha=" ";
    int iters;
    commansd+=command;
    string commands;

    xml_node<> * command_node = root_node->first_node(commansd.c_str());
    iter=command_node->first_attribute("iterations")->value();

    iters=atoi(iter.c_str());

        cout<<"Running :"<<command_node->first_attribute("name")->value()<<endl<<command_node->first_attribute("iterations")->value()<<":no of times. \n";

            // Interate over the beers

    ui.progressBar_5->setRange(0,iters);





      int i=1;

        for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
        {


            i++;
            ui.progressBar_5->setValue(i);



            program current;

            current.name=Actual_command->first_attribute("tool")->value();
            current.params=Actual_command->first_attribute("shell_command")->value();


           m_programs.push_back(current);






        }
        ui.progressBar_5->setValue(i);


}
void MainWindow::print_commands(string xml_filename)
{
cout << "Parsing commands..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile (xml_filename.c_str());
   cout<<"Read the xml file into a vector"<<endl;

    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
     cout<<"Parse the buffer using the xml file parsing library into doc"<<endl;
    doc.parse<0>(&buffer[0]);
    cout<< "Find our root node"<<endl;
    root_node = doc.first_node("Instructubles");

    string iter=root_node->first_attribute("no_of_commands")->value();
    cout<<"Max commands"<<iter<<endl;
    //cout<<"No of commands available :"<<iter<<endl;

    //cout<<"Here are the available commands.\n\n";
    // Iterate over the brewerys
    int iters=atoi(iter.c_str());
    max_commands=iters;
    cout<<"Max commands"<<max_commands<<endl;
    for (int i=1; i!=iters+1;i++)
    {

        char buffer [33];
        string adds=itoa (i,buffer,10);
        string commands="Commands_";
        commands+=adds;
        xml_node<> * command_node = root_node->first_node(commands.c_str());
       QString k,l;


       QString no=(command_node->first_attribute("no")->value());
       QString command=command_node->first_attribute("name")->value();

      // cout<<command_node->first_attribute("no")->value()<<command_node->first_attribute("name")->value()<<endl;
       ui.comboBox->InsertAfterCurrent;


        if (1)
          ui.comboBox->addItem(no+"."+command);
        else
            ui.comboBox->addItem("No commands.");






            //command_node->first_attribute("iterations")->value());
            // Interate over the beers
        /***
        for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
        {
            printf("Using  %s to run %s. \n\n",
                Actual_command->first_attribute("tool")->value(),
                Actual_command->first_attribute("shell_command")->value());
            printf("Logging: %s\n", Actual_command->value());
        }
        **/
        //cout << endl;
    }
    //cout<<max_commands+1<<".Back.\n";
    //to_exit=max_commands+1;

}
void MainWindow::on_textBrowser_textChanged()
{

}

void MainWindow::on_textBrowser_5_textChanged()
{

}



void MainWindow::on_pushButton_2_clicked()
{
ui.textBrowser_5->insertPlainText("\nStarting adb server.");
execute("adb start-server");
ui.textBrowser_5->moveCursor(QTextCursor::End);
killed=false;


}

void MainWindow::on_pushButton_3_clicked()
{

 execute("adb root");
 ui.textBrowser_5->insertPlainText("\nStarting adb as root.\n");
 ui.textBrowser_5->moveCursor(QTextCursor::End);



}

void MainWindow::on_textBrowser_2_textChanged()
{

}

void MainWindow::on_textBrowser_3_textChanged()
{

}

void MainWindow::on_pushButton_5_clicked()
{

    get_menu_initial_entry(menu_file,ui.comboBox_2->currentIndex()+1);



    command_executor(sellected_menu_entry,ui.comboBox->currentIndex());



   // ui.progressBar_5->setMaximum(totalPrograms);




    if (m_programs.size() > 0)
    {
        processCommand(0); //Process the first program
    }
    else
    {
        ;
    }




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
  ui.textBrowser_5->moveCursor(QTextCursor::End);


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
killed=false;
refresh();


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
        {
          ui.label_6->setText("No device.");\

      }
      else if(data.contains("not running"))
           ui.label_6->setText("Please Start adb server.");
       else
      {
          ui.label_6->setText(data);

          ui.textBrowser_5->insertPlainText("Found: "+data+'\n');
          ui.textBrowser_5->moveCursor(QTextCursor::End);
          killed=true;
      }

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
      else if(data.contains("not running"))
           ui.label_7->setText("Please Start adb server.");
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
      if(data.contains("device not found"))
        ui.label_8->setText("No device.");\
      else if(data.contains("not running"))
           ui.label_8->setText("Please Start adb server.");
      else if (data.contains("(root)"))
           ui.label_8->setText("Yes");
      else if (data.contains("su: permission denied"))
           ui.label_8->setText("No");
      else if (data.contains("offline"))
           ui.label_8->setText(data);
       else if (data.contains("sh: su: not found"))
          ui.label_8->setText("No");


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
      else if(data.contains("not running"))
           ui.label_9->setText("Please Start adb server.");
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
      ui.textBrowser_5->insertPlainText(file.readAll()+'\n');
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

void MainWindow::on_pushButton_4_clicked()
{
    ui.textBrowser_5->insertPlainText("\nKilling adb Server.");
    execute("adb kill-server");
    ui.textBrowser_5->moveCursor(QTextCursor::End);
    ui.textBrowser_5->insertPlainText("\nSuccessfully killed adb server.");
    ui.textBrowser_5->moveCursor(QTextCursor::End);

    killed=true;
}
void MainWindow::refresh(void)
{
    if(!killed)
  {
    //ui.textBrowser_5->insertPlainText("Checking for devices. \n");
    QString text;

    text="shell getprop ro.product.model";
    execute_2("adb "+text);
    set_label_6_adb_text();
    //RETREIVE DEVICE NAME


    text="shell getprop ro.build.version.release ";
    execute_3("adb "+text);
    set_label_7_adb_text();
    //RETRIEVE ANDROID VERSION


    text="shell \"su -c id\"";
    execute_4("adb "+text);
    set_label_8_adb_text();
    //ROOT STATUS

    text="shell getprop ro.build.version.sdk ";
    execute_5("adb "+text);
    set_label_9_adb_text();
    //BATTERY STATUS
}


}

void MainWindow::on_pushButton_7_clicked()
{
    process.close();
}

void MainWindow::display_initial_entry(string menu_file)
{
cout << "Parsing commands..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile (menu_file.c_str());
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("Instructubles");

    string iter=root_node->first_attribute("no_of_items")->value();

    cout<<"No of commands available :"<<iter<<endl;

    printf("Here are the available commands.\n\n");
    // Iterate over the brewerys
    int iters=atoi(iter.c_str());
    max_commands=iters;
    for (int i=1; i!=iters+1;i++)
    {

        char buffer [33];
        string adds=itoa (i,buffer,10);
        string commands="acvite_item_";
        commands+=adds;
        xml_node<> * command_node = root_node->first_node(commands.c_str());



        QString no=command_node->first_attribute("no")->value();
        QString command=command_node->first_attribute("item_name")->value();

       // cout<<command_node->first_attribute("no")->value()<<command_node->first_attribute("name")->value()<<endl;
        ui.comboBox->InsertAfterCurrent;


         if (1)
           ui.comboBox_2->addItem(no+"."+command);
         else
             ui.comboBox_2->addItem("No commands.");
            //command_node->first_attribute("iterations")->value());
            // Interate over the beers
        /***
        for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
        {
            printf("Using  %s to run %s. \n\n",
                Actual_command->first_attribute("tool")->value(),
                Actual_command->first_attribute("shell_command")->value());
            printf("Logging: %s\n", Actual_command->value());
        }
        **/
        //cout << endl;
    }

//	cout<<iters+1<<". Exit"<<endl;
}


void MainWindow::select_from_initial_entry(string menu_file,int item_no)
{
    char buffer_2 [33];
    string menu_item_no=itoa (item_no,buffer_2,10);





    cout << "Parsing commands..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile (menu_file.c_str());
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("Instructubles");
    // Iterate over the brewerys
    string commansd="acvite_item_";
    string iter;
    int iters;
    commansd+=menu_item_no;
    string commands,choice;

    xml_node<> * command_node = root_node->first_node(commansd.c_str());
    //iter=command_node->first_attribute("no_of_items")->value();
    //iters=atoi(iter.c_str());

        print_commands(command_node->first_attribute("file")->value());



        //cout << endl;




}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    //select_from_initial_entry( menu_file,ui.comboBox_2->currentIndex());
}

void MainWindow::combochanged(int index)
{
    ui.comboBox->clear();
    select_from_initial_entry( menu_file,index+1);
     ui.progressBar_5->setValue(0);
}

void MainWindow::combo_2_changed(int index)
{


     ui.progressBar_5->setValue(0);
}


void MainWindow::get_menu_initial_entry(string menu_file,int item_no)
{
    char buffer_2 [33];
    string menu_item_no=itoa (item_no,buffer_2,10);







    cout << "Parsing commands..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile (menu_file.c_str());
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("Instructubles");
    // Iterate over the brewerys
    string commansd="acvite_item_";
    string iter;
    int iters;
    commansd+=menu_item_no;
    string commands,choice;

    xml_node<> * command_node = root_node->first_node(commansd.c_str());
    //iter=command_node->first_attribute("no_of_items")->value();
    //iters=atoi(iter.c_str());

       sellected_menu_entry=command_node->first_attribute("file")->value();



        //cout << endl;




}

void MainWindow::processCommand(int pos)
{
    currProgram = pos;

    QString program;


    if(!m_programs.empty())
    {
        program.fromStdString(m_programs[pos].name+" "+m_programs[pos].params);


        execute(program);

        m_programs.pop_back();



            if (currProgram +1 <= m_programs.size()-1)
            {
                processCommand(currProgram +1);
            }
            else
            {
                commandsFinished();
            }



        if (currProgram +1 <= m_programs.size()-1)
        {
            processCommand(currProgram +1);
        }
    }
        else
        {
            commandsFinished();
        }

}
void MainWindow::readyRead()
{

;

}

void MainWindow::commandsFinished()
{
    ;
}

void MainWindow::programFinished(int exitCode)
{
    totalProcessed++;
    ui.progressBar_5->setValue(totalProcessed);




    if (!m_programs.empty()) //If I have more programs
    {
        processCommand(currProgram +1);
    }
    else
    {
        commandsFinished();
    }
}
