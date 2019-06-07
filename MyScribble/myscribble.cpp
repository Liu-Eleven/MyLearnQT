#include "myscribble.h"
#include <QtGui>

MyScribble::MyScribble(QWidget *parent)
    : QWidget(parent)
{
    image = QImage(QSize(330,310),QImage::Format_ARGB32);
    image.fill(Qt::white);
}

MyScribble::~MyScribble()
{

}



void MyScribble::paintEvent ( QPaintEvent * event )
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//设置抗锯齿
    QRect rect = event->rect();
    painter.drawImage(rect, image, rect);
}
void MyScribble::mousePressEvent ( QMouseEvent * event )
{
    if (event->button() == Qt::LeftButton) {
        startPoint = event->pos();
    }
}
void MyScribble::mouseMoveEvent(QMouseEvent *event)
{
   QPoint EndPoint = event->pos();

   DrawLineTo(EndPoint);
}
void MyScribble::mouseReleaseEvent ( QMouseEvent * event )
{
   // update();
}

void MyScribble::DrawLineTo(const QPoint &EndPoint)
{
    QPainter painter(&image);
    painter.drawLine(startPoint,EndPoint);
    startPoint = EndPoint;
    update();

}
/*
void MyScribble::resizeEvent(QResizeEvent *event)
{
    update();
}
*/
