/********************************************************************************
** Form generated from reading UI file 'myeditlsy.ui'
**
** Created: Thu Dec 29 11:02:00 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYEDITLSY_H
#define UI_MYEDITLSY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyEditLSY
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Save_As;
    QAction *action_Exit;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Past;
    QAction *action_About;
    QAction *action_About_QT;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Option;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyEditLSY)
    {
        if (MyEditLSY->objectName().isEmpty())
            MyEditLSY->setObjectName(QString::fromUtf8("MyEditLSY"));
        MyEditLSY->resize(400, 300);
        action_New = new QAction(MyEditLSY);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon);
        action_Open = new QAction(MyEditLSY);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save = new QAction(MyEditLSY);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon2);
        action_Save_As = new QAction(MyEditLSY);
        action_Save_As->setObjectName(QString::fromUtf8("action_Save_As"));
        action_Exit = new QAction(MyEditLSY);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Cut = new QAction(MyEditLSY);
        action_Cut->setObjectName(QString::fromUtf8("action_Cut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Cut->setIcon(icon3);
        action_Copy = new QAction(MyEditLSY);
        action_Copy->setObjectName(QString::fromUtf8("action_Copy"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Copy->setIcon(icon4);
        action_Past = new QAction(MyEditLSY);
        action_Past->setObjectName(QString::fromUtf8("action_Past"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Past->setIcon(icon5);
        action_About = new QAction(MyEditLSY);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        action_About_QT = new QAction(MyEditLSY);
        action_About_QT->setObjectName(QString::fromUtf8("action_About_QT"));
        centralWidget = new QWidget(MyEditLSY);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 40, 211, 141));
        MyEditLSY->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyEditLSY);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Option = new QMenu(menuBar);
        menu_Option->setObjectName(QString::fromUtf8("menu_Option"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        MyEditLSY->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyEditLSY);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyEditLSY->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyEditLSY);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyEditLSY->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Option->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_Save_As);
        menu_File->addSeparator();
        menu_File->addAction(action_Exit);
        menu_Option->addAction(action_Cut);
        menu_Option->addAction(action_Copy);
        menu_Option->addAction(action_Past);
        menu_Help->addAction(action_About);
        menu_Help->addAction(action_About_QT);
        mainToolBar->addAction(action_New);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Cut);
        mainToolBar->addAction(action_Copy);
        mainToolBar->addAction(action_Past);

        retranslateUi(MyEditLSY);
        QObject::connect(action_Cut, SIGNAL(triggered()), textEdit, SLOT(cut()));
        QObject::connect(action_Copy, SIGNAL(triggered()), textEdit, SLOT(copy()));
        QObject::connect(action_Past, SIGNAL(triggered()), textEdit, SLOT(paste()));
        QObject::connect(textEdit, SIGNAL(copyAvailable(bool)), action_Cut, SLOT(setEnabled(bool)));
        QObject::connect(textEdit, SIGNAL(copyAvailable(bool)), action_Copy, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MyEditLSY);
    } // setupUi

    void retranslateUi(QMainWindow *MyEditLSY)
    {
        MyEditLSY->setWindowTitle(QApplication::translate("MyEditLSY", "MyEditLSY", 0, QApplication::UnicodeUTF8));
        action_New->setText(QApplication::translate("MyEditLSY", "&New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_New->setToolTip(QApplication::translate("MyEditLSY", "Create new file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_New->setShortcut(QApplication::translate("MyEditLSY", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_Open->setText(QApplication::translate("MyEditLSY", "&Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Open->setToolTip(QApplication::translate("MyEditLSY", "Open new file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Open->setShortcut(QApplication::translate("MyEditLSY", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("MyEditLSY", "&Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Save->setToolTip(QApplication::translate("MyEditLSY", "Save a file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Save->setShortcut(QApplication::translate("MyEditLSY", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        action_Save_As->setText(QApplication::translate("MyEditLSY", "&Save As", 0, QApplication::UnicodeUTF8));
        action_Exit->setText(QApplication::translate("MyEditLSY", "&Exit", 0, QApplication::UnicodeUTF8));
        action_Cut->setText(QApplication::translate("MyEditLSY", "&Cut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Cut->setToolTip(QApplication::translate("MyEditLSY", "Cut  a fdata", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Cut->setShortcut(QApplication::translate("MyEditLSY", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        action_Copy->setText(QApplication::translate("MyEditLSY", "&Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Copy->setToolTip(QApplication::translate("MyEditLSY", "Copy a text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Copy->setShortcut(QApplication::translate("MyEditLSY", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        action_Past->setText(QApplication::translate("MyEditLSY", "&Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Past->setToolTip(QApplication::translate("MyEditLSY", "Paste a text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Past->setShortcut(QApplication::translate("MyEditLSY", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MyEditLSY", "&About", 0, QApplication::UnicodeUTF8));
        action_About_QT->setText(QApplication::translate("MyEditLSY", "&About QT", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MyEditLSY", "&File", 0, QApplication::UnicodeUTF8));
        menu_Option->setTitle(QApplication::translate("MyEditLSY", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MyEditLSY", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyEditLSY: public Ui_MyEditLSY {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYEDITLSY_H
