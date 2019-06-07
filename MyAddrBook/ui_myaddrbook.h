/********************************************************************************
** Form generated from reading UI file 'myaddrbook.ui'
**
** Created: Mon Dec 19 14:56:19 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYADDRBOOK_H
#define UI_MYADDRBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyAddrBook
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditName;
    QTextEdit *textEditAddr;
    QLabel *label_Name;
    QLabel *label_Addr;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Edit;
    QPushButton *pushButton_Remove;
    QPushButton *pushButton_Find;
    QPushButton *pushButton_Submit;
    QPushButton *pushButton_Cancle;
    QPushButton *pushButton_Load;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Export;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Previous;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Next;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *MyAddrBook)
    {
        if (MyAddrBook->objectName().isEmpty())
            MyAddrBook->setObjectName(QString::fromUtf8("MyAddrBook"));
        MyAddrBook->resize(396, 386);
        gridLayoutWidget = new QWidget(MyAddrBook);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 393, 381));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditName = new QLineEdit(gridLayoutWidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 0, 1, 1, 1);

        textEditAddr = new QTextEdit(gridLayoutWidget);
        textEditAddr->setObjectName(QString::fromUtf8("textEditAddr"));

        gridLayout->addWidget(textEditAddr, 1, 1, 1, 1);

        label_Name = new QLabel(gridLayoutWidget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        gridLayout->addWidget(label_Name, 0, 0, 1, 1);

        label_Addr = new QLabel(gridLayoutWidget);
        label_Addr->setObjectName(QString::fromUtf8("label_Addr"));
        label_Addr->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_Addr, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_Add = new QPushButton(gridLayoutWidget);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));

        verticalLayout->addWidget(pushButton_Add);

        pushButton_Edit = new QPushButton(gridLayoutWidget);
        pushButton_Edit->setObjectName(QString::fromUtf8("pushButton_Edit"));

        verticalLayout->addWidget(pushButton_Edit);

        pushButton_Remove = new QPushButton(gridLayoutWidget);
        pushButton_Remove->setObjectName(QString::fromUtf8("pushButton_Remove"));

        verticalLayout->addWidget(pushButton_Remove);

        pushButton_Find = new QPushButton(gridLayoutWidget);
        pushButton_Find->setObjectName(QString::fromUtf8("pushButton_Find"));

        verticalLayout->addWidget(pushButton_Find);

        pushButton_Submit = new QPushButton(gridLayoutWidget);
        pushButton_Submit->setObjectName(QString::fromUtf8("pushButton_Submit"));

        verticalLayout->addWidget(pushButton_Submit);

        pushButton_Cancle = new QPushButton(gridLayoutWidget);
        pushButton_Cancle->setObjectName(QString::fromUtf8("pushButton_Cancle"));

        verticalLayout->addWidget(pushButton_Cancle);

        pushButton_Load = new QPushButton(gridLayoutWidget);
        pushButton_Load->setObjectName(QString::fromUtf8("pushButton_Load"));

        verticalLayout->addWidget(pushButton_Load);

        pushButton_Save = new QPushButton(gridLayoutWidget);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        verticalLayout->addWidget(pushButton_Save);

        pushButton_Export = new QPushButton(gridLayoutWidget);
        pushButton_Export->setObjectName(QString::fromUtf8("pushButton_Export"));

        verticalLayout->addWidget(pushButton_Export);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Previous = new QPushButton(gridLayoutWidget);
        pushButton_Previous->setObjectName(QString::fromUtf8("pushButton_Previous"));

        horizontalLayout->addWidget(pushButton_Previous);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Next = new QPushButton(gridLayoutWidget);
        pushButton_Next->setObjectName(QString::fromUtf8("pushButton_Next"));

        horizontalLayout->addWidget(pushButton_Next);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);


        retranslateUi(MyAddrBook);
        QObject::connect(pushButton_Add, SIGNAL(clicked()), MyAddrBook, SLOT(MyAdd()));
        QObject::connect(pushButton_Edit, SIGNAL(clicked()), MyAddrBook, SLOT(MyEdit()));
        QObject::connect(pushButton_Remove, SIGNAL(clicked()), MyAddrBook, SLOT(MyRemove()));
        QObject::connect(pushButton_Find, SIGNAL(clicked()), MyAddrBook, SLOT(MyFind()));
        QObject::connect(pushButton_Submit, SIGNAL(clicked()), MyAddrBook, SLOT(MySubmit()));
        QObject::connect(pushButton_Cancle, SIGNAL(clicked()), MyAddrBook, SLOT(MyCancle()));
        QObject::connect(pushButton_Load, SIGNAL(clicked()), MyAddrBook, SLOT(MyLoad()));
        QObject::connect(pushButton_Save, SIGNAL(clicked()), MyAddrBook, SLOT(MySave()));
        QObject::connect(pushButton_Export, SIGNAL(clicked()), MyAddrBook, SLOT(MyExport()));
        QObject::connect(pushButton_Previous, SIGNAL(clicked()), MyAddrBook, SLOT(MyPrevious()));
        QObject::connect(pushButton_Next, SIGNAL(clicked()), MyAddrBook, SLOT(MyNext()));

        QMetaObject::connectSlotsByName(MyAddrBook);
    } // setupUi

    void retranslateUi(QWidget *MyAddrBook)
    {
        MyAddrBook->setWindowTitle(QApplication::translate("MyAddrBook", "MyAddrBook", 0, QApplication::UnicodeUTF8));
        label_Name->setText(QApplication::translate("MyAddrBook", "Name:", 0, QApplication::UnicodeUTF8));
        label_Addr->setText(QApplication::translate("MyAddrBook", "Address:", 0, QApplication::UnicodeUTF8));
        pushButton_Add->setText(QApplication::translate("MyAddrBook", "&Add", 0, QApplication::UnicodeUTF8));
        pushButton_Edit->setText(QApplication::translate("MyAddrBook", "&Edit", 0, QApplication::UnicodeUTF8));
        pushButton_Remove->setText(QApplication::translate("MyAddrBook", "&Remove", 0, QApplication::UnicodeUTF8));
        pushButton_Find->setText(QApplication::translate("MyAddrBook", "&Find", 0, QApplication::UnicodeUTF8));
        pushButton_Submit->setText(QApplication::translate("MyAddrBook", "&Submit", 0, QApplication::UnicodeUTF8));
        pushButton_Cancle->setText(QApplication::translate("MyAddrBook", "&Cancle", 0, QApplication::UnicodeUTF8));
        pushButton_Load->setText(QApplication::translate("MyAddrBook", "&Load...", 0, QApplication::UnicodeUTF8));
        pushButton_Save->setText(QApplication::translate("MyAddrBook", "&Save...", 0, QApplication::UnicodeUTF8));
        pushButton_Export->setText(QApplication::translate("MyAddrBook", "E&xport", 0, QApplication::UnicodeUTF8));
        pushButton_Previous->setText(QApplication::translate("MyAddrBook", "&Previous", 0, QApplication::UnicodeUTF8));
        pushButton_Next->setText(QApplication::translate("MyAddrBook", "&Next", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyAddrBook: public Ui_MyAddrBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYADDRBOOK_H
