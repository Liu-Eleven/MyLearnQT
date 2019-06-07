/********************************************************************************
** Form generated from reading UI file 'mybutton.ui'
**
** Created: Sun Dec 18 14:49:16 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYBUTTON_H
#define UI_MYBUTTON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyButton
{
public:

    void setupUi(QWidget *MyButton)
    {
        if (MyButton->objectName().isEmpty())
            MyButton->setObjectName(QString::fromUtf8("MyButton"));
        MyButton->resize(400, 300);

        retranslateUi(MyButton);

        QMetaObject::connectSlotsByName(MyButton);
    } // setupUi

    void retranslateUi(QWidget *MyButton)
    {
        MyButton->setWindowTitle(QApplication::translate("MyButton", "MyButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyButton: public Ui_MyButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYBUTTON_H
