#include <QtGui/QApplication>
#include "extendlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExtenDlg w;
    w.show();

    return a.exec();
}
