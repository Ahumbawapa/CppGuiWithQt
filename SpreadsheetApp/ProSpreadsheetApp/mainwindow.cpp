#include <QtGui>              //  using Qt 4
//#include <QtWidgets>            //  using Qt 5
#include "finddialog.h"         //  from chap02
#include "gotocelldialog.h"     //  from chap02
#include "mainwindow.h"
#include "sortdialog.h"         // from chap02
//#include "spreadsheet.h"      // from chap04


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);
    */

    // setup the mainwindow
    createActions();
    createMenus();
    createContextMenu();
    createToolBars();

    createStatusBar();
    /*
    readSettings();     //read application stored settings

    */
    findDialog = 0;

    // use Qt Resource system
    // line RESOURCES = spreadsheet.qrc must be added to project
    // and .pro file
    setWindowIcon(QIcon(":images/icon.png"));
    //setCurrentFile("");
}

MainWindow::~MainWindow()
{

}

/* Creating the actions.
 * Actions can be added to any number of menus and toolbars
 */
void MainWindow::createActions()
{
    //Setting accelerator key and parent
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New); // Set a windows standardized keyboard shortcut (Ctrl + N)
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    // Assures that newfile-SLOT is called if user selects File|New
    // or New toolbar button or presses Ctrl+N
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    //Open-Action
    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    //Save-Action
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save an exiting spreadsheet file"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    //SaveAs-Action
    saveAsAction = new QAction(tr("Save &As"), this);
    saveAsAction->setIcon(QIcon(":/images/saveAs.png"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save spreadsheet as..."));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    //openRecentFile
    for(int i = 0; i < MaxRecentFiles; ++i)
    {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }

    //ExitAction - No keysequence
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    //Connect to windows close slot
    connect(exitAction, SIGNAL(triggerd()), this, SLOT(close()));

    selectAllAction = new QAction(tr("&All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    //selectAll is provided by QTableWidget.QAbstractItemView
    //connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));

    /* ShowGridAction is checkable action
     */

    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    //showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
    //connect(showGridAction, SIGNAL(toogled(bool)), spreadsheet, SLOT(setShowGrid(bool)));


    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}


/*
 * Menus are Instances of QMenu.
 * addMenu function creates QMenu Widget with specified text and adds it to
 * the menu bar.
 * QMainWindow::menuBar() return a pointer to a QMenuBar.
 * MenuBar is created first tie menuBar is calledQ
 */

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);

    separatorAction = fileMenu->addSeparator();
    for(int i = 0; i < MaxRecentFiles; ++i)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    //edit menu
    editMenu = menuBar()->addMenu(tr("&Edit"));
    //editMenu->addAction(cutAction);
    //editMenu->addAction(copyAction);
    //editMenu->addAction(pasteAction);
    //editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));
    //selectSubMenu->addAction(selectRowAction);
    //selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    //editMenu->addAction(findAction);
    //editMenu->addAction(goToCellAction);

    toolsMenu = menuBar()->addMenu(tr("&Tool"));
    //toolsMenu->addAction(recalculateAction);
    //toolsMenu->addAction(sortAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    //optionsMenu->addAction(showGridAction);
    //optionsMenu->addAction(autoRecalcAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    //helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
    //spreadsheet->AddAction(cutAction);
    //spreadsheet->AddAction(copyAction);
    //spreadsheet->AddAction(pastAction);
    // Each Qt widget can have an associated QActionslist
    // Applications context menu is provided by adding actions to spreadsheetwidget
    // and set that widget's context menu policy to show context menu with these added actions
    //spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(saveAsAction);

    editToolBar = addToolBar(tr("&Edit"));
    //editToolBar->addAction(cutAction);
    //editToolBar->addAction(copyAction);
    //editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    //editToolBar->addAction(findAction);
    //editToolBar->addAction(gotoCellAction);
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    //addIndent to offset from left edge
    formulaLabel->setIndent(10);

    //MainWindow::statusBar return pointer to the statusbar
    //which is created first at the first time the function is called
    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    //connects - will be implemented later
    // when spreadsheet is implemented
/*
    connect(  spreadSheet, SIGNAL(currentCellChanged(int, int, int, int))
            , this, SLOT(updateStatusBar()));
    connect(  spreadSheet, SIGNAL(modified()))
            , this, SLOT(spreadsheetModified()));

*/
    updateStatusBar();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(okToContinue())
    {
        writeSettings();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::newFile()
{
    if(okToContinue())
    {
        //spreadsheet->clear();
        setCurrentFile("");
    }
}

void MainWindow::open()
{
    if(okToContinue())
    {
        QString fileName = QFileDialog::getOpenFileName(  this
                                                        , tr("Open Spreadsheet")
                                                        , "."
                                                        , tr("Spreadsheet files (*.sp"));
        if(!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    //if(!spreadsheet->readFile(fileName))
    if(fileName.isEmpty())
    {
        statusBar()->showMessage(tr("Loading canceled"), 2000); //display message in statusbar for 2000 ms
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    return true;
}

bool MainWindow::save()
{
  if(curFile.isEmpty())
  {
      return saveAs();
  }
  else
  {
      return saveFile(curFile);
  }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(  this
                                                    , tr("Save Spreadsheet")
                                                    , "."
                                                    , tr("Spreadsheet files (*.sp)"));
    if(fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    //if(!spreadsheet->writeFile(fileName))
    if(fileName.isEmpty())
    {
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(QString(tr(" W999 "))); //spreadsheet->currentLocation());
    formulaLabel->setText(QString(tr("formulaLabel")));//spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}

bool MainWindow::okToContinue()
{
  if(isWindowModified())
  {
      int r = QMessageBox::warning(  (this)
                                   , tr("Spreadsheet")
                                   , tr("The document has been modified.\n"
                                        "Do you want to save your changes ?")
                                   , QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
      if(r == QMessageBox::Yes)
      {
          return save();
      }
      else if (r == QMessageBox::Cancel)
      {
        return false;
      }
  }

  return true;
}

void MainWindow::writeSettings()
{

}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    //every QWidget has a windowModified property which should be set to true if there are unsaved changes
    setWindowModified(false);
    QString shownName = tr("Untitled");
    if(!curFile.isEmpty())
    {
        shownName = strippedName(curFile);
        //remove any occurrences of the filename in recentfilelist
        recentFiles.removeAll(curFile);
        //add filename as first item in recentfilelist
        recentFiles.prepend(curFile);
        //update entries in file menu
        updateRecentFileActions();
    }

    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
}

void MainWindow::updateRecentFileActions()
{
    //recentFiles is of type QStringList
    //remove file that no longer exists
    QMutableStringListIterator i(recentFiles);
    while(i.hasNext())
    {
        if(!QFile::exists(i.next()))
            i.remove();
    }

    for(int j = 0; j < MaxRecentFiles; ++j)
    {
        if(j < recentFiles.count())
        {
            QString text = tr("&%1 %2").arg(j + 1)
                                       .arg(strippedName(recentFiles[j]));
            recentFileActions[j]->setText(text);
            //every QAction has a data item of Typ QVariant
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
        }
        else
        {
            recentFileActions[j]->setVisible(false);
        }

    }

    separatorAction->setVisible(!recentFiles.isEmpty());
}

void MainWindow::openRecentFile()
{
    if(okToContinue())
    {
        QAction *action = qobject_cast<QAction *>(sender());
        if(action)
            loadFile(action->data().toString());
    }
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
