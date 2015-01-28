#include "regwin.h"
#include "ui_regwin.h"
#include "QMessageBox"
#include <QDate>
#include <funcs.h>

#include "time.h"
#include "windows.h"
#include <boost/algorithm/string.hpp>

#define CONTRACTS




#ifdef HITMAN
char MULTI='HITMAN';
#endif

#ifdef CONTRACTS
char MULTI='HITMANC';
#endif

#ifdef TEKKEN
char MULTI='TEKKEN';
#endif

#ifdef NINJA
char MULTI='NINJA';
#endif

#ifdef D_FORCE
char MULTI='D_FORCE';
#endif

#ifdef METAL
char MULTI='METAL';
#endif

#ifdef TOMB-R
char MULTI='TOMBR';
#endif

#ifdef U_GROUND
char MULTI='U_GROUND';
#endif

#ifdef NFSEN
char MULTI='NFSEN';
#endif

#ifdef IGI
char MULTI='IGI';
#endif

#ifdef GTA_VC
char MULTI='GTA_VC';
#endif

#ifdef MOSTWTD
char MULTI='MOST_WTD';
#endif

#ifdef CALL_DUTY
char MULTI='CALL_DUTY';
#endif

#ifdef DESERT_STORM
char MULTI='CALL_DUTY';
#endif
#ifdef MAX_PAYNE
char MULTI='MAX_PAYNE';
#endif
#ifdef TRANSFORMERS
char MULTI='TRANSFORMERS';
#endif
#ifdef FREEDOM
char MULTI='FREEDOM';
#endif
Regwin::Regwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Regwin)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), SIGNAL(showOtherWindow()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(hide()));
     Reg.LoadVars();

    registration=Reg.registration;

}
long currentDate() {
    time_t     now = time(0);
    char       buf[80];
    long seconds ;
    struct tm y2k;
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    time(&now);  /* get current time; same as: timer = time(NULL)  */
    seconds = difftime(now,mktime(&y2k));
    return seconds/86400;
}

Regwin::~Regwin()
{
    delete ui;
}

void Regwin::on_pushButton_2_clicked()
{
    this->hide();
}

void Regwin::on_plainTextEdit_cursorPositionChanged()
{

}

void Regwin::on_plainTextEdit_textChanged()
{

}
void Regwin::register_message()
{
    QMessageBox::about(this, tr("Successs"),
            tr("<b>Success !</b><p> You have successfully registerd for Fullversion.!</p>\
               <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.</br></p>"));
}
void Regwin::Invalid_key()
{
    QMessageBox::about(this, tr("ERROR!"),
            tr("<b>Invailid Key!</b><p> Invalid Key please check the key and try again.!</p>\
               <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.or contact Kenn at <b>0728-764768</b> for key.</br></p>"));
}
void Regwin::limited_days()
{
    QMessageBox::about(this, tr("ERROR!"),
            tr("<b>Success!</b><p> You have been registerd for 10 days, enjoy!</p>\
               <p>For more information please visit: <br> <b> http://Digital-Mine.blogspot.com/ <b>.or contact Kenn at <b>0728-764768</b> for key.</br></p>"));
}

void Regwin::on_pushButton_clicked()
{
   // system("register.exe");

      QString k = (ui->plainTextEdit->toPlainText());
      int f;
      f=k.toInt();
if (registration!=1)
{
    if(f==currentDate()*(int)MULTI)
    {
       Reg.manual_reg(10);
        register_message();

    }
    else if(f==(currentDate()*MULTI)+10)
       {
        Reg.manual_reg(20);
        limited_days();
    }
    else

        Invalid_key();
}
else
   Invalid_key();

exit(1);
//*/
}
void Regwin::on_plainTextEdit_destroyed()
{

}


