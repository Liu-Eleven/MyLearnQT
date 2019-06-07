#ifndef MYEDITLSY_H
#define MYEDITLSY_H

#include <QMainWindow>
#include <QtGui>

namespace Ui {
    class MyEditLSY;
}

class MyEditLSY : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyEditLSY(QWidget *parent = 0);
    ~MyEditLSY();
protected:
    void closeEvent(QCloseEvent *);
private slots:

    void DocumentChanged();

    void on_action_Exit_triggered();

    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_action_Save_As_triggered();

    void on_action_Save_triggered();

    void on_action_Cut_triggered();



private:
    Ui::MyEditLSY *ui;

    bool flagEdit ;
    QString CutStr;

    QString GetFileName(const QString &);//得到文件名字
    void SetCurrentFileName(const QString &);//设置当前标题
    void ReadSetting();//读取配置
    void WriteSetting();//写入文件位置记录

    QString SourceName;

};

#endif // MYEDITLSY_H
