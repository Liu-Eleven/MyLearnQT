#include "myselecttreeview.h"

MySelectTreeView::MySelectTreeView(QWidget *parent)
    : QMainWindow(parent)
{
    TreeView = new QTreeView(this);
    setCentralWidget(TreeView);

    StandardModel = new QStandardItemModel ;

    QStandardItem *rootNode = StandardModel->invisibleRootItem();

    QStandardItem *HeNan = new QStandardItem("He Nan");
    QStandardItem *NanYang = new QStandardItem("Nan Yang");
    QStandardItem *XinXiang = new QStandardItem("Xin Xiang");
    QStandardItem *TangHe = new QStandardItem("Tang He");

    QStandardItem *HuBei = new QStandardItem("Hu Bei");
    QStandardItem *XiangFan = new QStandardItem("Xiang Fan");
    QStandardItem *ShiYan = new QStandardItem("Shi Yan");
    QStandardItem *ZaoYang = new QStandardItem("Zao Yang");

    //根节点添加河南湖北两个省份
    rootNode->appendRow(HeNan);
    rootNode->appendRow(HuBei);

    //在河南添加新乡和南阳
    HeNan->appendRow(XinXiang);
    HeNan->appendRow(NanYang);


    //在南阳添加唐和
    NanYang->appendRow(TangHe);

    //在湖北添加襄樊
    HuBei->appendRow(XiangFan);

    //在襄樊添加十晏和枣阳
    XiangFan->appendRow(ShiYan);
    XiangFan->appendRow(ZaoYang);

    TreeView->setModel(StandardModel);

    //设置全部展开
    //TreeView->expandAll();

    //QItemSelectionModel ：　跟踪一个视图的被选择的项
    QItemSelectionModel *SelectModel = TreeView->selectionModel();

    //void QItemSelectionModel::selectionChanged ( const QItemSelection & selected, const QItemSelection & deselected ) [signal]
    //选择改变时， 发出信号selectionChanged(。。。)
    connect(SelectModel ,SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
            this,SLOT(selectionChangedSlot (const QItemSelection &, const QItemSelection &)));

}

MySelectTreeView::~MySelectTreeView()
{

}

void MySelectTreeView::selectionChangedSlot (const QItemSelection &/*newSelection*/, const QItemSelection & /*oldSelection*/)
{
    //获取被选项的QModelIndex
    const QModelIndex index = TreeView->selectionModel()->currentIndex();

    //返回QModelIndex所指向的数据
    QString SelectedText = index.data(Qt::DisplayRole).toString();

    //获取被选项在树形结构中的层次
    int i = 1;//int hierarchyLevel=1; 不明白
    QModelIndex seekRoot = index;
    while(seekRoot.parent() != QModelIndex() )
    {
        seekRoot = seekRoot.parent();
        i++;
    }

    QString showString = QString("%1 , Level %2").arg(SelectedText)
                         .arg(i);
    setWindowTitle(showString);
}



