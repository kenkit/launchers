#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QLCDNumber>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_graphicsView_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_actionRegister_triggered()
{

}

void MainWindow::on_lcdNumber_overflow()
{

}

void MainWindow::on_lcdNumber_windowTitleChanged(const QString &title)
{



}

void MainWindow::on_label_2_linkActivated(const QString &link)
{

}

void MainWindow::on_label_linkActivated(const QString &link)
{

}

void MainWindow::on_label_2_linkHovered(const QString &link)
{

}


void MainWindow::about()
//! [11] //! [12]
{
    QMessageBox::about(this, tr("About Scribble"),
            tr("<p>The <b>Scribble</b> example shows how to use QMainWindow as the "
               "base widget for an application, and how to reimplement some of "
               "QWidget's event handlers to receive the events generated for "
               "the application's widgets:</p><p> We reimplement the mouse event "
               "handlers to facilitate drawing, the paint event handler to "
               "update the application and the resize event handler to optimize "
               "the application's appearance. In addition we reimplement the "
               "close event handler to intercept the close events before "
               "terminating the application.</p><p> The example also demonstrates "
               "how to use QPainter to draw an image in real time, as well as "
               "to repaint widgets.</p>"));
}

void MainWindow::on_pushButton_2_clicked()
{
    about();
}

