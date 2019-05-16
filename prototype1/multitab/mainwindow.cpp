#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QWidget>
#include <QTextEdit>
#include <bits/stdc++.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i=1;

    ttbb = new QTabWidget();
    ttbb->setTabsClosable(true);
    ttbb->setMovable(true);
    ui->mywid->layout()->addWidget(ttbb);

    connect(ttbb, SIGNAL(currentChanged(int)), this, SLOT(curTabChanged(int)));
    connect(ttbb, SIGNAL(tabCloseRequested(int)), this, SLOT(closetab(int)));

    // cur is analogous to editor variable in the code
    // QTextEdit is analogous to ScintillaEditor
    cur = new QTextEdit();

    // initially setting first tab
    ttbb->addTab(cur,"tab"+QString::number(i));
    ttbb->setCurrentWidget(cur);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mybutton_pressed()
{
    std::cout << "button is pressed: " << ++i << std::endl;
    cur = new QTextEdit();
    ttbb->addTab(cur, "tab"+QString::number(i));
    ttbb->setCurrentWidget(cur);
}

void MainWindow::on_mybut2_pressed()
{
    std::cout << "Currently active tab is: " << (ttbb->tabText(ttbb->currentIndex())).toStdString() << std::endl;
    std::cout << "Contents:" << std::endl;
    std::cout << ((QTextEdit *)cur)->toPlainText().toStdString() << std::endl << std::endl;
}

void MainWindow::curTabChanged(int i)
{
    cur = ttbb->widget(i);
}

void MainWindow::closetab(int i)
{
    std::cout << "Tab close requested for tab at: " << i << std::endl;
    QWidget *temp = ttbb->widget(i);
    ttbb->removeTab(i);

    // todo: popup dialog for saving of contents

    delete temp;
}
