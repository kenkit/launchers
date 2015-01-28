#include "deltaforce.h"
#include "ui_deltaforce.h"
#include "QMessageBox"
#include "fstream"
#include "funcs.h"
#define CONTRACTS


DeltaForce::DeltaForce(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeltaForce)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), SIGNAL(showOtherWindow()));

}


DeltaForce::~DeltaForce()
{
    delete ui;
}

void DeltaForce::on_DeltaForce_windowIconTextChanged(const QString &iconText)
{

}

void DeltaForce::on_DeltaForce_customContextMenuRequested(const QPoint &pos)
{

}


void DeltaForce::on_DeltaForce_iconSizeChanged(const QSize &iconSize)
{

}
void DeltaForce::about()
{
 #ifdef D_FORCE
    QMessageBox::about(this, tr("About DeltaForce"),
            tr("<b><u>Deltaforce</u></b><p> This software was designed an is currently maintained by storm.</p>\
               <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif

 #ifdef TEKKEN
    QMessageBox::about(this, tr("About Tekken"),
                      tr("<b><u>Tekken</u></b><p> This software was designed an is currently maintained by storm.</p>\
                         <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif

 #ifdef U_GROUND
     QMessageBox::about(this, tr("About Underground"),
                       tr("<b><u>Underground</u></b><p> This software was designed an is currently maintained by storm.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif
#ifdef NINJA
     QMessageBox::about(this, tr("About Ninja"),
                      tr("<b><u>Ninja</u></b><p> This software was designed an is currently maintained by storm.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif

#ifdef METAL
    QMessageBox::about(this, tr("About Metal Gear"),
                       tr("<b><u>Metal Gear</u></b><p> This software was designed an is currently maintained by storm.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
 #ifdef TOMB-R
     QMessageBox::about(this, tr("About Tomb-Raider"),
                       tr("<b><u>Tomb-Raider</u></b><p> This software was designed an is currently maintained by storm.</p>\
                              <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif
#ifdef HITMAN
      QMessageBox::about(this, tr("About Hitman-Silent Assasin"),
                       tr("<b><u>Hitman-Silent Assasin</u></b><p> This software was designed an is currently maintained by storm.</p>\
                              <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef CONTRACTS
      QMessageBox::about(this, tr("About Hitman Contracts"),
                        tr("<b><u>Hitman Contracts</u></b><p> This software was designed an is currently maintained by storm.</p>\
                                <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef NFSEN
       QMessageBox::about(this, tr("About Need For speed II"),
                    tr("<b><u>Need For speed II</u></b><p> This software was designed an is currently maintained by storm.</p>\
                      <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
 #ifdef IGI
       QMessageBox::about(this, tr("About Project IGI"),
                       tr("<b><u>Project IGI</u></b><p> This software was designed an is currently maintained by storm.</p>\
                       <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef GTA_VC
       QMessageBox::about(this, tr("About GTA Vice City 17"),
                        tr("<b><u>GTA VC</u></b><p> This software was designed an is currently maintained by storm.</p>\
                         <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif

#ifdef MOSTWTD
        QMessageBox::about(this, tr("About NeedforspeedMostWanted"),
                         tr("<b><u>NeedforspeedMostWanted</u></b><p> This software was designed an is currently maintained by storm.</p>\
                         <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef CALL_DUTY
           QMessageBox::about(this, tr("About Call Of Duty MW"),
                          tr("<b><u>Call Of Duty Moden Warfare</u></b><p> This software was designed an is currently maintained by storm.</p>\
                           <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif
 #ifdef DESERT_STORM
           QMessageBox::about(this, tr("About Desert Storm"),
                           tr("<b><u>Desert Storm</u></b><p> This software was designed an is currently maintained by storm.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif
#ifdef TRANSFORMERS
          QMessageBox::about(this, tr("About Transformer"),
                              tr("<b><u>Transformer</u></b><p> This software was designed an is currently maintained by storm.</p>\
                             <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif
  #ifdef FREEDOM
          QMessageBox::about(this, tr("About Freedom Fighters"),
                              tr("<b><u>Freedom Fighters</u></b><p> This software was designed an is currently maintained by storm.</p>\
                              <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
  #endif
}

void DeltaForce::on_pushButton_3_clicked()
{
    about();
}

void DeltaForce::on_action_About_triggered()
{
   about();
}

void DeltaForce::on_action_Exit_triggered()
{
    exit(1);
}

void DeltaForce::on_lcdNumber_overflow()
{

}


void DeltaForce::on_pushButton_2_clicked()
{

}


void DeltaForce::on_action_Register_triggered()
{
    showOtherWindow();
}

void DeltaForce::on_pushButton_4_clicked()
{
     exit(1);
}
void DeltaForce::Lcd_Display(int ts)
{
    ui->lcdNumber->display(ts);
}
void DeltaForce::Lcd_Display(char* ts)
{
    ui->lcdNumber->display(ts);
}


void DeltaForce::UpdateLcd()
{

}


void DeltaForce::on_pushButton_clicked()
{
    if ((registration!=1)&&(days_remaining<1))
           register_message();
    else
        {

            launch_app();

        }
}

void DeltaForce::register_message()
{
    #ifdef D_FORCE
    QMessageBox::about(this, tr("About DeltaForce"),
            tr("<b><u>Deltaforce</u></b><p> To continue using this software please register by clicking on register button.</p>\
               <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
   #endif

   #ifdef TEKKEN
   QMessageBox::about(this, tr("About Tekken"),
                       tr("<b><u>Tekken</u></b><p> To continue using this software please register by clicking on register button.</p>\
                          <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
  #endif
  #ifdef U_GROUND
      QMessageBox::about(this, tr("About Underground"),
                          tr("<b><u>Underground</u></b><p> To continue using this software please register by clicking on register button.</p>\
                             <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
  #endif
 #ifdef NINJA
      QMessageBox::about(this, tr("About Ninja"),
                           tr("<b><u>Ninjka</u></b><p> To continue using this software please register by clicking on register button.</p>\
                           <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif
 #ifdef METAL
      QMessageBox::about(this, tr("About Metal Gear"),
                           tr("<b><u>Metal</u></b><p> To continue using this software please register by clicking on register button.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef TOMB-R
      QMessageBox::about(this, tr("About Tomb Raider"),
                           tr("<b><u>Tomb Raider</u></b><p> To continue using this software please register by clicking on register button.</p>\
                           <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef HITMAN
      QMessageBox::about(this, tr("About Hitman-Silent Assasin"),
                          tr("<b><u>Hitman-Silent Assasin</u></b><p> To continue using this software please register by clicking on register button.</p>\
                           <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
 #ifdef CONTRACTS
        QMessageBox::about(this, tr("About Hitman Contracts"),
                            tr("<b><u>Hitman Contracts</u></b><p> To continue using this software please register by clicking on register button.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef NFSEN
       QMessageBox::about(this, tr("About Need For Speed ii"),
                           tr("<b><u>Need For Speed ii</u></b><p> To continue using this software please register by clicking on register button.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef IGI
       QMessageBox::about(this, tr("About Project IGI"),
                             tr("<b><u>Project IGI</u></b><p> To continue using this software please register by clicking on register button.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef GTA_VC
       QMessageBox::about(this, tr("About GTA Vice City 17"),
                            tr("<b><u>GTA Vice City</u></b><p> To continue using this software please register by clicking on register button.</p>\
                            <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif

#ifdef MOSTWTD
       QMessageBox::about(this, tr("About NeedForSpeedMostwanted"),
                             tr("<b><u>NeedForSpeedMostwanted</u></b><p> To continue using this software please register by clicking on register button.</p>\
                             <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));

#endif
#ifdef CALL_DUTY

                                QMessageBox::about(this, tr("About Call Of Duty MW"),
                                                         tr("<b><u>Call Of Duty Modern Warfare</u></b><p> To continue using this software please register by clicking on register button.</p>\
                                <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef DESERT_STORM
         QMessageBox::about(this, tr("About Desert Storm"),
            tr("<b><u>Desert Storm</u></b><p> To continue using this software please register by clicking on register button.</p>\
           <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif

 #ifdef MAX_PAYNE
                    QMessageBox::about(this, tr("About Max Payne"),
                       tr("<b><u>Max Payne</u></b><p> To continue using this software please register by clicking on register button.</p>\
                      <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
 #endif
#ifdef TRANSFORMERS
                    QMessageBox::about(this, tr("About Transformers"),
                       tr("<b><u>Transformers</u></b><p> To continue using this software please register by clicking on register button.</p>\
                      <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
#ifdef FREEDOM
                     QMessageBox::about(this, tr("About Freedom Fighters"),
                         tr("<b><u>Freedom Fighters</u></b><p> To continue using this software please register by clicking on register button.</p>\
                    <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
#endif
}
