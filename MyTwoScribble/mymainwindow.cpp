#include "mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(330,310);
  //  setMinimumSize(330,310);
  //  setMaximumSize(330,310);
    //设置画板
    setCentralWidget(&scribble);

    menubar = new QMenuBar;
    //创建菜单
    CreateMenu();
    setMenuBar(menubar);
    setWindowTitle("Love Scribble");


}

MyMainWindow::~MyMainWindow()
{

}

void MyMainWindow::CreateMenu()
{
    //文件菜单
    FileMenu = new QMenu(tr("&File "), this);
    OpenAct = new QAction(tr("&Open..."),this);
    OpenAct->setShortcuts(QKeySequence::Open);
    connect(OpenAct,SIGNAL(triggered()),this,SLOT(OpenFile()));

    SaveAct = new QAction(tr("&Save"), this);
    connect(SaveAct,SIGNAL(triggered()),this,SLOT(Save()));

    AddActionToSave();
    PrintAct = new QAction(tr("&Print..."),this);

    ExitAct = new QAction(tr("E&xit"),this);
    connect(ExitAct,SIGNAL(triggered()),this,SLOT(close()));

    FileMenu->addAction(OpenAct);
    FileMenu->addAction(SaveAct);
    FileMenu->addMenu(SaveMenu);
    FileMenu->addAction(PrintAct);
    FileMenu->addSeparator();
    FileMenu->addAction(ExitAct);

    //选项菜单
    OptionMenu = new QMenu(tr("Options "), this);
    ColorAct = new QAction(tr("&Pen Color..."), this);
    connect(ColorAct,SIGNAL(triggered()),this,SLOT(SetPenColor()));
    ColorWidth = new QAction(tr("&Pen width..."),this);
    connect(ColorWidth,SIGNAL(triggered()),this,SLOT(SetPenWidth()));
    ClearScrAct = new QAction(tr("&Clear Screen"),this);
    connect(ClearScrAct,SIGNAL(triggered()),this,SLOT(clearScreen()));

    OptionMenu->addAction(ColorAct);
    OptionMenu->addAction(ColorWidth);
    OptionMenu->addSeparator();
    OptionMenu->addAction(ClearScrAct);

    //帮助菜单
    HelpMenu = new QMenu(tr("Help ") , this);
    AboutAct = new QAction(tr("&About.."),this);
    AboutQtAct = new QAction(tr("&About Qt"),this);

    HelpMenu->addAction(AboutAct);
    HelpMenu->addAction(AboutQtAct);


    menubar->addMenu(FileMenu);
    menubar->addMenu(OptionMenu);
    menubar->addMenu(HelpMenu);
}

void MyMainWindow::AddActionToSave()
{
    SaveMenu = new QMenu(tr("&Save as") , this);

    QList <QByteArray> AllFormat = QImageWriter::supportedImageFormats ();
//遍历所有图片格式
    foreach(QByteArray tmp,AllFormat)
    {
        QString StrFormat = QString(tmp.toUpper());
        QAction *action = new QAction(tr("%1...").arg(StrFormat),this);
        //设置action内置数据
        action->setData(tmp);

        connect(action,SIGNAL(triggered()),this,SLOT(SaveAs()));
        SaveMenu->addAction(action);
    }
}

void MyMainWindow::Save()
{
    qDebug()<<"I'm in Save";
    scribble.SaveImage(SourcePath);

}

void MyMainWindow::SaveAs()
{
    qDebug()<<"I'm in saveas";
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    if( SaveFile(fileFormat) )
    {
        QMessageBox::about(this,"Clue on","Save as success!");
    }
}

bool MyMainWindow::SaveFile(QByteArray &format)
{
    QString title = "untitle."+format;
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save as"),""+title,
                                                    tr("%1 Files (*.%2);;All Files(*)")
                                                    .arg(QString(format)).arg(QString(format)));//)
    if(fileName.isEmpty())
        return false;
    else
        return scribble.SaveAsImage(fileName,format);

}

bool MyMainWindow::OpenFile()
{

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"",
                                                    tr("All Image(*)"));
    if( fileName.isEmpty() )
        return false;
    if(scribble.OpenImage(fileName) == false)
    {
        QMessageBox::about(this,"Clue on","Open Picture failure!");
    }
    SourcePath = fileName;
    return true;
}

int  MyMainWindow::SetPenColor()
{
    QColor color = QColorDialog::getColor();
    scribble.SetPenColor(color);
    return 0;
}
int  MyMainWindow::SetPenWidth()
{
    //qDebug()<<"test";
    bool ok;
    int newWidth = QInputDialog::getInteger(this, tr("Input pen width"),
                                            tr("Pen width:"),
                                            0,1, 61, 1, &ok);//第二个参数是设置初始直，
                                                             //第三个参数是设置最大值
                                                             //第四个参数是设置跳过值
   // qDebug()<<newWidth;
    if(ok)
        scribble.SetPenWidth(newWidth);
    return 0;
}
void MyMainWindow::clearScreen()
{
    qDebug()<<"clear screen";
    scribble.ClearMyScreen();
}

//窗口关闭事件
void MyMainWindow::closeEvent ( QCloseEvent * event )
{
    int button ;
    if(scribble.modify)
    {
        button = QMessageBox::question(this,tr("Save image"),
                                       tr("The image is modify,do you want save?"),
                                       QMessageBox::Yes | QMessageBox::No);
    }
    if (button == QMessageBox::Yes)
    {
       event->ignore();
    }

}

