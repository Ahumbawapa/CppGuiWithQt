#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


//forward declarations
class QAction;
class QLabel;
class FindDialog;   //from Chap2
class Spreadsheet;  //will be implemented in Chap04

class MainWindow : public QMainWindow
{
    Q_OBJECT // providing own signal and slots

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event); //virtual function in QWidget
};

#endif // MAINWINDOW_H
