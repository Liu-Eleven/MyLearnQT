#include <QtGui/QApplication>
#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindDialog *dialog = new FindDialog;
    //w.show();
    dialog->show();
    return a.exec();
}
