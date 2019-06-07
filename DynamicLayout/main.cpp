#include <QtGui/QApplication>
#include "dynamiclayout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DynamicLayout w;
    w.show();

    return a.exec();
}
