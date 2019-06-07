#ifndef DYNAMICLAYOUT_H
#define DYNAMICLAYOUT_H

#include <QtGui>

class DynamicLayout : public QWidget
{
    Q_OBJECT

public:
    DynamicLayout(QWidget *parent = 0);
    ~DynamicLayout();

public slots:
    void ChangeUI();
    void UpdataUI(int );
private:
    //顶部所需要的部件
    QGroupBox *TopBox;
    QProgressBar *proBar;
    QSpinBox *spinBox;
    QSlider  *slider;
    QDial *dial;
    QGridLayout *G_TopLayout;

    //QQueue: 通用模板， 提供一个队列
    QQueue <QWidget *> Msg_Queue;

    //初始化顶部界面
    void CreateTopUI();

    //初始化中部界面
    void CreateCenterUI();
    QGroupBox *CentBox;
    QComboBox *ComBox;

    //初始化底部界面
    void CreateBottomUI();
    QDialogButtonBox *buttonBox;
    QPushButton *Btn_Help;
    QPushButton *Btn_Close;
    QPushButton *Btn_Rota;

    //主界面布局管理器
    QGridLayout *M_Layout;
};

#endif // DYNAMICLAYOUT_H
