#include "tabmodtime.h"

TabModTime::TabModTime( QObject * parent )
    : QAbstractTableModel(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerHit()));
    timer->start();
}

TabModTime::~TabModTime()
{

}
int TabModTime::rowCount(const QModelIndex &) const
{
    return 2;
}
int TabModTime::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant TabModTime::data(const QModelIndex &index ,int role) const
{
    int row = index.row();
    int column = index.column();

   // QString str = "LSY";

    switch(role)
    {
    case Qt::DisplayRole://设置文本
        if(row == 0 && column == 0)
             return QTime::currentTime().toString();
        break;
    case Qt::BackgroundColorRole://设置被景色
        if(row == 0 && column == 0)
        {
            QBrush brush(Qt::yellow);
            return brush;
        }
    case Qt::FontRole://设置字体
        if(row == 0 && column == 0)
        {
            QFont font;
            //font.setBold(true);
            font.setStyle(QFont::StyleOblique);//倾斜字体StyleOblique
            font.setPointSize(15);
            return font;
        }
    case Qt::TextAlignmentRole://设置文本对齐方式
        if(row == 0 && column == 0)
        {
            return Qt::AlignHCenter + Qt::AlignVCenter;
        }
    }


    return QVariant();
}

QVariant TabModTime::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)//如果是水平方向
        {
            switch(section)
            {
            case 0:
                return QString(tr("NAME"));
            case 1:
                return QString(tr("SEX"));
            case 2:
                return QString(tr("AGE"));
            }
        }
        if(orientation == Qt::Vertical)//如果是垂直方向
        {
            switch(section)
            {
            case 0:
                return QString(tr("1.0"));
            case 1:
                return QString(tr("2.0"));
            }
        }
    }
    return QVariant();
}

void TabModTime::timerHit()
{
    QModelIndex topLeft = createIndex(0,0);

    emit dataChanged(topLeft,topLeft);
}
