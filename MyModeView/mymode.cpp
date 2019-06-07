#include "mymode.h"

MyMode::MyMode( QObject * parent)
    : QAbstractTableModel(parent)
{

}

MyMode::~MyMode()
{

}

int MyMode::rowCount(const QModelIndex & ) const
{
    return 2;
}
int MyMode::columnCount(const QModelIndex &) const
{
    return 3;
}



QVariant MyMode::data(const QModelIndex &index , int role) const
{
    int row = index.row();
    int column = index.column();

    qDebug()<<QString("row = %1 , column = %2 role = %3").arg(index.row()+1).arg(index.column()+1).arg(role);

    switch(role)
    {
    case Qt::DisplayRole: //文本
        if(row == 0 && column == 1) return QString("<----left");
        if(row == 1 && column == 1) return QString("right---->");

        return QString("%1 Row , %2Column")
                 .arg(index.row()+1)
                 .arg(index.column()+1);
        break;
    case Qt::FontRole: //字体颜色
        if(row == 0 && column == 0)
       {
            QFont font;
            font.setBold(true);
            //font.setPointSize(20);设置笔的粗细
            return font;
        }
        break;
    case Qt::BackgroundRole://背景色
        if(row == 1 && column == 2)
        {
            QBrush brush(Qt::yellow);
            return brush;
        }
        break;
    case Qt::TextAlignmentRole://文本对齐方式
        if(row == 1 && column == 1)
        {
            return Qt::AlignRight + Qt::AlignVCenter;
        }
        break;
    case Qt::CheckStateRole://复选框
        if(row == 1 && column == 0)
        {
            return Qt::Checked;
        }
        break;
    }
    return QVariant();
}



/*
  bak
QVariant MyMode::data(const QModelIndex &index , int role) const
{
 //   QString str[6]={"LSY","RHZ","ZY","NXY","WF","ZML"};
    if( role == Qt::DisplayRole )
    {
       return QString("%1 Row , %2Column")
                .arg(index.row()+1)
                .arg(index.column()+1);
        qDebug()<<"i = "<<i;
        i++;
        return QString(str[i]);
    }
    return QVariant();
}
*/
