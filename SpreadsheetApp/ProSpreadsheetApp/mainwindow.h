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
    //virtual function in QWidget, automatically called when window is closed by user
    //reimplement here for showing close dialog
    void closeEvent(QCloseEvent *event);

private slots:
    void NewFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void about();

    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();

private:
    void createActions();
//    void createMenus();
//    void createContextMenu();
//    void createToolBars();
//    void createStatusBar();
//    void readSettings();
//    void writeSettings();
//    bool okToContinue();
//    bool loadFile(const QString &fileName);
//    bool saveFile(const QString &fileName);
//    void setCurrentFile(const QString &fileName);
//    void updateRecentFileActions();
//    QString strippedName(const QString &fullFileName);

    Spreadsheet *spreadsheet;
    FindDialog  *findDialog;
    QLabel      *locationLabel;
    QLabel      *formulaLabel;
    QStringList  recentFiles;
    QString      curFile;

    enum {MaxRecentFiles = 5};

    QAction     *recentFileActions[MaxRecentFiles];
    QAction     *separatorAction;

    QMenu       *fileMenu;
    QMenu       *editMenu;

    QToolBar    *fileToolBar;
    QToolBar    *editToolBar;
    QAction     *newAction;
    QAction     *openAction;

    QAction     *aboutQtAction;
};

#endif // MAINWINDOW_H
