#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char *argv[])
{
    //Application object to manage application-wide resources.
    QApplication app(argc, argv);
    //Create a QLabel Widget. Is here the main window!
    QLabel *label = new QLabel("<h2><i>Hello</i>" "<font color=red>Qt</font></h2>");
    //Widgets are always created hidden for avoiding flickering during customization
    label->show();
    //Pass control of the appliation on to Qt. Enter event loop
    return app.exec();
}
