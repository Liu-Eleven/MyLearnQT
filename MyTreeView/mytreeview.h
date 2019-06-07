#ifndef MYTREEVIEW_H
#define MYTREEVIEW_H

#include <QtGui>

class MyTreeView : public QMainWindow
{
    Q_OBJECT

public:
    MyTreeView(QWidget *parent = 0);
    ~MyTreeView();

private:
    //树形视图
    QTreeView *TreeView;
    //QStandardItemModelPrivate: 通用数据模型
    QStandardItemModel *StandModel;

    QList <QStandardItem *> PrepareRow(const QString &first,
                                       const QString &second,
                                       const QString &third);
};

#endif // MYTREEVIEW_H
