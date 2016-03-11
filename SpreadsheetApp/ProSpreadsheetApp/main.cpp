#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /* Main function to handle only a single window
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */

    /* Main function to handle a mutiple document interface */
    QApplication app(argc, argv);
    MainWindow *mainWin = new MainWindow;
    mainWin->show();
    return app.exec();
}
