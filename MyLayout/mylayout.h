#ifndef MYLAYOUT_H
#define MYLAYOUT_H

#include <QtGui>


QT_BEGIN_NAMESPACE
class QDialogButtonBox ;
QT_END_NAMESPACE

class MyLayout : public QWidget
{
    Q_OBJECT


public:
    MyLayout(QWidget *parent = 0);
    ~MyLayout();
private slots:
    void clickbutton1();
private:
    QGroupBox  * groupBox;
    QGroupBox *GridBox;
    QPushButton *button[4];
    QGroupBox *formBox;

    QPushButton *Ok;
    QPushButton *Cancel;
//    QDialogButtonBox *buttonbox;

    QMenuBar *MyMenu;
    QMenu *Menu;
    QAction *Action;

    void AddMenuTool();

    void  AddHorLayout();//初始化第一个布局管理器
    void AddGridLayout();//初始化第二个布局管理器
    void AddFormLayout();//初始化第三个布局管理器
};

#endif // MYLAYOUT_H
