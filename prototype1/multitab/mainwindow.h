#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTabWidget *ttbb;
    QWidget *cur;
    int i;

private slots:
    void on_mybutton_pressed();
    void on_mybut2_pressed();
    void curTabChanged(int);
    void closetab(int);
};

#endif // MAINWINDOW_H
