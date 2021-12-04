/****************************************************************************
** Meta object code from reading C++ file 'returnbooks.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CS106_GroupProject/returnbooks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'returnbooks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReturnBooks_t {
    const uint offsetsAndSize[12];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ReturnBooks_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ReturnBooks_t qt_meta_stringdata_ReturnBooks = {
    {
QT_MOC_LITERAL(0, 11), // "ReturnBooks"
QT_MOC_LITERAL(12, 6), // "Finish"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 10), // "ReturnBook"
QT_MOC_LITERAL(31, 12), // "FlagReturned"
QT_MOC_LITERAL(44, 15) // "FlagNotReturned"

    },
    "ReturnBooks\0Finish\0\0ReturnBook\0"
    "FlagReturned\0FlagNotReturned"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReturnBooks[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ReturnBooks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReturnBooks *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Finish(); break;
        case 1: _t->ReturnBook(); break;
        case 2: _t->FlagReturned(); break;
        case 3: _t->FlagNotReturned(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReturnBooks::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReturnBooks::Finish)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject ReturnBooks::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ReturnBooks.offsetsAndSize,
    qt_meta_data_ReturnBooks,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ReturnBooks_t
, QtPrivate::TypeAndForceComplete<ReturnBooks, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ReturnBooks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReturnBooks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReturnBooks.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ReturnBooks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ReturnBooks::Finish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
