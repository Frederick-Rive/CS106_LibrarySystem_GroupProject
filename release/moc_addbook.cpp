/****************************************************************************
** Meta object code from reading C++ file 'addbook.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CS106_GroupProject/addbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddBook_t {
    const uint offsetsAndSize[20];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AddBook_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AddBook_t qt_meta_stringdata_AddBook = {
    {
QT_MOC_LITERAL(0, 7), // "AddBook"
QT_MOC_LITERAL(8, 6), // "Finish"
QT_MOC_LITERAL(15, 0), // ""
QT_MOC_LITERAL(16, 24), // "on_ddSlider_valueChanged"
QT_MOC_LITERAL(41, 5), // "value"
QT_MOC_LITERAL(47, 25), // "on_ddCounter_valueChanged"
QT_MOC_LITERAL(73, 4), // "arg1"
QT_MOC_LITERAL(78, 26), // "on_coverpathSearch_clicked"
QT_MOC_LITERAL(105, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(127, 26) // "on_monthEntry_valueChanged"

    },
    "AddBook\0Finish\0\0on_ddSlider_valueChanged\0"
    "value\0on_ddCounter_valueChanged\0arg1\0"
    "on_coverpathSearch_clicked\0"
    "on_saveButton_clicked\0on_monthEntry_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddBook[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   51,    2, 0x08,    2 /* Private */,
       5,    1,   54,    2, 0x08,    4 /* Private */,
       7,    0,   57,    2, 0x08,    6 /* Private */,
       8,    0,   58,    2, 0x08,    7 /* Private */,
       9,    1,   59,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void AddBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddBook *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Finish(); break;
        case 1: _t->on_ddSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_ddCounter_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_coverpathSearch_clicked(); break;
        case 4: _t->on_saveButton_clicked(); break;
        case 5: _t->on_monthEntry_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddBook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddBook::Finish)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AddBook::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AddBook.offsetsAndSize,
    qt_meta_data_AddBook,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AddBook_t
, QtPrivate::TypeAndForceComplete<AddBook, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *AddBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddBook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddBook.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AddBook::Finish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
