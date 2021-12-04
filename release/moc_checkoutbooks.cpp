/****************************************************************************
** Meta object code from reading C++ file 'checkoutbooks.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CS106_GroupProject/checkoutbooks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkoutbooks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CheckoutBooks_t {
    const uint offsetsAndSize[12];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CheckoutBooks_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CheckoutBooks_t qt_meta_stringdata_CheckoutBooks = {
    {
QT_MOC_LITERAL(0, 13), // "CheckoutBooks"
QT_MOC_LITERAL(14, 6), // "Remove"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 1), // "i"
QT_MOC_LITERAL(24, 24), // "on_confirmButton_clicked"
QT_MOC_LITERAL(49, 24) // "on_dismissButton_clicked"

    },
    "CheckoutBooks\0Remove\0\0i\0"
    "on_confirmButton_clicked\0"
    "on_dismissButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CheckoutBooks[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   35,    2, 0x08,    3 /* Private */,
       5,    0,   36,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CheckoutBooks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CheckoutBooks *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_confirmButton_clicked(); break;
        case 2: _t->on_dismissButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CheckoutBooks::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CheckoutBooks::Remove)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CheckoutBooks::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CheckoutBooks.offsetsAndSize,
    qt_meta_data_CheckoutBooks,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CheckoutBooks_t
, QtPrivate::TypeAndForceComplete<CheckoutBooks, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CheckoutBooks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CheckoutBooks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CheckoutBooks.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CheckoutBooks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CheckoutBooks::Remove(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
