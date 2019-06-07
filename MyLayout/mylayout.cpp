#include "mylayout.h"

MyLayout::MyLayout(QWidget *parent)
    : QWidget(parent)
{
    AddMenuTool();

    AddHorLayout();
    AddGridLayout();
    AddFormLayout();

    QVBoxLayout * M_Layout = new QVBoxLayout;
    M_Layout->setMenuBar(MyMenu);
    QTextEdit *text1 = new QTextEdit("this is test formlayout!");
    M_Layout->addWidget(groupBox);
    M_Layout->addWidget(GridBox);
    M_Layout->addWidget(formBox);
    M_Layout->addWidget(text1);


   //添加确认和取消按钮
    QHBoxLayout *endlayout = new QHBoxLayout;
    Ok = new QPushButton("&OK");
    Cancel = new QPushButton("&Cancel");
    //endlayout->addSpacing(250);
    endlayout->addStretch();
    endlayout->addWidget(Ok);
    endlayout->addWidget(Cancel);
    M_Layout->addLayout(endlayout);
    connect(Ok,SIGNAL(clicked()),this,SLOT(close()));
    connect(Cancel,SIGNAL(clicked()),this,SLOT(close()));


    setLayout(M_Layout);
    setMaximumWidth(250);
    setMaximumHeight(450);

  //  buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  /*  buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok
                                         | QDialogButtonBox::Cancel);

        connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
        connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));

   M_Layout->addWidget(buttonbox);*/



}

MyLayout::~MyLayout()
{

}
//初始化第一个布局管理器
void MyLayout::AddHorLayout()
{


    QString str[4] = {"button 1","Button 2","button 3","button 4"};
    int i;
    QHBoxLayout *H_Layout = new QHBoxLayout;
    for(i=0;i<4;i++)
    {
        button[i] = new QPushButton;
        button[i]->setText(str[i]);
        H_Layout->addWidget(button[i]);

    }
    groupBox = new QGroupBox(tr("Horizontal layout"));
    groupBox->setLayout(H_Layout);
    connect(button[1],SIGNAL(clicked()),this,SLOT(clickbutton1()));

}
//初始化第二个布局管理器
void MyLayout::AddGridLayout()
{
    QLabel *label[3];
    QLineEdit *edit[3];
    QString str[3] = {"label 1","label 2","label 3"};
    QGridLayout *G_Layout = new QGridLayout;

    int i;
    for(i=0;i<3;i++)
    {
        label[i] = new QLabel;
        label[i]->setText(str[i]);
        G_Layout->addWidget(label[i],i,0,1,1);

        edit[i] = new QLineEdit;
        G_Layout->addWidget(edit[i],i,1,1,1);
    }
   QTextEdit *text = new QTextEdit("This is simple.");
   G_Layout->addWidget(text,0,2,4,1);
   GridBox = new QGroupBox(tr("Grid layout"));
   GridBox->setLayout(G_Layout);
}
//增加一个管理器
 void MyLayout::AddFormLayout()
 {
     formBox = new QGroupBox(tr("Form layout"));

     QFormLayout *fromlayout = new QFormLayout;
     fromlayout->addRow(new QLabel(tr("Label 1:")),new QLineEdit);
     fromlayout->addRow(new QLabel(tr("Label 2:")),new QComboBox);
     fromlayout->addRow(new QLabel(tr("Label 2:")),new QLineEdit);
     formBox->setLayout(fromlayout);
 }
//添加一个菜单
 void MyLayout::AddMenuTool()
 {
     MyMenu = new QMenuBar;
     Menu = new QMenu(tr("&File"),this);
     Action = Menu->addAction(tr("&Exit"));
     MyMenu->addMenu(Menu);
     connect(Action,SIGNAL(triggered()),this,SLOT(close()));
 }

void MyLayout::clickbutton1()
{
    QMessageBox::about(this,"Clue on","You click button1");

}
