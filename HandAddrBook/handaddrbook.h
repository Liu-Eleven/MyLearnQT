#ifndef HANDADDRBOOK_H
#define HANDADDRBOOK_H

#include <QtGui>
#include "finddialog.h"

class HandAddrBook : public QWidget
{
    Q_OBJECT

public:
    HandAddrBook(QWidget *parent = 0);
    ~HandAddrBook();
    enum MODE {INIT,ADD,EDIT,CANCEL};
private slots:
    void AddData();
    void EditData();
    void RemoveData();
    void FindData();
    void SubmitData();
    void CancelData();
    void LoadData();
    void SaveData();
    void ExportData();
    void PreviousData();
    void NextData();


private:
    QMap<QString,QString> MyMap;
    QString OldName;
    QString OldAddr;

    QLineEdit *edit_Name;
    QTextEdit *text_Address;
    QGridLayout *M_Layout;

    QPushButton *button[11];
    QHBoxLayout *h_Layout;
    QVBoxLayout *v_Layout;

    void initializationUi();
    void UpdateUI(MODE mode);
    void CancleStat();
    void DeleteDate(QString name);
    MODE mode ;

    findDialog *dialog;

};

#endif // HANDADDRBOOK_H
