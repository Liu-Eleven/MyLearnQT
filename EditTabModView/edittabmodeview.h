#ifndef EDITTABMODEVIEW_H
#define EDITTABMODEVIEW_H

#include <QtGui>


const int ROW = 2;
const int COL = 3;
class EditTabModeView : public 	QAbstractTableModel
{
    Q_OBJECT
public:
    EditTabModeView( QObject * parent = 0 );
    //重载系统虚函数
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index , int role = Qt::DisplayRole ) const ;
    //设置数据
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    //设置标志位,系统虚函数
    Qt::ItemFlags flags(const QModelIndex &index) const;


signals:
    void editCompleted(const QString &);//自定义信号

private:
    QString GridData[ROW][COL];

};

#endif // EDITTABMODEVIEW_H
