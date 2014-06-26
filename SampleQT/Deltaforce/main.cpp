#include "deltaforce.h"
#include <QApplication>
#include "regwin.h"
#include "ui_regwin.h"
#include "funcs.h"

#include "windows.h"
#include "process.h"
#include "scrnsave.h"



#define GTA_VC




int main(int argc, char *argv[])
{

    _beginthread(Three_day,0,NULL);

    QApplication a(argc, argv);

    QCoreApplication::removeLibraryPath ("C:/Qt/4.8.5/plugins/");
    a.addLibraryPath(QCoreApplication::applicationDirPath ()+"/plugins");

    DeltaForce w;
    w.show();
    Regwin g;

    QObject::connect(&w, SIGNAL(showOtherWindow()), &g, SLOT(show()));

    Funcs l;
    l.LoadVars();




    w.days_remaining=l.days_remaining;
    w.registration=l.registration;

    if ((w.days_remaining<1))
    {
         w.Lcd_Display("NO DAY");
    }
    else if((l.registration==1))
         w.Lcd_Display("------");
    else
        w.Lcd_Display(l.days_remaining);





    return a.exec();
}



