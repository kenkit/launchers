/********************************************************************************
** Form generated from reading UI file 'mainwindowrJ1600.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWRJ1600_H
#define MAINWINDOWRJ1600_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_exit;
    QAction *actionAbout;
    QAction *actionRegister;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView;
    QLCDNumber *lcdNumber;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(495, 476);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionRegister = new QAction(MainWindow);
        actionRegister->setObjectName(QString::fromUtf8("actionRegister"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 390, 221, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 370, 211, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 320, 111, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 370, 111, 41));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 491, 291));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/D_FORCE.jpg);"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(13, 322, 111, 41));
        lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(198, 158, 93);"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 320, 221, 41));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/Capture.JPG);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 495, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_exit);
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionRegister);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_exit->setText(QApplication::translate("MainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionRegister->setText(QApplication::translate("MainWindow", "Register", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Visit http://digital-mine.blogspot.com/", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "For More Games and Apps", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Register", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        widget->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">REGISTRATION TIMEOUT</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        menu_File->setTitle(QApplication::translate("MainWindow", "&Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWRJ1600_H
