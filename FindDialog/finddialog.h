#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QtGui>
#include <QDialog>

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);
    ~FindDialog();

signals:
 //   void findNext(const QString &str,Qt::CaseSensitive cs);
  //  void findPrevious(const QString &str,Qt::CaseSensitivity cs);
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);



private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;

};

#endif // FINDDIALOG_H
