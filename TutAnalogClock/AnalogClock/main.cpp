#include "analogclock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnalogClock *ac = new AnalogClock();
    ac->show();

    return a.exec();
}
