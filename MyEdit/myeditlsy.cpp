#include "myeditlsy.h"
#include "ui_myeditlsy.h"

MyEditLSY::MyEditLSY(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyEditLSY)
{
    ui->setupUi(this);
    flagEdit = false;
    ReadSetting();//读取窗口位置

    //设置编辑域位于窗体中央
    setCentralWidget(ui->textEdit);

    SetCurrentFileName("");

    //灰显剪切和粘贴按钮
    ui->action_Cut->setEnabled(false);
    ui->action_Copy->setEnabled(false);

    connect(ui->textEdit->document(), SIGNAL(contentsChanged()),this, SLOT(DocumentChanged()));
    //创建状态栏提示
    ui->action_New->setStatusTip(tr("Create new file"));
    ui->action_Open->setStatusTip(tr("Open an existing file"));
    ui->action_Save->setStatusTip(tr("Save the document to disk"));
    ui->action_Cut->setStatusTip(tr("Cut current the selection's contents to the clipboard"));
    ui->action_Copy->setStatusTip(tr("Copy the current selection's contents to the clipboard"));
    ui->action_Past->setStatusTip(tr("Paste the clipboard's contents into the current selection"));

}

MyEditLSY::~MyEditLSY()
{
    delete ui;
}
//退出程序
void MyEditLSY::on_action_Exit_triggered()
{
    //qDebug()<<"exit the process";
    flagEdit =  ui->textEdit->document()->isModified();
    //int modify=11;
    QMessageBox::StandardButton ret;

    if(flagEdit)
    {
       /* modify = QMessageBox::question(this,tr("Save text"),
                                       tr("The text is modify,do you want save?"),
                                       QMessageBox::Yes | QMessageBox::No);*/

        ret = QMessageBox::warning(this,tr("Application"),
                                   tr("The document has been modified.\n"
                                      "Dou you want to save you changes?"),
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    }
    if(ret == QMessageBox::Save || ret == QMessageBox::Cancel)
    {
        return ;
    }
    WriteSetting();//写入位置记录
    exit(0);
}
//创建一个新文件
void MyEditLSY::on_action_New_triggered()
{
    QMessageBox::StandardButton ret;
    flagEdit = ui->textEdit->document()->isModified();
    if(flagEdit)
    {
        ret = QMessageBox::warning(this,tr("Clue on"),
                                   tr("Old file already changed,Do you want save?"),
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if(ret == QMessageBox::Save)
        {
            on_action_Save_triggered();//调用保存函数
        }else if( ret == QMessageBox::Cancel )
        {
            return;
        }
    }
    ui->textEdit->clear();
    SetCurrentFileName("");
}
//打开一个文件
void MyEditLSY::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),"",
                                                    tr("Text file(*.txt) ;; All file(*)"));
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,tr("Clue on"),tr("Open file failure!"));
        return ;
    }else
    {
        //qDebug()<<"open sucess!";
        QFile file(fileName);
        if( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            QMessageBox::about(this,tr("Clue on"),tr("Read file failure!"));
            return ;
        }
        QTextStream in(&file);
        QString textData;
        textData = in.readAll();//读入数据流
        ui->textEdit->setText(textData);
        file.close();
        SourceName = fileName;//这句不写，影响到文件的保存
        SetCurrentFileName(fileName);
    }


}
//实现文本另存为。。。
void MyEditLSY::on_action_Save_As_triggered()
{
    QString initPath = QDir::currentPath() + "/untitled.txt";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save file"),initPath,
                                                    tr("Text file(*.txt);;All file(*)"));
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,tr("Clue on"),tr("Save file failure!"));
        return ;
    }else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(this,tr("Clue on"),tr("Write file failure!"));
            return;
        }
        QTextStream out(&file);
        out<< ui->textEdit->toPlainText();//写出数据流
        file.close();
        //ui->textEdit->document()->setModified(false);
        SetCurrentFileName(fileName);
        QMessageBox::about(this,tr("Clue on"),tr("Save success"));
    }

}
//关闭窗口事件
void MyEditLSY::closeEvent(QCloseEvent *event)
{
    //qDebug()<<"close windows";
    flagEdit =  ui->textEdit->document()->isModified();
    QMessageBox::StandardButton ret;

    if(flagEdit)
    {
        ret = QMessageBox::warning(this,tr("Application"),
                                   tr("The document has been modified.\n"
                                      "Dou you want to save you changes?"),
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    }
    if(ret == QMessageBox::Save || ret == QMessageBox::Cancel)
    {
        event->ignore();
    }
    WriteSetting();//写入位置记录

}

//实现文件保存
void MyEditLSY::on_action_Save_triggered()
{
    QFile file(SourceName);
    if( SourceName.isEmpty() )
    {
        on_action_Save_As_triggered();
        return ;
    }
    if( !file.open(QIODevice::WriteOnly) )
    {
        QMessageBox::about(this,tr("Clue on"),tr("Read file failure!"));
        return ;
    }
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();
    file.close();
   // ui->textEdit->document()->setModified(false);
    SetCurrentFileName(SourceName);
    statusBar()->showMessage(tr("Save Success"));
}

//设置当前文件名字
void MyEditLSY::SetCurrentFileName(const QString &fileName)
{
    SourceName = fileName;
     ui->textEdit->document()->setModified(false);
    setWindowModified(false);


    if( SourceName.isEmpty() )
    {
        setWindowTitle("untitled.txt[*]");
        return ;
    }
    setWindowTitle(GetFileName(SourceName)+"[*]");


}

//去除文件路径，保留文件名字
QString MyEditLSY::GetFileName(const QString &filePathName)
{
    return QFileInfo(filePathName).fileName();
}

//判断文档是否改变
void MyEditLSY::DocumentChanged()
{
    setWindowModified(ui->textEdit->document()->isModified());
}

//读取位置
void MyEditLSY::ReadSetting()
{
    QSettings settings("LSY","TEXT EDIT");

    QPoint pos = settings.value("pos",QPoint(330,310)).toPoint();
    QSize  size = settings.value("size",QSize(400,400)).toSize();

    resize(size);//调整窗体大小
    move(pos);//把窗体移动到pos位置
}
//记录位置
void MyEditLSY::WriteSetting()
{
    QSettings settings("LSY","TEXT EDIT");
    settings.setValue("pos",pos());
    settings.setValue("size",size());
}




