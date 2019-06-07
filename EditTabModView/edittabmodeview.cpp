#include "edittabmodeview.h"

EditTabModeView::EditTabModeView( QObject * parent) :
    QAbstractTableModel(parent)
{
}
//返回行
int EditTabModeView::rowCount(const QModelIndex & )const
{
    return ROW;
}
//返回列
int EditTabModeView::columnCount(const QModelIndex & ) const
{
    return COL;
}

//读取数据并显示到表格
QVariant EditTabModeView::data(const QModelIndex &index , int role) const
{
    if(role == Qt::DisplayRole)
    {
        return GridData[index.row()][index.column()];
    }
    return QVariant();
}

//设置表格数据
bool EditTabModeView::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
    {
        GridData[index.row()][index.column()] = value.toString() ;

        QString result ;
        for(int i=0 ; i < ROW ; i ++ )
        {
            for(int j=0 ; j< COL ; j++)
            {
                result += GridData[i][j]+" ";
            }
        }
        emit editCompleted(result);
    }
    return true;
}

//根据指定的位置读取数据的flags
Qt::ItemFlags EditTabModeView::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}
