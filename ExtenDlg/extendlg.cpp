#include "extendlg.h"

ExtenDlg::ExtenDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Extension Dialog");
    initBasicInfo();
    initDetailInfo();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(baseWidget);
    layout->addWidget(detailWidget);

    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->setSpacing(6);

    setLayout(layout);
}

ExtenDlg::~ExtenDlg()
{

}

void ExtenDlg::initBasicInfo()
{
    baseWidget = new QWidget;
    //创建空间
    QLabel *label_Name = new QLabel(tr("Name :"));
    QLabel *label_Sex = new QLabel(tr("Sex "));
    QLineEdit *edit_Name = new QLineEdit;
    QComboBox *ComBox_Sex = new QComboBox;
    ComBox_Sex->addItem(tr("Boy"));
    ComBox_Sex->addItem(tr("Girl"));

    QPushButton *Btn_Ok = new QPushButton(tr("Ok"));
    QPushButton *Btn_Detail = new QPushButton(tr("Detail"));
    //建立信号槽
    connect(Btn_Detail,SIGNAL(clicked()),this,SLOT(slot2Extension()));

    QDialogButtonBox *BtnBox = new QDialogButtonBox(Qt::Horizontal);
    BtnBox->addButton(Btn_Ok,QDialogButtonBox::ActionRole);
    BtnBox->addButton(Btn_Detail,QDialogButtonBox::ActionRole);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(label_Name,edit_Name);
    formLayout->addRow(label_Sex,ComBox_Sex);

    QVBoxLayout *vboxLayout = new QVBoxLayout;
    vboxLayout->addLayout(formLayout);
    vboxLayout->addWidget(BtnBox);


    baseWidget->setLayout(vboxLayout);

}
void ExtenDlg::initDetailInfo()
{
    detailWidget = new QWidget;
    QLabel *label_Age = new QLabel(tr("Age: "));
    QLabel *label_dept = new QLabel(tr("Department: "));
    QLabel *label_addr = new QLabel(tr("Address: "));

    QLineEdit *edit_Age = new QLineEdit;
    QComboBox *ComBox_Dept = new QComboBox;
    ComBox_Dept->addItem(tr("DEPT"));
     ComBox_Dept->addItem(tr("DEPT2"));
    QLineEdit *edit_Addr = new QLineEdit;

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(label_Age,edit_Age);
    formLayout->addRow(label_dept,ComBox_Dept);
    formLayout->addRow(label_addr,edit_Addr);

    detailWidget->setLayout(formLayout);
    detailWidget->hide();

}

 void ExtenDlg::slot2Extension()
 {
     qDebug()<<"lai lai lai";
     if(detailWidget->isHidden())
     {
         detailWidget->show();
     }else
     {
         detailWidget->hide();
     }
 }
