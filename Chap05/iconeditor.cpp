#include "iconeditor.h"

#include <QPainter>
#include <QPaintEvent>

IconEditor::IconEditor(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);

    //Tells any layout manager that widget's size hint
    //is really its minimum size
    //can be stretched, should never shrink below size hint
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    curColor = Qt::black;
    zoom = 8;//each pixel in the icon will be redered as an 8x8 square

    image = QImage(16, 16, QImage::Format_ARGB32);
    image.fill(qRgba(0,0,0,0));
}


/*
 * Reimplemented from QWidget
 * returns ideal size of a widget
 */
QSize IconEditor::sizeHint() const
{
    QSize size = zoom * image.size();
    if(zoom >= 3)
        size += QSize(1, 1); //Add additional space to show a grid, doesn't make sense if < 3
    return size;
}

void IconEditor::setPenColor(const QColor &newColor)
{
    curColor = newColor;
}

void IconEditor::setIconImage(const QImage &newImage)
{
    if(newImage != image)
    {
        //convert to 32-bit with alpha buffer
        image = newImage.convertToFormat(QImage::Format_ARGB32);
        update();//repaint widget
        updateGeometry();//tell any layout that the widget's sizehint has changed
    }
}

void IconEditor::setZoomFactor(int newZoom)
{
   if(newZoom < 1)
       newZoom = 1;

   if(newZoom != zoom)
   {
       zoom = newZoom;
       update();
       updateGeometry();
   }
}

void IconEditor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(zoom >= 3)
    {
        painter.setPen(palette().foreground().color());
        for(int i = 0; i <= image.width(); ++i)
            painter.drawLine(zoom * i, 0, zoom * i, zoom * image.height());
        for(int j = 0; j <= image.height(); ++j)
            painter.drawLine(0, zoom * j, zoom * image.width(), zoom * j);
    }

    for(int i = 0; i < image.width(); ++i)
    {
        for(int j = 0; j < image.height(); ++j)
        {
            QRect rect = pixelRect(i, j);
            if(!event->region().intersects(rect).isEmpty())
            {
                QColor color = QColor::fromRgba(image.pixel(i, j));
                if(color.alpha() < 255)
                    painter.fillRect(rect, Qt::white);
                painter.fillRect(rect, color);
            }
        }
    }
}

