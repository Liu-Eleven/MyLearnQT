#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QtGui>

class findDialog : public QDialog
{
    Q_OBJECT
public:
    explicit findDialog(QWidget * parent = 0, Qt::WindowFlags f = 0);


    QString  &DlgFindText();

public slots:
    void findclick();
private:
    QLabel  *label;
    QLineEdit *value;
    QPushButton *Btn;
    QString FindText;

};

#endif // FINDDIALOG_H
