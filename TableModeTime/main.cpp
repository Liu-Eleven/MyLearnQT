#include <QtGui/QApplication>
#include <QAbstractTableModel>
#include "tabmodtime.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView Tableview;
    TabModTime Mymode(0);
    Tableview.setModel(&Mymode);

    Tableview.show();

    return a.exec();
}
