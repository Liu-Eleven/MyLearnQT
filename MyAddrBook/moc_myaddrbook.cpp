/****************************************************************************
** Meta object code from reading C++ file 'myaddrbook.h'
**
** Created: Tue Dec 20 20:22:01 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myaddrbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myaddrbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyAddrBook[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      20,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      71,   11,   11,   11, 0x08,
      80,   11,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
     100,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyAddrBook[] = {
    "MyAddrBook\0\0MyAdd()\0MyEdit()\0MyRemove()\0"
    "MyFind()\0MySubmit()\0MyCancle()\0MyLoad()\0"
    "MySave()\0MyExport()\0MyPrevious()\0"
    "MyNext()\0"
};

void MyAddrBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyAddrBook *_t = static_cast<MyAddrBook *>(_o);
        switch (_id) {
        case 0: _t->MyAdd(); break;
        case 1: _t->MyEdit(); break;
        case 2: _t->MyRemove(); break;
        case 3: _t->MyFind(); break;
        case 4: _t->MySubmit(); break;
        case 5: _t->MyCancle(); break;
        case 6: _t->MyLoad(); break;
        case 7: _t->MySave(); break;
        case 8: _t->MyExport(); break;
        case 9: _t->MyPrevious(); break;
        case 10: _t->MyNext(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyAddrBook::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyAddrBook::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyAddrBook,
      qt_meta_data_MyAddrBook, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyAddrBook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyAddrBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyAddrBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyAddrBook))
        return static_cast<void*>(const_cast< MyAddrBook*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyAddrBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
