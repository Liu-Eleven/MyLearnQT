#ifndef MYCLOCK_H
#define MYCLOCK_H

#include <QtGui>

class MyClock : public QWidget
{
    Q_OBJECT

public:
    MyClock(QWidget *parent = 0);
    ~MyClock();

private slots:
    void rainf();
protected:
    void paintEvent ( QPaintEvent * event );

private:
    QTimer time;
    QColor color;
  //  bool incre;
   // int r;
    //画刻度
    void DrawScale();
    int sec;
};

#endif // MYCLOCK_H
