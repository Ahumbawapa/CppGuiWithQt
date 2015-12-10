#include <QtGui>
#include "finddialog.h"         // from chap02
#include "gotocelldialog.h"     // from chap02
#include "mainwindow.h"
#include "sortdialog.h"         // from chap02
#include "spreadsheet.h"        // from chap04


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    // setup the mainwindow
    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();     //read application stored settings

    findDialog = 0;

    setWindowIcon(QIcon(":images/icon.png"));
    setCurrentFile("");
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{

}
