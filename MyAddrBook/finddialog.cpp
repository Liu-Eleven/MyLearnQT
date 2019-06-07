#include "finddialog.h"

finddialog::finddialog( QWidget * parent, Qt::WindowFlags f) :
    QDialog(parent)
{
   QHBoxLayout *layout = new QHBoxLayout;
   label = new QLabel(tr("enter your name:"));
   value = new QLineEdit;
   Btn = new QPushButton(tr("&Find"));

   layout->addWidget(label);
   layout->addWidget(value);
   layout->addWidget(Btn);

   setLayout(layout);
   setWindowTitle("find name");

   connect(Btn, SIGNAL(clicked()), this, SLOT(findclick()));
   connect(Btn, SIGNAL(clicked()), this, SLOT(accept()));
 // qDebug()<<"find text"<<FindText;
}

 void finddialog::findclick()
 {
     QString text = value->text();
     FindText = text;
  //  qDebug()<<"find text"<<FindText;
 }

QString  &finddialog::DlgFindText()
{
  //   QString FindText =  value->text();
    // qDebug()<<">>>>>>>"<<FindText;
    return FindText;
}
