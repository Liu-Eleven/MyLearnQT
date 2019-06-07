#include <QtGui>
#include "mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    scribble = new MyScribble;
    setCentralWidget(scribble);
    resize(330,310);
}
