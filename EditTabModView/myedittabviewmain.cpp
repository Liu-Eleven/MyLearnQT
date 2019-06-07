#include "myedittabviewmain.h"
#include "edittabmodeview.h"
#include <QTableView>

MyEditTabViewMain::MyEditTabViewMain(QWidget *parent)
    : QMainWindow(parent)
{
    tableview = new QTableView(this) ;
    setCentralWidget(tableview);
    QAbstractTableModel *mymodel = new EditTabModeView(this);
    tableview->setModel(mymodel);
    connect(mymodel,SIGNAL(editCompleted(const QString &)),
            this,SLOT(ShowWindowTitle(QString)));
}

MyEditTabViewMain::~MyEditTabViewMain()
{

}

void MyEditTabViewMain::ShowWindowTitle(const QString &title)
{
    setWindowTitle(title);
}
