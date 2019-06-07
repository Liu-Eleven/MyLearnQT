#include <QtGui/QApplication>
#include "mytreeview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTreeView w;
    w.show();

    return a.exec();
}
