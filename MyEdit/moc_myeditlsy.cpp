/****************************************************************************
** Meta object code from reading C++ file 'myeditlsy.h'
**
** Created: Thu Dec 29 10:16:24 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myeditlsy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myeditlsy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyEditLSY[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      29,   10,   10,   10, 0x08,
      56,   10,   10,   10, 0x08,
      82,   10,   10,   10, 0x08,
     109,   10,   10,   10, 0x08,
     139,   10,   10,   10, 0x08,
     166,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyEditLSY[] = {
    "MyEditLSY\0\0DocumentChanged()\0"
    "on_action_Exit_triggered()\0"
    "on_action_New_triggered()\0"
    "on_action_Open_triggered()\0"
    "on_action_Save_As_triggered()\0"
    "on_action_Save_triggered()\0"
    "on_action_Cut_triggered()\0"
};

void MyEditLSY::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyEditLSY *_t = static_cast<MyEditLSY *>(_o);
        switch (_id) {
        case 0: _t->DocumentChanged(); break;
        case 1: _t->on_action_Exit_triggered(); break;
        case 2: _t->on_action_New_triggered(); break;
        case 3: _t->on_action_Open_triggered(); break;
        case 4: _t->on_action_Save_As_triggered(); break;
        case 5: _t->on_action_Save_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyEditLSY::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyEditLSY::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyEditLSY,
      qt_meta_data_MyEditLSY, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyEditLSY::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyEditLSY::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyEditLSY::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyEditLSY))
        return static_cast<void*>(const_cast< MyEditLSY*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyEditLSY::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
