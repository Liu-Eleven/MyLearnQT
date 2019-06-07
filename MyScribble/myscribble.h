#ifndef MYSCRIBBLE_H
#define MYSCRIBBLE_H

#include <QtGui>

class MyScribble : public QWidget
{
    Q_OBJECT

public:
    MyScribble(QWidget *parent = 0);
    ~MyScribble();
protected:
    void paintEvent ( QPaintEvent * event );
    void mousePressEvent ( QMouseEvent * event );
    void mouseMoveEvent ( QMouseEvent * event ) ;
    void mouseReleaseEvent ( QMouseEvent * event );
   /* void resizeEvent(QResizeEvent *event);*/
private:
    void DrawLineTo(const QPoint & );

    QImage image;

    QPoint startPoint;
};

#endif // MYSCRIBBLE_H
