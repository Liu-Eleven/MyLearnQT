#ifndef MYMODE_H
#define MYMODE_H

#include <QtGui>

class MyMode : public QAbstractTableModel
{
    Q_OBJECT

public:
    MyMode( QObject * parent = 0 );
    ~MyMode();

    int rowCount(const QModelIndex &parent = QModelIndex() ) const;
    int columnCount(const QModelIndex &parent = QModelIndex() ) const;
    QVariant data(const QModelIndex &index , int role = Qt::DisplayRole ) const;
};

#endif // MYMODE_H
