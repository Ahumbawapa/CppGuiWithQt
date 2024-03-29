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
    static QStringList  recentFiles;
protected:
    //virtual function in QWidget, automatically called when window is closed by user
    //reimplement here for showing close dialog
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void updateStatusBar();
    void spreadsheetModified();

    void find();
    void goToCell();

    /* to keep project compileable
    void sort();

    */
    void about();
    void openRecentFile();


private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);

    Spreadsheet *spreadsheet;
    FindDialog  *findDialog;
    QLabel      *locationLabel;
    QLabel      *formulaLabel;
    QString      curFile;

    enum {MaxRecentFiles = 5};

    QMenu       *fileMenu;
    QMenu       *editMenu;
    QMenu       *toolsMenu;
    QMenu       *selectSubMenu;
    QMenu       *optionsMenu;
    QMenu       *helpMenu;

    QToolBar    *fileToolBar;
    QToolBar    *editToolBar;

    //Actions
    QAction     *newAction;
    QAction     *openAction;
    QAction     *saveAction;
    QAction     *saveAsAction;
    QAction     *selectAllAction;
    QAction     *closeAction;
    QAction     *exitAction;
    QAction     *recentFileActions[MaxRecentFiles];
    QAction     *separatorAction;
    QAction     *aboutQtAction;
    QAction     *aboutAction;
    QAction     *showGridAction;
    QAction     *recalculateAction;
    QAction     *sortAction;
    QAction     *autoRecalcAction;
    QAction     *findAction;
    QAction     *gotoCellAction;

};

#endif // MAINWINDOW_H
