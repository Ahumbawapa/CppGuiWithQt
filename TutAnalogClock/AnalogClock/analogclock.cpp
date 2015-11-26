#include "analogclock.h"
#include <QtWidgets>

AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    setWindowTitle(tr("Analog Clock"));
    resize(200,200);

}

void AnalogClock::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {  QPoint(7,8)
                                        ,QPoint(-8,8)
                                        ,QPoint(0, -40)
                                      };

    static const QPoint minuteHand[3] = { QPoint(7,8)
                                         ,QPoint(-7,8)
                                         ,QPoint(0,-70)
                                        };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    // draws diagonal lines smoother
    painter.setRenderHint(QPainter::Antialiasing);
    //move origin to center of the widget
    painter.translate(width()/2, height()/2);
    //
    painter.scale(side/200.0, side/200.0);
}
