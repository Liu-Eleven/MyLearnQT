/****************************************************************************
** Meta object code from reading C++ file 'handaddrbook.h'
**
** Created: Wed Dec 21 19:32:52 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "handaddrbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handaddrbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HandAddrBook[] = {

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
      14,   13,   13,   13, 0x08,
      24,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,
      48,   13,   13,   13, 0x08,
      59,   13,   13,   13, 0x08,
      72,   13,   13,   13, 0x08,
      85,   13,   13,   13, 0x08,
      96,   13,   13,   13, 0x08,
     107,   13,   13,   13, 0x08,
     120,   13,   13,   13, 0x08,
     135,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HandAddrBook[] = {
    "HandAddrBook\0\0AddData()\0EditData()\0"
    "RemoveData()\0FindData()\0SubmitData()\0"
    "CancelData()\0LoadData()\0SaveData()\0"
    "ExportData()\0PreviousData()\0NextData()\0"
};

void HandAddrBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HandAddrBook *_t = static_cast<HandAddrBook *>(_o);
        switch (_id) {
        case 0: _t->AddData(); break;
        case 1: _t->EditData(); break;
        case 2: _t->RemoveData(); break;
        case 3: _t->FindData(); break;
        case 4: _t->SubmitData(); break;
        case 5: _t->CancelData(); break;
        case 6: _t->LoadData(); break;
        case 7: _t->SaveData(); break;
        case 8: _t->ExportData(); break;
        case 9: _t->PreviousData(); break;
        case 10: _t->NextData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HandAddrBook::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HandAddrBook::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HandAddrBook,
      qt_meta_data_HandAddrBook, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HandAddrBook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HandAddrBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HandAddrBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HandAddrBook))
        return static_cast<void*>(const_cast< HandAddrBook*>(this));
    return QWidget::qt_metacast(_clname);
}

int HandAddrBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
