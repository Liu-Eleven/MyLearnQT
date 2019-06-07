#ifndef MYEDITTABVIEWMAIN_H
#define MYEDITTABVIEWMAIN_H

#include <QtGui>


class MyEditTabViewMain : public QMainWindow
{
    Q_OBJECT

public:
    MyEditTabViewMain(QWidget *parent = 0);
    ~MyEditTabViewMain();

private:
    QTableView *tableview;
private slots:
    void ShowWindowTitle(const QString &);

};

#endif // MYEDITTABVIEWMAIN_H
