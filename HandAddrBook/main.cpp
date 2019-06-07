#include <QtGui/QApplication>
#include "handaddrbook.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HandAddrBook w;
    w.show();

    return a.exec();
}
