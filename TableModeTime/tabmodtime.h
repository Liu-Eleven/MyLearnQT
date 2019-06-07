#ifndef TABMODTIME_H
#define TABMODTIME_H

#include <QtGui>

class TabModTime : public QAbstractTableModel
{
    Q_OBJECT

public:
    TabModTime( QObject * parent = 0 );
    ~TabModTime();
    //虚函数
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index ,int role = Qt::DisplayRole) const;
private slots:
    void timerHit();
private:

    QTimer *timer;
};

#endif // TABMODTIME_H
