/****************************************************************************
** Meta object code from reading C++ file 'viewbook.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CS106_GroupProject/viewbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ViewBook_t {
    const uint offsetsAndSize[16];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ViewBook_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ViewBook_t qt_meta_stringdata_ViewBook = {
    {
QT_MOC_LITERAL(0, 8), // "ViewBook"
QT_MOC_LITERAL(9, 6), // "Finish"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 8), // "EmitBook"
QT_MOC_LITERAL(26, 17), // "LibSystems::Book*"
QT_MOC_LITERAL(44, 4), // "book"
QT_MOC_LITERAL(49, 11), // "ReserveBook"
QT_MOC_LITERAL(61, 8) // "EditBook"

    },
    "ViewBook\0Finish\0\0EmitBook\0LibSystems::Book*\0"
    "book\0ReserveBook\0EditBook"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewBook[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    1,   39,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   42,    2, 0x08,    4 /* Private */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ViewBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ViewBook *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Finish(); break;
        case 1: _t->EmitBook((*reinterpret_cast< LibSystems::Book*(*)>(_a[1]))); break;
        case 2: _t->ReserveBook(); break;
        case 3: _t->EditBook(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ViewBook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ViewBook::Finish)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ViewBook::*)(LibSystems::Book * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ViewBook::EmitBook)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ViewBook::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ViewBook.offsetsAndSize,
    qt_meta_data_ViewBook,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ViewBook_t
, QtPrivate::TypeAndForceComplete<ViewBook, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LibSystems::Book *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ViewBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewBook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewBook.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ViewBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ViewBook::Finish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ViewBook::EmitBook(LibSystems::Book * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
