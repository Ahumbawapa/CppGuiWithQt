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
    static const QPoint secondHand[3] = {
        QPoint(2,8)
       ,QPoint(-2,8)
       ,QPoint(0, -90)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(90, 90, 90, 100);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    // draws diagonal lines smoother
    painter.setRenderHint(QPainter::Antialiasing);
    //move origin to center of the widget
    painter.translate(width()/2, height()/2);
    //
    painter.scale(side/200.0, side/200.0);

    //draw hour hand
    painter.setPen(Qt::NoPen);      //NoPen-> no outline
    painter.setBrush(hourColor);    //Brushes are used to filling polygons

    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);
    for(int i = 0; i < 12; ++i)
    {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    //draw minute hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);
    for(int j = 0; j < 60; ++j)
    {
        if((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    //draw second hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.save();

    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();

}
