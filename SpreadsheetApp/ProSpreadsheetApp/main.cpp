#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

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

    //Add splashscreen
    QSplashScreen *splashScreen = new QSplashScreen;
    splashScreen->setPixmap(QPixmap(":/images/INKALogo.png"));
    splashScreen->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splashScreen->showMessage(  QObject::tr("Setting up the main window...")
                              , topRight, Qt::blue);


    MainWindow *mainWin = new MainWindow;

    splashScreen->showMessage(  QObject::tr("Loading modules...")
                              , topRight, Qt::white);

    //QThread::sleep(1);

    splashScreen->showMessage(  QObject::tr("Establishing connections...")
                              , topRight, Qt::white);

    //QThread::sleep(1);

    mainWin->show();
    splashScreen->finish(mainWin);
    delete splashScreen;

    return app.exec();
}
