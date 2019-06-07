#include <QtGui/QApplication>
#include "myedittabviewmain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyEditTabViewMain w;
    w.show();

    return a.exec();
}
