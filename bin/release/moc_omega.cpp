/****************************************************************************
** Meta object code from reading C++ file 'omega.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../maxon/omega.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'omega.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_omega_t {
    QByteArrayData data[8];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_omega_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_omega_t qt_meta_stringdata_omega = {
    {
QT_MOC_LITERAL(0, 0, 5), // "omega"
QT_MOC_LITERAL(1, 6, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(4, 52, 25), // "on_setForceButton_clicked"
QT_MOC_LITERAL(5, 78, 32), // "on_forceXSetEdit_editingFinished"
QT_MOC_LITERAL(6, 111, 32), // "on_forceYSetEdit_editingFinished"
QT_MOC_LITERAL(7, 144, 32) // "on_forceZSetEdit_editingFinished"

    },
    "omega\0on_openButton_clicked\0\0"
    "on_closeButton_clicked\0on_setForceButton_clicked\0"
    "on_forceXSetEdit_editingFinished\0"
    "on_forceYSetEdit_editingFinished\0"
    "on_forceZSetEdit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_omega[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void omega::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<omega *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_openButton_clicked(); break;
        case 1: _t->on_closeButton_clicked(); break;
        case 2: _t->on_setForceButton_clicked(); break;
        case 3: _t->on_forceXSetEdit_editingFinished(); break;
        case 4: _t->on_forceYSetEdit_editingFinished(); break;
        case 5: _t->on_forceZSetEdit_editingFinished(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject omega::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_omega.data,
    qt_meta_data_omega,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *omega::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *omega::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_omega.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int omega::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
