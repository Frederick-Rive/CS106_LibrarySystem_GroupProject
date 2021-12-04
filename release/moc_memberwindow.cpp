/****************************************************************************
** Meta object code from reading C++ file 'memberwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CS106_GroupProject/memberwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'memberwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MemberWindow_t {
    const uint offsetsAndSize[30];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MemberWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MemberWindow_t qt_meta_stringdata_MemberWindow = {
    {
QT_MOC_LITERAL(0, 12), // "MemberWindow"
QT_MOC_LITERAL(13, 10), // "HomeScreen"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 25), // "on_facebookButton_clicked"
QT_MOC_LITERAL(51, 24), // "on_twitterButton_clicked"
QT_MOC_LITERAL(76, 22), // "on_instaButton_clicked"
QT_MOC_LITERAL(99, 24), // "on_logout_button_clicked"
QT_MOC_LITERAL(124, 27), // "on_viewbooks_button_clicked"
QT_MOC_LITERAL(152, 12), // "DisplayBooks"
QT_MOC_LITERAL(165, 17), // "DisplaySingleBook"
QT_MOC_LITERAL(183, 17), // "LibSystems::Book*"
QT_MOC_LITERAL(201, 4), // "book"
QT_MOC_LITERAL(206, 25), // "on_account_Button_clicked"
QT_MOC_LITERAL(232, 25), // "on_overdue_button_clicked"
QT_MOC_LITERAL(258, 23) // "on_returnButton_clicked"

    },
    "MemberWindow\0HomeScreen\0\0"
    "on_facebookButton_clicked\0"
    "on_twitterButton_clicked\0"
    "on_instaButton_clicked\0on_logout_button_clicked\0"
    "on_viewbooks_button_clicked\0DisplayBooks\0"
    "DisplaySingleBook\0LibSystems::Book*\0"
    "book\0on_account_Button_clicked\0"
    "on_overdue_button_clicked\0"
    "on_returnButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MemberWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    1,   87,    2, 0x08,    8 /* Private */,
      12,    0,   90,    2, 0x08,   10 /* Private */,
      13,    0,   91,    2, 0x08,   11 /* Private */,
      14,    0,   92,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MemberWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MemberWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->HomeScreen(); break;
        case 1: _t->on_facebookButton_clicked(); break;
        case 2: _t->on_twitterButton_clicked(); break;
        case 3: _t->on_instaButton_clicked(); break;
        case 4: _t->on_logout_button_clicked(); break;
        case 5: _t->on_viewbooks_button_clicked(); break;
        case 6: _t->DisplayBooks(); break;
        case 7: _t->DisplaySingleBook((*reinterpret_cast< LibSystems::Book*(*)>(_a[1]))); break;
        case 8: _t->on_account_Button_clicked(); break;
        case 9: _t->on_overdue_button_clicked(); break;
        case 10: _t->on_returnButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MemberWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MemberWindow.offsetsAndSize,
    qt_meta_data_MemberWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MemberWindow_t
, QtPrivate::TypeAndForceComplete<MemberWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LibSystems::Book *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MemberWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MemberWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MemberWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MemberWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
