#include "myaddrbook.h"
#include "ui_myaddrbook.h"

MyAddrBook::MyAddrBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAddrBook)
{
    UpdateUI(INIT);

}

MyAddrBook::~MyAddrBook()
{
    delete ui;
}

void MyAddrBook::MyAdd()
{

    //CtrlButton();
    ui->lineEditName->clear();
    ui->textEditAddr->clear();

    mode = ADD;
    UpdateUI(mode);
}
void MyAddrBook::MyEdit()
{

   // CtrlButton();
    OldName = ui->lineEditName->text();
    OldAddr = ui->textEditAddr->toPlainText();

    mode = EDIT;
    UpdateUI(mode);
}
void MyAddrBook::MyRemove()
{
    QString name = ui->lineEditName->text();
    int button = QMessageBox::question(this,
        tr("Confirm delete?"),
        tr("Are you sure you want to delete \"%1\"?").arg(name),
        QMessageBox::Yes | QMessageBox::No);


    if(button == QMessageBox::Yes)
    {
        QMap <QString, QString>::iterator i = MyMap.find(name);
        int option = MyMap.count();
        qDebug()<<"option = "<<option;

        switch(option)
        {
        case 1:

            ui->lineEditName->clear();
            ui->textEditAddr->clear();
            MyMap.empty();
            break;
        case 2:
            ui->pushButton_Previous->setEnabled(false);
            ui->pushButton_Next->setEnabled(false);
            MyMap.remove(name);
            qDebug()<<"1";
            break;
        case 3:
            ui->pushButton_Find->setEnabled(false);
            MyMap.remove(name);
            qDebug()<<"2";
            break;
        default:
             MyMap.remove(name);

        }
        MyNext();
    }else if(button == QMessageBox::No)
    {
        return ;
    }

}
void MyAddrBook::MyFind()
{
    qDebug()<<"I'm at Find";
    dialog->show();
    if(dialog->exec() == 1)
    {
        QString name = dialog->DlgFindText();
        if(MyMap.contains(name))
        {
           // qDebug()<<"you mingzi!";
              QMap <QString, QString>::iterator i = MyMap.find(name);
              ui->lineEditName->setText(i.key());
              ui->textEditAddr->setText(i.value());
        }else
        {
            QMessageBox::about(this,"Clue on","Sorry,don't Find your data");
        }
    }
}
void MyAddrBook::MySubmit()
{

    if(mode == ADD)
    {
        ui->pushButton_Submit->hide();
        ui->pushButton_Cancle->hide();
        ui->pushButton_Load->setEnabled(true);
        ui->pushButton_Add->setEnabled(true);
        ui->pushButton_Edit->setEnabled(true);
        ui->pushButton_Save->setEnabled(true);
        ui->pushButton_Export->setEnabled(true);
        ui->pushButton_Remove->setEnabled(true);
        ui->lineEditName->setReadOnly(true);
        ui->textEditAddr->setReadOnly(true);

        QString Name = ui->lineEditName->text();
        QString Addr = ui->textEditAddr->toPlainText();

        if(Name == "")
        {
            MyAdd();
            ui->pushButton_Load->setEnabled(false);
            ui->pushButton_Save->setEnabled(false);
            ui->pushButton_Export->setEnabled(false);
            ui->pushButton_Remove->setEnabled(false);
            ui->pushButton_Edit->setEnabled(false);
            QMessageBox::about(this,"Clue on",tr("you forget write message!"));
            return ;
        }


        if(MyMap.contains(Name))
        {
            MyAdd();
            QMessageBox::about(this,"Clue on","The data is exist!");
            return ;
        }
        if(MyMap.count() > 0)
        {
            ui->pushButton_Previous->setEnabled(true);
            ui->pushButton_Next->setEnabled(true);
        }
        if(MyMap.count() > 1)
        {
            ui->pushButton_Find->setEnabled(true);
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

            QString  Name = ui->lineEditName->text();
            QString Addr = ui->textEditAddr->toPlainText();
            MyMap.insert(Name,Addr);

            QMessageBox::about(this,"Clue on",tr("modify success!"));

            ui->pushButton_Submit->hide();
            ui->pushButton_Cancle->hide();
            ui->pushButton_Load->setEnabled(true);
            ui->pushButton_Add->setEnabled(true);
            ui->pushButton_Edit->setEnabled(true);
            ui->pushButton_Find->setEnabled(true);
            ui->pushButton_Remove->setEnabled(true);
            ui->lineEditName->setReadOnly(true);
            ui->textEditAddr->setReadOnly(true);
            if(MyMap.count()> 0)
            {
                ui->pushButton_Previous->setEnabled(true);
                ui->pushButton_Next->setEnabled(true);
            }
        }else if(QMessageBox::No == button)
        {
            return ;
        }

    }



}
void MyAddrBook::MyCancle()
{
    mode = CANCLE;
    UpdateUI(mode);

}
void MyAddrBook::MyLoad()
{
  //  qDebug()<<"I'm at Load";
    QString filename = QFileDialog::getOpenFileName(this,tr("Load my addrbook"),"",
                                                   tr("Address Book(*.abk) ;; All file(*)"));
    if(filename.isEmpty())
    {
        QMessageBox::about(this,"clue on","File name is not empty!");
        return ;
    }else
    {
        QFile file(filename);

        if( !file.open(QIODevice::ReadOnly) )
        {
            QMessageBox::about(this,"Clue on","Open the file failure!");
            return ;
        }else
        {
            QDataStream in(&file);
            in.setVersion(QDataStream::Qt_4_3);
            MyMap.empty();
            in>>MyMap;

            QMap<QString,QString>::iterator i = MyMap.begin();
            ui->lineEditName->setText(i.key());
            ui->textEditAddr->setText(i.value());
            if(MyMap.count() > 0)
            {
                ui->pushButton_Previous->setEnabled(true);
                ui->pushButton_Next->setEnabled(true);
                ui->pushButton_Find->setEnabled(true);
                ui->pushButton_Edit->setEnabled(true);
                ui->pushButton_Remove->setEnabled(true);
                ui->pushButton_Save->setEnabled(true);
            }
        }
    }
 }
void MyAddrBook::MySave()
{
   // qDebug()<<"I'm at Save";
    QString filename = QFileDialog::getSaveFileName(this,tr("Save My addrbook"),"",
                                                        tr("Address Book(*.abk) ;; All File(*) "));
    if(filename.isEmpty())
        return ;
    else
    {
        QFile file(filename);

        if( !file.open(QIODevice::WriteOnly) )
        {
            QMessageBox::about(this,"Clue on","Open the file failure!");
            return ;
        }else
        {
            QDataStream out(&file);
            out.setVersion(QDataStream::Qt_4_3);
            out<<MyMap;
            QMessageBox::about(this,"Clue on","Save Success!");
        }

    }
}
void MyAddrBook::MyExport()
{
   // qDebug()<<"I'm at Export";
    QString name = ui->lineEditName->text();
    QString addr = ui->textEditAddr->toPlainText();

    QString firstName;
    QString lastName;

    QStringList nameList;
    int index = name.indexOf(" ");
    if(index != -1)
    {
        nameList = name.split(QRegExp("\\s+"),QString::SkipEmptyParts);
        firstName = nameList.first();
        lastName = nameList.last();
    }else
    {
        firstName = name;
        lastName = "";
    }
    QString fileName = QFileDialog::getSaveFileName(this,tr("Export file"),"",
                                                    tr("Address Book(*.abk) ; ; ALll file(*)"));
    if(fileName.isEmpty())
        return ;
    QFile file(fileName);
    if( !file.open(QIODevice::WriteOnly) )
    {
        QMessageBox::about(this,"Clue on","open file failure!");
        return ;
    }
    QTextStream out(&file);

    //输出到file
    out << "BEGIN:VCARD" << "\n";
    out << "VERSION:2.1" << "\n";
    out << "N:" << lastName << ";" << firstName << "\n";

    if (!nameList.isEmpty())
       out << "FN:" << nameList.join(" ") << "\n";
    else
       out << "FN:" << firstName << "\n";

    addr.replace(";", "\\;", Qt::CaseInsensitive);
    addr.replace("\n", ";", Qt::CaseInsensitive);
    addr.replace(",", " ", Qt::CaseInsensitive);

    out << "ADR;HOME:;" << addr<< "\n";
    out << "END:VCARD" << "\n";

    QMessageBox::information(this, tr("Export Successful"),
        tr("\"%1\" has been exported as a vCard.").arg(name));


}

void MyAddrBook::MyPrevious()
{

   qDebug()<<"I'm at Previous";
    QString name = ui->lineEditName->text();
    QMap <QString, QString>::iterator i = MyMap.find(name);

    if(i == MyMap.end())
    {
        ui->lineEditName->clear();
        ui->textEditAddr->clear();
        return  ;
    }
    if(i == MyMap.begin())
        i = MyMap.end();
    i--;
    ui->lineEditName->setText(i.key());
    ui->textEditAddr->setText(i.value());
}
void MyAddrBook::MyNext()
{
    //qDebug()<<"I'm at Next";
    QString name = ui->lineEditName->text();
    QMap <QString, QString>::iterator i = MyMap.find(name);

    if(i != MyMap.end())
        i++;
    if(i == MyMap.end())
        i = MyMap.begin();

    ui->lineEditName->setText(i.key());
    ui->textEditAddr->setText(i.value());
}

void MyAddrBook::CtrlButton()
{
    ui->pushButton_Load->setEnabled(false);
    ui->pushButton_Add->setEnabled(false);
    ui->pushButton_Submit->setVisible(true);
    ui->pushButton_Cancle->setVisible(true);
    ui->pushButton_Edit->setEnabled(false);
    ui->pushButton_Export->setEnabled(false);
    ui->pushButton_Remove->setEnabled(false);
    ui->pushButton_Save->setEnabled(false);
    ui->pushButton_Find->setEnabled(false);
    ui->pushButton_Previous->setEnabled(false);
    ui->pushButton_Next->setEnabled(false);

    ui->lineEditName->setReadOnly(false);
    ui->textEditAddr->setReadOnly(false);
}

void MyAddrBook::UpdateUI(MODE mode)
{
    if(mode == INIT)
    {
        ui->setupUi(this);
        ui->gridLayout->setMargin(11);
        this->setLayout(ui->gridLayout);//设置随大小改变而改变

        ui->pushButton_Edit->setEnabled(false);
        ui->pushButton_Remove->setEnabled(false);
        ui->pushButton_Find->setEnabled(false);
        ui->pushButton_Save->setEnabled(false);
        ui->pushButton_Export->setEnabled(false);
        ui->pushButton_Previous->setEnabled(false);
        ui->pushButton_Next->setEnabled(false);

        ui->pushButton_Submit->setVisible(false);
        ui->pushButton_Cancle->setVisible(false);

        ui->lineEditName->setReadOnly(true);
        ui->textEditAddr->setReadOnly(true);

        dialog = new finddialog(this);
    }else if(mode == ADD)
    {
        ui->pushButton_Load->setEnabled(false);
        ui->pushButton_Add->setEnabled(false);
        ui->pushButton_Submit->setVisible(true);
        ui->pushButton_Cancle->setVisible(true);
        ui->pushButton_Edit->setEnabled(false);
        ui->pushButton_Export->setEnabled(false);
        ui->pushButton_Remove->setEnabled(false);
        ui->pushButton_Save->setEnabled(false);
        ui->pushButton_Find->setEnabled(false);
        ui->pushButton_Previous->setEnabled(false);
        ui->pushButton_Next->setEnabled(false);

        ui->lineEditName->setReadOnly(false);
        ui->textEditAddr->setReadOnly(false);
    }else if(mode == EDIT)
    {
        ui->pushButton_Load->setEnabled(false);
        ui->pushButton_Add->setEnabled(false);
        ui->pushButton_Submit->setVisible(true);
        ui->pushButton_Cancle->setVisible(true);
        ui->pushButton_Edit->setEnabled(false);
        ui->pushButton_Export->setEnabled(false);
        ui->pushButton_Remove->setEnabled(false);
        ui->pushButton_Save->setEnabled(false);
        ui->pushButton_Find->setEnabled(false);
        ui->pushButton_Previous->setEnabled(false);
        ui->pushButton_Next->setEnabled(false);

        ui->lineEditName->setReadOnly(false);
        ui->textEditAddr->setReadOnly(false);

    }else if(mode == CANCLE)
    {
        ui->lineEditName->setReadOnly(true);
        ui->textEditAddr->setReadOnly(true);

        ui->pushButton_Add->setEnabled(true);
        ui->pushButton_Load->setEnabled(true);

        ui->pushButton_Submit->setVisible(false);
        ui->pushButton_Cancle->setVisible(false);
        int  n=  MyMap.count();
        qDebug()<<n<<"sdf";
        switch(n)
        {
        case 0:
            ui->lineEditName->clear();
            ui->textEditAddr->clear();
            break;
        case 1:
        {
            QMap<QString,QString>::iterator i = MyMap.begin();
            ui->lineEditName->setText(i.key());
            ui->textEditAddr->setText(i.value());
            ui->pushButton_Edit->setEnabled(true);
        }
            break;
        default:
        {
            QMap<QString,QString>::iterator i = MyMap.begin();
            ui->lineEditName->setText(i.key());
            ui->textEditAddr->setText(i.value());
            ui->pushButton_Edit->setEnabled(true);
            ui->pushButton_Previous->setEnabled(true);
            ui->pushButton_Next->setEnabled(true);
        }

        }
     /*   if(MyMap.count() > 0)
        {
            QMap<QString,QString>::iterator i = MyMap.begin();
            ui->lineEditName->setText(i.key());
            ui->textEditAddr->setText(i.value());
            ui->pushButton_Edit->setEnabled(true);
        }
        if(MyMap.count() > 1)
        {
            ui->pushButton_Previous->setEnabled(true);
            ui->pushButton_Next->setEnabled(true);
        }*/

    }
}
