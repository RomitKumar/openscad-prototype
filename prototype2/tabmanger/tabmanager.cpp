#include <QTabWidget>
#include "myeditor.h"
#include "tabmanager.h"
#include <bits/stdc++.h>

TabManager::TabManager(MainWindow *o)
{
    i=1;
    par = o;
    tabobj = new QTabWidget();
    tabobj->setTabsClosable(true);
    tabobj->setMovable(true);
    connect(tabobj, SIGNAL(currentChanged(int)), this, SLOT(curChanged(int)));
    connect(tabobj, SIGNAL(tabCloseRequested(int)), this, SLOT(closeRequested(int)));

    editor = new MyEditor();
    tabobj->addTab(editor, "tab"+QString::number(i));
    tabobj->setCurrentWidget(editor);

}

QTabWidget *TabManager::gettabobj()
{
    return tabobj;
}

void TabManager::curChanged(int x)
{
    std::cout << "current tab changed" << std::endl;
    editor = (MyEditor *)tabobj->widget(x);
}

void TabManager::closeRequested(int x)
{
    std::cout << "Tab close requested for tab at: " << x << std::endl;
    QWidget *temp = tabobj->widget(x);
    tabobj->removeTab(x);

    // todo: popup dialog for saving of contents

    delete temp;
}

void TabManager::createTab()
{
    std::cout << "button is pressed: " << ++i << std::endl;
    editor = new MyEditor();
    tabobj->addTab(editor, "tab"+QString::number(i));
    tabobj->setCurrentWidget(editor);
}

void TabManager::curContent()
{
    std::cout << "Currently active tab is: " << (tabobj->tabText(tabobj->currentIndex())).toStdString() << std::endl;
    std::cout << "Contents:" << std::endl;
    std::cout << editor->toPlainText().toStdString() << std::endl << std::endl;

    // todo: set window title
}
