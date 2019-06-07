#ifndef EXTENDLG_H
#define EXTENDLG_H

#include <QtGui>

class ExtenDlg : public QDialog
{
    Q_OBJECT

public:
    ExtenDlg(QWidget *parent = 0);
    ~ExtenDlg();
    void initBasicInfo();
    void initDetailInfo();
public slots:
    void slot2Extension();
private:
    QWidget *baseWidget;
    QWidget *detailWidget;

};

#endif // EXTENDLG_H
