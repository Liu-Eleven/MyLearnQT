#include <QtGui/QApplication>
#include "myeditlsy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyEditLSY w;
    w.show();

    return a.exec();
}
