#include <QtGui/QApplication>
#include "mylayout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyLayout w;
    w.show();

    return a.exec();
}
