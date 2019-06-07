#ifndef MYSELECTTREEVIEW_H
#define MYSELECTTREEVIEW_H

#include <QtGui>

class MySelectTreeView : public QMainWindow
{
    Q_OBJECT

public:
    MySelectTreeView(QWidget *parent = 0);
    ~MySelectTreeView();

private:
    QTreeView *TreeView;
    QStandardItemModel *StandardModel;

private slots:
    void selectionChangedSlot (const QItemSelection &newSelection, const QItemSelection &oldSelection);
};

#endif // MYSELECTTREEVIEW_H
