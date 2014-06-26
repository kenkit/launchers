#include "mainwindow.h"


#include <iostream>
#include <string>
#include <boost/algorithm/string/case_conv.hpp>
#include <fstream>
#include <QMessageBox>
#include <windows.h>
#include <process.h>

#define RELIGIOUS  1
#define TECHNOLOGY 2


using namespace std;
using namespace boost;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);

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
ui.progressBar->setValue(0);
}

void MainWindow::on_progressBar_valueChanged(int value)
{

}
int MainWindow:: Subject_determiner(string str)
{

to_lower(str);
float val=0;

for (int i=0;i<rl;i++)
{

    if(sizeof(religion[i])>=1)
         {
            to_lower(religion[i]);
             avg_relig+=Number_Of_Matches(religion[i],str);
         }

ui.progressBar->setValue(20);
}
for (int i=0;i<tch;i++)
{

        if (sizeof(technology[i])>=1)
          {
                  to_lower(technology[i]);
                  avg_tech+=Number_Of_Matches(technology[i],str);
          }
ui.progressBar->setValue(40);
}
for (int i=0;i<pol;i++)
{

        if (sizeof(politics[i])>=1)
          {
                  to_lower(politics[i]);
                  avg_pol+=Number_Of_Matches(politics[i],str);
          }
 ui.progressBar->setValue(60);
}
for (int i=0;i<sci;i++)
{

        if (sizeof(science[i])>=1)
          {
                  to_lower(science[i]);
                  avg_scie+=Number_Of_Matches(science[i],str);
          }
ui.progressBar->setValue(80);
}
for (int i=0;i<bus;i++)
{

        if (sizeof(business[i])>=1)
          {
                  to_lower(business[i]);
                  avg_bus+=Number_Of_Matches(business[i],str);
          }
        ui.progressBar->setValue(100);
}
if  ((avg_relig>avg_tech)&&(avg_relig>avg_pol)&&(avg_relig>avg_scie)&&(avg_relig>avg_bus))
    {


        QString DAS;
        char rel[10]; itoa(avg_relig,rel,10);
        QString a1="Subject of the text is religious, with :",a2=" Word Occurrencies in the text \n";
        DAS=a1+rel+a2;
        ui.textBrowser_2->setPlainText(DAS);
        return RELIGIOUS;
    }
else if((avg_tech>avg_relig)&&(avg_tech>avg_pol)&&(avg_tech>avg_scie)&&(avg_tech>avg_bus))
    {
    QString DAS;
    char tech[10]; itoa(avg_tech,tech,10);
    QString a1="Subject of the text is Technology, with :",a2=" Word Occurrencies in the text \n";
    DAS=a1+tech+a2;
    ui.textBrowser_2->setPlainText(DAS);
        return TECHNOLOGY;
    }
else if((avg_pol>avg_relig)&&(avg_pol>avg_tech)&&(avg_pol>avg_scie)&&(avg_pol>avg_bus))
    {
    QString DAS;
    char pol[10]; itoa(avg_pol,pol,10);
    QString a1="Subject of the text is Politics, with :",a2=" Word Occurrencies in the text \n";
    DAS=a1+pol+a2;
   ui.textBrowser_2->setPlainText(DAS);
        return TECHNOLOGY;
    }
else if((avg_scie>avg_relig)&&(avg_scie>avg_tech)&&(avg_scie>avg_pol)&&(avg_scie>avg_bus))
    {
    QString DAS;
    char scie[10]; itoa(avg_scie,scie,10);
    QString a1="Subject of the text is Science, with :",a2=" Word Occurrencies in the text \n";
    DAS=a1+scie+a2;
    ui.textBrowser_2->setPlainText(DAS);
        return TECHNOLOGY;
    }
else if((avg_bus>avg_relig)&&(avg_bus>avg_tech)&&(avg_bus>avg_pol)&&(avg_bus>avg_scie))
    {
    QString DAS;
    char bus[10]; itoa(avg_bus,bus,10);
    QString a1="Subject of the text is Business, with :",a2=" Word Occurrencies in the text \n";
    DAS=a1+bus+a2;
    ui.textBrowser_2->setPlainText(DAS);
        return TECHNOLOGY;
    }
else
     {
        QMessageBox::about(this, tr("! Error"),
                      tr("Subject Type Undeteremined.! <br>Please make sure the dictionary is valid.</br>"));

         return 0;
     }
}
int MainWindow:: Read_Dictionaries(char* filename,string DICTIONARY [])
{

    int i=0;
    QString word;
    string DICT;
    ifstream mydoc(filename);
    QString read="Reading :";
    QString das=read+filename;
    QString sfs;
    ui.textBrowser->setPlainText(das);

        if (mydoc.is_open())
        {
            while ( mydoc.good() )
            {
                getline (mydoc,DICTIONARY[i]);
            i++;
        }

        mydoc.close();

    }

    for (int j=0;j<1024;j++)
        if (DICTIONARY[j].length()>1)
      DICT=DICTIONARY[j];
   sfs.fromStdString(DICT);
     word="Reading Word : "+sfs;
     ui.textBrowser->setPlainText(word);

return i;
}

int MainWindow::Number_Of_Matches(string to_be_found,string find_in_me)
{
int letters=0;
int spaces=0;
int start_ps=0;
int f=0;
letters=find_in_me.length();

for (int i=0;i<letters;i++)
{

    f=find_in_me.find(to_be_found,start_ps);

   if (f>=0)
    {
        spaces++;
    }
    if (f>=0)
    {
        start_ps=f;
        start_ps++;
    }

}
if (spaces>=0)
    return spaces;
else
    return 0;
}


void MainWindow::evaluator()
{

string data;
ifstream mydoc("read.txt");

avg_relig=0;
avg_tech=0;
avg_bus=0;
avg_scie=0;
avg_pol=0;

rl=Read_Dictionaries("REL.txt",religion);
tch=Read_Dictionaries("TECH.txt",technology);
bus=Read_Dictionaries("business.txt",business);
pol=Read_Dictionaries("politics.txt",politics);
sci=Read_Dictionaries("science.txt",science);



QString k = (ui.textEdit->toPlainText());

string datas= k.toStdString();
Subject_determiner(datas);

QString a1="The total average text output is :\n",
        a2=": for religious stuff and\n",
        a3=": for tech stuff \n",
        a4=": for business stuff \n",
        a5=": for science stuff \n",
        a6=": for politics stuff \n";

char rel[10]; itoa(avg_relig,rel,10);char tech[10]; itoa(avg_tech,tech,10);
char bus[10];itoa(avg_bus,bus,10);char scie[10]; itoa(avg_scie,scie,10);
char pol[10]; itoa(avg_pol,pol,10);


QString DAS=(a1+rel+a2+tech+a3+bus+a4+scie+a5+pol+a6);

ui.textBrowser->setPlainText(DAS);

}

void MainWindow::on_pushButton_clicked()
{

evaluator();

}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_textBrowser_textChanged()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    ui.textEdit->clear();
    ui.progressBar->setValue(0);
}

void MainWindow::on_textBrowser_2_textChanged()
{

}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Roswell Software Ver 1.0"),
                  tr("This software was designed for those Literature Gurus\
                     <br>who would want to determine the nature of large text <br>\
                     without having to read through the whole document.</br> \
                     <br>Enjoy !"));
}

void MainWindow::on_pushButton_3_clicked()
{
    exit(1);
}

void MainWindow::on_actionExit_triggered()
{
    exit(1);
}
