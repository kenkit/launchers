#include "mainwindow.h"
#include <QApplication>
#include <windows.h>
#include <QVector>
#include <fstream>
void Stealth(int x)
{
        HWND Stealth;
        AllocConsole();
        Stealth = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Stealth,x);/*show console app 1*/

}


int main(int argc, char *argv[])
{








        //QCoreApplication::removeLibraryPath ("C:/Qt/4.8.5/plugins/");
        // QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath ()+"/plugins");

    //Stealth(0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //w.execute("adb root");
    //w.execute("adb devices");
    //w.scan_devices();

    return a.exec();
}
