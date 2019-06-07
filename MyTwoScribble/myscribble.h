#ifndef MYSCRIBBLE_H
#define MYSCRIBBLE_H

#include <QtGui>

class MyScribble : public QWidget
{
    Q_OBJECT
public:
    explicit MyScribble(QWidget *parent = 0);
    bool SaveAsImage(QString &filename,QByteArray &format);
    bool SaveImage(QString &fileName);
    bool OpenImage(QString &);
    void SetPenColor(const QColor &);
    void SetPenWidth(const int );
    void ClearMyScreen();

    bool modify ;



protected:
    void paintEvent ( QPaintEvent * event ) ;
    void mousePressEvent ( QMouseEvent * event );
    void mouseMoveEvent (QMouseEvent * event);
    void resizeEvent ( QResizeEvent * event );



private:
    QImage image;
    QPoint startPoint;
    QColor MyColor;
    int Mywidth;


    void DrawLineTo(const QPoint  &);



};

#endif // MYSCRIBBLE_H
