#include "mytreeview.h"

MyTreeView::MyTreeView(QWidget *parent)
    : QMainWindow(parent)
{
    TreeView = new QTreeView(this);

    setCentralWidget(TreeView);

    StandModel = new QStandardItemModel ;


    //获取通用数据模型的根节点
    QStandardItem *item = StandModel->invisibleRootItem() ;


    QList<QStandardItem *> FirstItem = PrepareRow("NAME","SEX","AGE");
    item->appendRow(FirstItem);

    QList<QStandardItem *> SecondRow = PrepareRow("LSY","MALE","20");
    FirstItem.first()->appendRow(SecondRow);
   // item->appendRow(SecondRow);

    TreeView->setModel(StandModel);
    TreeView->expandAll();
}

MyTreeView::~MyTreeView()
{

}

QList <QStandardItem *> MyTreeView::PrepareRow(const QString &first,
                                   const QString &second,
                                   const QString &third)
{
    QList <QStandardItem *> allitems;
    allitems << new QStandardItem(first);
    allitems << new QStandardItem(second);
    allitems << new QStandardItem(third);
    return allitems;

}
