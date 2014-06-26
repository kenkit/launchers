/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralWidget;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label;
    QFrame *frame_3;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QFrame *frame_4;
    QTextBrowser *textBrowser_5;
    QProgressBar *progressBar_5;
    QTextEdit *textEdit;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(539, 660);
        MainWindow->setMinimumSize(QSize(530, 660));
        MainWindow->setMaximumSize(QSize(539, 660));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 0, 171, 171));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/android.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(180, 0, 361, 41));
        frame_2->setStyleSheet(QString::fromUtf8("border-image: url(:/unlocker.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 50, 341, 131));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 150, 511, 271));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        textBrowser = new QTextBrowser(frame_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 30, 231, 41));
        textBrowser_2 = new QTextBrowser(frame_3);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 80, 231, 41));
        textBrowser_3 = new QTextBrowser(frame_3);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(0, 130, 231, 41));
        progressBar_2 = new QProgressBar(frame_3);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(240, 80, 181, 21));
        progressBar_2->setValue(0);
        progressBar_3 = new QProgressBar(frame_3);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(240, 130, 181, 21));
        progressBar_3->setValue(0);
        progressBar = new QProgressBar(frame_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(240, 30, 181, 21));
        progressBar->setValue(0);
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 30, 91, 31));
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 77, 91, 31));
        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(420, 120, 91, 31));
        pushButton_5 = new QPushButton(frame_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 170, 261, 41));
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 370, 511, 131));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        textBrowser_5 = new QTextBrowser(frame_4);
        textBrowser_5->setObjectName(QString::fromUtf8("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(0, 10, 511, 111));
        progressBar_5 = new QProgressBar(centralWidget);
        progressBar_5->setObjectName(QString::fromUtf8("progressBar_5"));
        progressBar_5->setGeometry(QRect(10, 510, 521, 23));
        progressBar_5->setValue(0);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 540, 351, 41));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(380, 550, 151, 41));
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        frame_2->raise();
        label->raise();
        frame_3->raise();
        progressBar_5->raise();
        textEdit->raise();
        frame_4->raise();
        pushButton_6->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 539, 26));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionAbout);
        menuMenu->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Android Unlocker by Storm", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:7pt; font-weight:600; text-decoration: underline; color:#ff0000;\">Android Unlocker Ver 1.0.0 </span></p><p><span style=\" font-size:7pt;\">Designed and maintained by Storm.</span></p><p><span style=\" font-size:7pt;\">All software designed by Storm Comply with Qt LGPL Liscence.</span></p><p><span style=\" font-size:7pt; text-decoration: underline;\">Please see</span><span style=\" font-size:7pt; font-weight:600; text-decoration: underline;\"> About</span><span style=\" font-size:7pt; text-decoration: underline;\"> in the </span><span style=\" font-size:7pt; font-weight:600; text-decoration: underline;\">Sub-Menu </span><span style=\" font-size:7pt; text-decoration: underline;\">for more information.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Wipe*Key file", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "SQL Cmd", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "ADB File Rem", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Run All (Warning Risky)", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "Run User's Command", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
