#include "myclock.h"

MyClock::MyClock(QWidget *parent)
    : QWidget(parent)
{

    //增加布局管理器
    QFormLayout *formLayout = new QFormLayout;
    QHBoxLayout *H_Layout = new QHBoxLayout;
    QLabel *label = new QLabel(tr("MADE BY LSY"));

    H_Layout->addStretch();
    H_Layout->addWidget(label);
    H_Layout->addStretch();

    formLayout->addRow(new QLabel);
    formLayout->addRow(H_Layout);

    time.setInterval(1000);
    connect(&time,SIGNAL(timeout()),this,SLOT(rainf()));
    time.start();

    resize(200,200);


    setLayout(formLayout);
    setWindowTitle("My clock");
    //setMinimumSize(200,200);
    //setMaximumSize(200,200);
}

/*
  //  incre = true;
  //  r = 10;
    QPainter painter(this);
    //设为抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

   // painter.drawLine(100,0,100,200);
  //  painter.drawLine(0,100,200,100);

    //painter.drawRect(50,50,100,100);

    //第一种画圆的方法
    //painter.drawEllipse(50,50,100,100);
    //第二种画圆的方法
    //painter.drawEllipse(QPoint(100,100),50,50);

    //第三种画圆的方法
    //移动坐标
    color = QColor(qrand()%255,qrand()%255,qrand()%255);
    //painter.setPen(color);
    QPen pen(Qt::DashLine);    qDebug()<<"lsy";
    pen.setColor(color);
    painter.setPen(pen);


    if(incre)
    {
        if(r < 100)
            r++;
        else
            incre = false;
    }else
    {
        if(r > 10)
            r --;
        else
            incre = true;
    }
    painter.translate(100,100);
    painter.drawEllipse(QPoint(0,0),r,r);



*/



void MyClock::paintEvent (QPaintEvent * event)
{
    //定义时针
    QPoint hourHand[3] ={
        QPoint(-6,6),
        QPoint(6,6),
        QPoint(0,-40)
    };
    //定义分针
    QPoint minuteHand[3]={
        QPoint(-6,6),
        QPoint(6,6),
        QPoint(0,-65)
    };

    //定义秒针
    QPoint secondHand[3]={
        QPoint(-4,4),
        QPoint(4,4),
        QPoint(0,-90)
    };

    //获取最小值
    int side = qMin(width(),height());


    //创建画板
    QPainter painter(this);
    //设为抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    //移动坐标
    painter.translate(width()/2,height()/2);

    //缩放比例
    painter.scale(side/200.0,side/200.0);

    //定义分针和时针的颜色
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
   // QColor secondColor(128,89,166,191);
    QColor secondColor = QColor(qrand()%255,qrand()%255,qrand()%255);

    //画刻度
    DrawScale();


    //得到当前时间
    QTime time = QTime::currentTime();
    sec = time.second();




    //画秒针
    painter.save();;
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand,3);//画多边形
    painter.restore();


    //画时针
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.rotate(30.0 * ((time.hour()) + (time.minute()/60.0)) );
    painter.drawConvexPolygon(hourHand,3);
    painter.restore();

    //画分针
    painter.save();
    painter.setPen(Qt::NoPen);//不绘制边框
    painter.setBrush(Qt::FDiagPattern);//选取画刷样式
    painter.rotate(6.0 * ( (time.minute()) + (time.second()/60.0) ) );
    painter.setBrush(minuteColor);
    painter.drawConvexPolygon(minuteHand,3);
    painter.restore();

    //写标签
    QPen pen(Qt::DashDotLine);
    pen.setColor(secondColor);
    painter.setPen(pen);


    QString Str_Sec;
    QString str = tr("MADE IN IMTI : ");
    Str_Sec.setNum(sec,10);
    str += Str_Sec;
    painter.drawText(-(width()/4),(height()/4),str);

}


void MyClock::DrawScale()
{
    //获取最小值
    int side = qMin(width(),height());

    //创建画板
    QPainter painter(this);
    //设置为抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    //移动坐标系
    painter.translate(width()/2,height()/2);
    //缩放比例
    painter.scale(side/200.0,side/200.0);

    //时针颜色
    QColor hourColor(127, 0, 127);

    //定义画笔
    QPen pen(Qt::CustomDashLine);
    //选取画笔颜色
    pen.setColor(hourColor);

    //选择画笔
    painter.setPen(pen);
    for(int i=0;i<12;i++)
    {
        painter.drawLine(92,0,98,0);
        painter.rotate(30);
    }

    //定义分针颜色
    QColor minuteColor(0, 127, 127, 191);
    //重新为画笔选择颜色
    pen.setColor(minuteColor);
    //选取画笔
    painter.setPen(pen);
    for(int i=0;i<60;i++)
    {
        if(i % 5 == 0)
        {
            painter.rotate(6);
            continue;
        }else
        {
            painter.drawLine(93,0,96,0);
            painter.rotate(6);
        }
    }


}

void MyClock::rainf()
{
    update();
}

MyClock::~MyClock()
{

}
