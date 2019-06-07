#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include"myscribble.h"
#include <QMainWindow>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = 0);

signals:

public slots:

private:
    MyScribble *scribble;

};

#endif // MYMAINWINDOW_H
