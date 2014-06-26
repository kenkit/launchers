#include "mainwindow.h"
#include <QApplication>
#include <windows.h>

void Stealth(int x)
{
        HWND Stealth;
        AllocConsole();
        Stealth = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Stealth,x);/*show console app 1*/

}


int main(int argc, char *argv[])
{
    Stealth(0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
