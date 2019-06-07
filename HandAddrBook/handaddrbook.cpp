#include "handaddrbook.h"

HandAddrBook::HandAddrBook(QWidget *parent)
    : QWidget(parent)
{
    initializationUi();
    setMinimumHeight(350);
    setMinimumWidth(400);

    setMaximumWidth(400);
    setMaximumHeight(350);

    dialog = new findDialog(this);
}

HandAddrBook::~HandAddrBook()
{

}
//初始化界面
 void HandAddrBook::initializationUi()
 {
     QLabel *label_Name = new QLabel(tr("Name:"));
     QLabel *label_Addr = new QLabel(tr("Address:"));

     edit_Name = new QLineEdit;
     text_Address = new QTextEdit;
     M_Layout = new QGridLayout;

     M_Layout->addWidget(label_Name,0,0);
     M_Layout->addWidget(edit_Name,0,1);
     M_Layout->addWidget(label_Addr,1,0,Qt::AlignTop);
     M_Layout->addWidget(text_Address,1,1);

     QString str[11]={"&Add","&Edit","&Remove","&Find","&Submit","&Cancel","&Load...","&Save...","E&xport...","&Previous","&Next"};
     v_Layout = new QVBoxLayout;//垂直布局管理器
     h_Layout = new QHBoxLayout;//水平布局管理器
     int i;
     for(i=0;i<11;i++)
     {
         if(i <= 8)
         {
            button[i] = new QPushButton;
            button[i]->setText(str[i]);
            v_Layout->addWidget(button[i]);
         }else
         {
             button[i] = new QPushButton;
             button[i]->setText(str[i]);
             h_Layout->addWidget(button[i]);
         }

     }
     v_Layout->addStretch();//添加弹簧

     M_Layout->addLayout(v_Layout,1,2);
     M_Layout->addLayout(h_Layout,2,1);
     setLayout(M_Layout);

     //注册信号
     connect(button[0],SIGNAL(clicked()),this,SLOT(AddData()));
     connect(button[1],SIGNAL(clicked()),this,SLOT(EditData()));
     connect(button[2],SIGNAL(clicked()),this,SLOT(RemoveData()));
     connect(button[3],SIGNAL(clicked()),this,SLOT(FindData()));
     connect(button[4],SIGNAL(clicked()),this,SLOT(SubmitData()));
     connect(button[5],SIGNAL(clicked()),this,SLOT(CancelData()));
     connect(button[6],SIGNAL(clicked()),this,SLOT(LoadData()));
     connect(button[7],SIGNAL(clicked()),this,SLOT(SaveData()));
     connect(button[8],SIGNAL(clicked()),this,SLOT(ExportData()));
     connect(button[9],SIGNAL(clicked()),this,SLOT(PreviousData()));
     connect(button[10],SIGNAL(clicked()),this,SLOT(NextData()));
     int j= 0;
     for(j=1; j<11 ;j++)
     {
         if(j != 6)
         {
             button[j]->setEnabled(false);
         }
     }

     button[4]->setVisible(false);
     button[5]->setVisible(false);
     edit_Name->setReadOnly(true);
     text_Address->setReadOnly(true);
 }
//更新界面
 void HandAddrBook::UpdateUI(MODE mode)
 {
     if(mode == ADD)
     {
         int i;
         for(i=0;i<11;i++)
         {
             if(i != 4 && i != 5)
             {
                 button[i]->setEnabled(false);
             }else
             {
                  button[i]->setVisible(true);
                  button[i]->setEnabled(true);
             }
         }
     }else if(mode == EDIT)
     {

         int i;
         for(i=0;i<11;i++)
         {
             if(i != 4 && i != 5)
             {
                 button[i]->setEnabled(false);
             }else
             {
                 button[i]->setVisible(true);
                 button[i]->setEnabled(true);
             }
         }
         edit_Name->setReadOnly(false);
         text_Address->setReadOnly(false);
     }else if(mode == CANCEL)
     {
         edit_Name->setReadOnly(true);
         text_Address->setReadOnly(true);

         button[0]->setEnabled(true);
         button[6]->setEnabled(true);

         button[4]->setVisible(false);
         button[5]->setVisible(false);
         int  n=  MyMap.count();
         switch(n)
         {
         case 0:
             edit_Name->clear();
             text_Address->clear();
               break;
         case 1:
                {
                    QMap<QString,QString>::iterator i = MyMap.begin();
                    edit_Name->setText(i.key());
                    text_Address->setText(i.value());
                    button[1]->setEnabled(true);//有一个元素，编辑按钮激活
                    button[2]->setEnabled(true);//删除按钮激活
                    button[7]->setEnabled(true);//保存按钮激活
                    button[8]->setEnabled(true);//导出按钮激活
                }
                break;
          default:
                {
                    QMap<QString,QString>::iterator i = MyMap.begin();
                    edit_Name->setText(i.key());
                    text_Address->setText(i.value());
                    button[1]->setEnabled(true);//有两个以上元素，编辑按钮激活
                    button[2]->setEnabled(true);//删除按钮激活
                    button[3]->setEnabled(true);//查找按钮激活
                    button[7]->setEnabled(true);//保存按钮激活
                    button[8]->setEnabled(true);//导出按钮激活
                    button[9]->setEnabled(true);//向前按钮激活
                    button[10]->setEnabled(true);//向后按钮激活
                }

          }
     }
 }
//添加一条数据
 void HandAddrBook::AddData()
 {
     qDebug()<<"I'm in add";
     mode = ADD;
     edit_Name->setReadOnly(false);
     text_Address->setReadOnly(false);
     edit_Name->clear();
     text_Address->clear();
     UpdateUI(mode);
 }

 //修改一条数据
 void HandAddrBook::EditData()
 {
     mode = EDIT;

     OldName = edit_Name->text();
     OldAddr = text_Address->toPlainText();
     UpdateUI(mode);
    // qDebug()<<"I'm in edit";
 }

 //删除一条数据
 void HandAddrBook::RemoveData()
 {
     //qDebug()<<"I'm in remove";
     QString name = edit_Name->text();
     int button = QMessageBox::question(this,
             tr("Confirm delete?"),
             tr("Are you sure you want to delete \"%1\"?").arg(name),
             QMessageBox::Yes | QMessageBox::No);


         if(button == QMessageBox::Yes)
         {
           //  QMap <QString, QString>::iterator i = MyMap.find(name);
             DeleteDate(name);

         }else if(button == QMessageBox::No)
         {
             return ;
         }
 }

 //查找一条数据
 void HandAddrBook::FindData()
 {
  //   qDebug()<<"I'm in find";
     dialog->show();
     if(dialog->exec() == 1)
     {
         QString name = dialog->DlgFindText();
         if(MyMap.contains(name))
         {
            // qDebug()<<"you mingzi!";
               QMap <QString, QString>::iterator i = MyMap.find(name);
               edit_Name->setText(i.key());
               text_Address->setText(i.value());
         }else
         {
             QMessageBox::about(this,"Clue on","Sorry,don't Find your data");
         }
     }
 }

 //提交添加数据
 void HandAddrBook::SubmitData()
 {
     //qDebug()<<"I'm in submit";
     if(mode == ADD)
      {
          QString Name = edit_Name->text();
          QString Addr = text_Address->toPlainText();
          button[0]->setEnabled(true);
          button[1]->setEnabled(true);
          button[2]->setEnabled(true);
          button[4]->hide();
          button[5]->hide();
          button[6]->setEnabled(true);
          button[7]->setEnabled(true);
          button[8]->setEnabled(true);
          edit_Name->setReadOnly(true);
          text_Address->setReadOnly(true);
          if(Name == "")
          {
              AddData();
              QMessageBox::about(this,"Clue on",tr("you forget write message!"));
              return ;
          }
          if(MyMap.contains(Name))
          {
              AddData();
              QMessageBox::about(this,"Clue on","The data is exist!");
              return ;
          }
          if(MyMap.count() > 0)
          {
              button[9]->setEnabled(true);//前一个
              button[10]->setEnabled(true);//后一个
          }
          if(MyMap.count() > 1)
          {
              button[3]->setEnabled(true);//查找
          }

          MyMap.insert(Name,Addr);
          QMessageBox::about(this,"Clue on","add data success");
      }else if(mode == EDIT)
      {
          int button = QMessageBox::question(this,
              tr("Confirm modify?"),
              tr("Are you sure you want to modify \"%1\"?").arg(OldName),
              QMessageBox::Yes | QMessageBox::No);

          if(QMessageBox::Yes == button)
          {
              QMap <QString, QString>::iterator i = MyMap.find(OldName);
              MyMap.remove(OldName);

              QString  Name = edit_Name->text();
              QString Addr = text_Address->toPlainText();
              MyMap.insert(Name,Addr);
              QMessageBox::about(this,"Clue on",tr("modify success!"));
              CancleStat();
          }else if(QMessageBox::No == button)
          {
              return ;
          }

      }
 }
 //取消本次操作
 void HandAddrBook::CancelData()
 {
     //qDebug()<<"I'm in cancel";
     mode = CANCEL;
     UpdateUI(mode);
 }

 //载入现有文件
 void HandAddrBook::LoadData()
 {
   //  qDebug()<<"I'm in load";
     QString fileName = QFileDialog::getOpenFileName(this,tr("Save My address book"),"",
                                                     tr("Address Book(*.abk) ;; All File(*)"));
     if(fileName.isEmpty())
         return ;
     else
     {
         QFile file(fileName);
         if( !file.open(QIODevice::ReadOnly) )
         {
             QMessageBox::about(this,tr("Clue on"),tr("open the file failure~!"));
                     return ;
         }else
         {
             QDataStream in(&file);
             in.setVersion(QDataStream::Qt_4_3);
             MyMap.empty();
             in>>MyMap;
             QMap<QString,QString>::iterator i = MyMap.begin();
              edit_Name->setText(i.key());
              text_Address->setText(i.value());
              int n = MyMap.count();
              switch(n)
              {
              case 1:
                  button[0]->setEnabled(true);//添加按钮激活
                  button[1]->setEnabled(true);//编辑按钮激活
                  button[2]->setEnabled(true);//删除按钮激活
                  button[7]->setEnabled(true);//保存按钮激活
                  button[8]->setEnabled(true);//导出按钮激活
                  break;
              default:
                  button[0]->setEnabled(true);//添加按钮激活
                  button[1]->setEnabled(true);//编辑按钮激活
                  button[2]->setEnabled(true);//删除按钮激活
                  button[3]->setEnabled(true);//查找按钮激活
                  button[7]->setEnabled(true);//保存按钮激活
                  button[8]->setEnabled(true);//导出按钮激活
                  button[9]->setEnabled(true);//向前按钮激活
                  button[10]->setEnabled(true);//向后按钮激活
              }
            if(MyMap.count() > 0)
              {
                //如果有数据

              }
             QMessageBox::about(this,tr("Clue on"),tr("save sucess!"));
         }
     }
 }
 //保存为文本
 void HandAddrBook::SaveData()
 {
     //qDebug()<<"I'm in save";
     QString fileName = QFileDialog::getSaveFileName(this,tr("Save My address book"),"",
                                                     tr("Address Book(*.abk) ; ; All File(*)"));
     if(fileName.isEmpty())
         return ;
     else
     {
         QFile file(fileName);
         if( !file.open(QIODevice::WriteOnly) )
         {
             QMessageBox::about(this,tr("Clue on"),tr("open the file failure~!"));
                     return ;
         }else
         {
             QDataStream out(&file);
             out.setVersion(QDataStream::Qt_4_3);
             out<<MyMap;
             QMessageBox::about(this,tr("Clue on"),tr("save sucess!"));
         }
     }
 }
 //导出名片
 void HandAddrBook::ExportData()
 {
   //  qDebug()<<"I'm in export";
     QString name = edit_Name->text();
     QString addr  = text_Address->toPlainText();

     QString firstName;
     QString lastName;

     QStringList nameList;
     int index = name.indexOf(" ");//查找空格第一次出现的位置,如果没有空格返回-1
     if( index != -1)
     {
         nameList = name.split(QRegExp("\\s+"),QString::SkipEmptyParts);

         firstName = nameList.first();
         lastName = nameList.last();
     }else
     {
         firstName = name;
         lastName = "";
     }

     QString fileName = QFileDialog::getSaveFileName(this,tr("Export local file"),"",
                                                     tr("Address Book(*.vcf) ; ; All file(*)"));
     if(fileName.isEmpty())
         return ;
     else
     {
         QFile file(fileName);
         if( !file.open(QFile::WriteOnly) )
         {
             QMessageBox::about(this,"Clue on","open file failure!");
             return ;
         }else
         {
             QTextStream out(&file);

             out<<"BEGIN VCARD"<<"\n";
             out<<"VERSION 2.1"<<"\n";

             out<<"FAMILY NAME: "<<firstName<< " ; "<<"NAME: "<<lastName<<"\n";

             if( !nameList.isEmpty() )
                 out<<"All NAME: "<<nameList.join(" ")<<"\n";
             else
                 out<<"FAMILY NAME"<<firstName<<"\n";

             addr.replace(";","\\",Qt::CaseInsensitive);
             addr.replace("\n",";",Qt::CaseInsensitive);
             addr.replace(","," ",Qt::CaseInsensitive);

             out<<"ADR; HOME: ;"<<addr<<"\n";
             out<<"END : VCARD "<<"\n";
             QMessageBox::information(this, tr("Export Successful"),
                     tr("\"%1\" has been exported as a vCard.").arg(name));
         }
     }



 }

 //查看上一项
 void HandAddrBook::PreviousData()
 {
    // qDebug()<<"I'm in previous";
      QString name = edit_Name->text();
      QMap <QString, QString>::iterator i = MyMap.find(name);

      if(i == MyMap.end())
      {
          edit_Name->clear();
          text_Address->clear();
          return  ;
      }
      if(i == MyMap.begin())
          i = MyMap.end();
      i--;
      edit_Name->setText(i.key());
      text_Address->setText(i.value());
 }
 //查看下一项
 void HandAddrBook::NextData()
 {
     //qDebug()<<"I'm in next";
     QString name = edit_Name->text();
     QMap <QString, QString>::iterator i = MyMap.find(name);

        if( i != MyMap.end())
            i++;
        if(i == MyMap.end())
            i = MyMap.begin();

        edit_Name->setText(i.key());
        text_Address->setText(i.value());
 }
//取消后回复状态
  void HandAddrBook::CancleStat()
  {
      //以下是更改控件的状态
      button[4]->setVisible(false);
      button[5]->setVisible(false);
      button[0]->setEnabled(true);
      button[6]->setEnabled(true);
      int  n=  MyMap.count();
      switch(n)
      {
      case 0:
          edit_Name->clear();
          text_Address->clear();
            break;
      case 1:
             {
                 QMap<QString,QString>::iterator i = MyMap.begin();
                 edit_Name->setText(i.key());
                 text_Address->setText(i.value());
                 button[1]->setEnabled(true);//有一个元素，编辑按钮激活
                 button[2]->setEnabled(true);//删除按钮激活
                 button[7]->setEnabled(true);//保存按钮激活
                 button[8]->setEnabled(true);//导出按钮激活
             }
             break;
       default:
             {
                 QMap<QString,QString>::iterator i = MyMap.begin();
                 edit_Name->setText(i.key());
                 text_Address->setText(i.value());
                button[1]->setEnabled(true);//有两个以上元素，编辑按钮激活
                 button[2]->setEnabled(true);//删除按钮激活
                 button[3]->setEnabled(true);//查找按钮激活
                 button[7]->setEnabled(true);//保存按钮激活
                 button[8]->setEnabled(true);//导出按钮激活
                 button[9]->setEnabled(true);//向前按钮激活
                 button[10]->setEnabled(true);//向后按钮激活
             }

       }
  }
//删除后回复状态
  void HandAddrBook::DeleteDate(QString name)
  {
      int option = MyMap.count();
      qDebug()<<"option = "<<option;

      switch(option)
      {
      case 1:
          edit_Name->clear();
          text_Address->clear();
          MyMap.empty();
          break;
      case 2:
          button[9]->setEnabled(false);//如果有两条记录，激活向前按钮
          button[10]->setEnabled(false);//向后按钮激活
          MyMap.remove(name);
          qDebug()<<"1";
          break;
      case 3:
          button[3]->setEnabled(false);//查找按钮激活
          MyMap.remove(name);
          qDebug()<<"2";
          break;
      default:
           MyMap.remove(name);
     }
      NextData();
  }
