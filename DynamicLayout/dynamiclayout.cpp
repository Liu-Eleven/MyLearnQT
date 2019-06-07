#include "dynamiclayout.h"

DynamicLayout::DynamicLayout(QWidget *parent)
    : QWidget(parent)
{
    CreateTopUI();
    CreateCenterUI();
    CreateBottomUI();

    M_Layout = new QGridLayout;
    M_Layout->addWidget(TopBox,0,0);
    M_Layout->addWidget(CentBox,1,0);
    M_Layout->addWidget(buttonBox,2,0);
    setLayout(M_Layout);
    M_Layout->setSizeConstraint(QLayout::SetMinimumSize);
}

DynamicLayout::~DynamicLayout()
{

}

//创建顶部界面
void DynamicLayout::CreateTopUI()
{
    TopBox = new QGroupBox(tr("Rotable Widgets"));
    proBar = new QProgressBar;
    spinBox = new QSpinBox;
    slider = new QSlider;
    dial = new QDial;

    G_TopLayout = new QGridLayout;

    Msg_Queue.append(proBar);
    Msg_Queue.append(spinBox);
    Msg_Queue.append(slider);
    Msg_Queue.append(dial);

    for(int i=0,j=0;i<2; i++,j++)
    {
        int k=0;
        G_TopLayout->addWidget(Msg_Queue.at(j),i,k);
        k++;
        G_TopLayout->addWidget(Msg_Queue.at(++j),i,k);
    }
    TopBox->setLayout(G_TopLayout);
    for(int n=0;n<4;n++)
    {
        if(n == 3)
        {
            connect(Msg_Queue.at(n),SIGNAL(valueChanged(int)),
                    Msg_Queue.at(n-3),SLOT(setValue(int)));
            break;
        }else
            connect(Msg_Queue.at(n),SIGNAL(valueChanged(int)),
                    Msg_Queue.at(n+1),SLOT(setValue(int)));
    }


}

void DynamicLayout::CreateCenterUI()
{
    CentBox = new QGroupBox(tr("Options"));
    QFormLayout *formLayout = new QFormLayout;
    ComBox = new QComboBox;
    ComBox->addItem(tr("Horizontal"));
    ComBox->addItem(tr("Vertical"));
    formLayout->addRow(new QLabel(tr("Orientation of buttons")),ComBox);
    CentBox->setLayout(formLayout);
    connect(ComBox,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdataUI(int)));
}

void DynamicLayout::CreateBottomUI()
{
    buttonBox = new QDialogButtonBox;
    Btn_Help = new QPushButton(tr("&Help"));
    Btn_Close = new QPushButton(tr("&Close"));
    //Btn_Rota = new QPushButton(tr("&Rotate Widgets"));

    Btn_Help = buttonBox->addButton(QDialogButtonBox::Help);
    Btn_Close = buttonBox->addButton(QDialogButtonBox::Close);
    Btn_Rota = buttonBox->addButton(tr("&Rotate Widgets"),
                                    QDialogButtonBox::ActionRole);

    connect(Btn_Rota,SIGNAL(clicked()),this,SLOT(ChangeUI()));
    //connect(Btn_Help,SIGNAL(clicked()),this,SLOT(help()));
    connect(Btn_Close,SIGNAL(clicked()),this,SLOT(close()));
}

void DynamicLayout::ChangeUI()
{
    foreach(QWidget *temp,Msg_Queue)
    {
        G_TopLayout->removeWidget(temp);
    }

    QWidget *head = Msg_Queue.dequeue();
    Msg_Queue.enqueue(head);
    for(int i=0,j=0;i<2; i++,j++)
    {
        int k=0;
        G_TopLayout->addWidget(Msg_Queue.at(j),i,k);
        k++;
        G_TopLayout->addWidget(Msg_Queue.at(++j),i,k);
    }



}
//本模块有问题
void DynamicLayout::UpdataUI(int index)
{
    M_Layout->setSizeConstraint(QLayout::SetNoConstraint);
    setMinimumSize(0, 0);
    Qt::Orientation orientation = Qt::Orientation(
                ComBox->itemData(index).toInt());

    if (orientation == buttonBox->orientation())
        return;
    M_Layout->removeWidget(buttonBox);

    //属性spacing保存在布局内的控件之间的空隙大小
    int spacing = M_Layout->spacing();

    //属性sizeHint用于保存控件推荐的大小
    QSize oldSizeHint = buttonBox->sizeHint() + QSize(spacing, spacing);
    //属性orientation用于保存button box的方向
    buttonBox->setOrientation(orientation);
    QSize newSizeHint = buttonBox->sizeHint() + QSize(spacing, spacing);

    if (orientation == Qt::Horizontal) {
        M_Layout->addWidget(buttonBox, 2, 0);
        //调整控件的大小
        resize(size() + QSize(-oldSizeHint.width(), newSizeHint.height()));
    }
    if(orientation == Qt::Vertical){
        qDebug()<<"lsdf";
        M_Layout->addWidget(buttonBox, 0, 3, 2, 1);
        resize(size() + QSize(newSizeHint.width(), -oldSizeHint.height()));
    }

    M_Layout->setSizeConstraint(QLayout::SetDefaultConstraint);

}

