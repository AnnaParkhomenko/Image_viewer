#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
class QPaintEvent;
class QWheelEvent;

class Painter : public QWidget
{
    Q_OBJECT
public:
    explicit Painter(QWidget *parent = 0);
    QString fileName;
    QSize normalSize,  fullSize, imgSize;
    QImage img, scaledImg;
    QImage scaledIm(double factor);
    double factor;

protected:
       virtual void paintEvent(QPaintEvent *);
       virtual void wheelEvent(QWheelEvent *even);
};

#endif // PAINTER_H
