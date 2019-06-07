#include <QtGui/QApplication>
#include "myselecttreeview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySelectTreeView w;
    w.show();

    return a.exec();
}
