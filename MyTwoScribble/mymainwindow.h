#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QtGui/QMainWindow>
#include "myscribble.h"

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

protected:
    void closeEvent ( QCloseEvent * event );

private slots:
    void Save();
    void SaveAs();
    bool OpenFile();
    int SetPenColor();
    int SetPenWidth();
    void clearScreen();

private:
    QMenuBar *menubar;
    QMenu *FileMenu;
    QAction *OpenAct;
    QAction *SaveAct;
    QMenu *SaveMenu;
    QAction *PrintAct;
    QAction *ExitAct;


    QMenu *OptionMenu;
    QAction *ColorAct;
    QAction *ColorWidth;
    QAction *ClearScrAct;


    QMenu *HelpMenu;
    QAction *AboutAct;
    QAction *AboutQtAct;

    MyScribble scribble;

    QString SourcePath;

    void CreateMenu();//创建菜单
    void AddActionToSave();//为另存为添加事件
    bool SaveFile(QByteArray &);
};

#endif // MYMAINWINDOW_H
