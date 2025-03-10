﻿#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug("---> @MainWindow: Start");
    this->setFixedSize(1366,768);// fix windows size
    tabWidget = new QTabWidget(this);
    filetab = new fileTab();
    qDebug("---> @MainWindow: post new filetab");
    synthtab = new synth1Tab(filetab);
    qDebug("---> @MainWindow: post new synthtab");

    tabWidget->addTab(filetab, tr("File Actions"));
    tabWidget->addTab(synthtab, tr("Synth1"));
    tabWidget->setFixedSize(1350,768);
    tabWidget->setGeometry(0,0,0,0);
    QObject::connect(filetab , SIGNAL(quit_touched()) ,this ,SLOT(close()));
    QObject::connect(synthtab,SIGNAL(keyboard_view()),filetab,SLOT(on_keyboardopenbutton_pressed()));
    QObject::connect(synthtab,SIGNAL(keyboard_hide()),filetab,SLOT(on_keyboardclosebutton_pressed()));
    QObject::connect(filetab,SIGNAL(key_return_touched()),synthtab,SLOT(save_preset_to_file2()));

 //   QVBoxLayout *mainLayout = new QVBoxLayout;
 //   mainLayout->addWidget(tabWidget);
 //   mainLayout->addStretch(1);
 //   setLayout(mainLayout);


    tabWidget->setCurrentIndex(1);
    qDebug("---> @MainWindow: end");
 //   tabWidget->show();
}

MainWindow::~MainWindow()
{
    filetab->saveSettings("test");
//    delete ui;
}

void MainWindow::quit(void)
{
    filetab->saveSettings("test");
    close();
}
