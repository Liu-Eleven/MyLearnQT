#include "myscribble.h"

MyScribble::MyScribble(QWidget *parent) :
    QWidget(parent)
{
    image = QImage(QSize(330,310),QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    //初始化画笔颜色
    QColor color = QColor(40,180,215);
    MyColor = color;
    Mywidth = 1;

    modify = false;
}

//把临时画布的图片贴到画板上
void MyScribble::paintEvent ( QPaintEvent * event )
{
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect,image,rect);
}

void MyScribble::mousePressEvent ( QMouseEvent * event )
{
    if( Qt::LeftButton == event->button() )
        startPoint = event->pos();
    modify = true;
}
void MyScribble::mouseMoveEvent (QMouseEvent * event)
{
    if( event->buttons() & Qt::LeftButton )
        DrawLineTo(event->pos());
}
//在临时画布上画图
void MyScribble::DrawLineTo(const QPoint  &lastPoint)
{
    QPainter painter(&image);

    QPen pen(Qt::SolidLine);
    pen.setWidth(Mywidth);
    pen.setColor(MyColor);

    painter.setPen(pen);
    painter.drawLine(startPoint,lastPoint);
    startPoint = lastPoint;
    update();
}
//另存为。。。
bool MyScribble::SaveAsImage(QString &filename,QByteArray &format)
{
    return image.save( filename, format);

}
//保存图片
bool MyScribble::SaveImage(QString &fileName)
{
    qDebug()<<"modify image";
    return image.save(fileName);

}
//打开图片
bool MyScribble::OpenImage(QString &filename)
{
    bool flag = image.load(filename);
    if(flag == false)
        return flag;
    update();
    return flag;
}
//窗口屏幕大小被改变事件
void MyScribble::resizeEvent ( QResizeEvent * event )
{
    int w = event->size().width();
    int h = event->size().height();

    if(w > image.width() || h > image.height())
    {
        QImage NewImage = QImage(QSize(event->size()),QImage::Format_RGB32);
        NewImage.fill(Qt::white);
        QPainter painter(&NewImage);
        painter.drawImage(QPoint(0,0),image);
        image = NewImage;
    }
}

//选取颜色
void MyScribble::SetPenColor(const QColor &newColor)
{
    MyColor = newColor;

}

//设置笔的宽度
void MyScribble::SetPenWidth(const int newWidth)
{
    Mywidth = newWidth;
}

//清除屏幕
void MyScribble::ClearMyScreen()
{
    image.fill(Qt::white);
    update();
    //qDebug()<<"clear...";
}
