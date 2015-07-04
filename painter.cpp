#include "painter.h"
#include <QPainter>
#include <QWheelEvent>

using namespace std;

class QPaintEvent;
class QWheelEvent;

Painter::Painter(QWidget *parent) :
    QWidget(parent)
{
}

void Painter::paintEvent(QPaintEvent *)
{
    if (factor > 20)
        factor = 1.0;
    QPainter p(this);
    if (!fileName.isNull())
    {
        img = scaledIm(factor);
        p.drawImage(0,0,img);
        this->setFixedSize(img.width(), img.height());
    }
}

QImage Painter::scaledIm(double factor)
{
    img.load(fileName);
        if  ((img.height() < 850) && (img.width() < 850) )
    {
        scaledImg = img.scaled(img.size() * factor, Qt::KeepAspectRatio);
        return scaledImg;
    }
    else
    {
        scaledImg = img.scaled(810 * factor, 800 * factor, Qt::KeepAspectRatio);
        return  scaledImg;
    }
}

void Painter::wheelEvent(QWheelEvent *even)
{
    int numDegrees = even->delta() / 8;
    int numSteps = numDegrees / 5;

    if (numSteps > 0)
       {
         factor = 1.015 * factor; this->update();
       }
       else
       {
           factor = 0.995 * factor; this->update();
       }
}
