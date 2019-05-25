#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QTabWidget>
#include "myeditor.h"

class MainWindow;

class TabManager: public QObject
{
    Q_OBJECT

public:
    TabManager(MainWindow *);
    QTabWidget *gettabobj();

private:
    int i;
    MainWindow *par;
    MyEditor *editor;
    QTabWidget *tabobj;

private slots:
    void curChanged(int);
    void closeRequested(int);

public slots:
    void createTab();
    void curContent();
};

#endif // TABMANAGER_H
