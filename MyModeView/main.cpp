#include <QtGui/QApplication>
#include <QtGui/QTableView>
#include "mymode.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableview;

    MyMode mode(0);
    tableview.setModel(&mode);
    tableview.show();

    return a.exec();
}


