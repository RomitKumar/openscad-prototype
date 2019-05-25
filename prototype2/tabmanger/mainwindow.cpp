#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ttbb = new TabManager(this);
    ui->myverlay->addWidget(ttbb->gettabobj());

    connect(ui->mybutton, SIGNAL(pressed()), ttbb, SLOT(createTab()));
    connect(ui->mybut2, SIGNAL(pressed()), ttbb, SLOT(curContent()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

