/****************************************************************************
** Meta object code from reading C++ file 'editmenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/editmenu.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editmenu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditMenu_t {
    QByteArrayData data[12];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditMenu_t qt_meta_stringdata_EditMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EditMenu"
QT_MOC_LITERAL(1, 9, 4), // "undo"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 4), // "redo"
QT_MOC_LITERAL(4, 20, 3), // "cut"
QT_MOC_LITERAL(5, 24, 4), // "copy"
QT_MOC_LITERAL(6, 29, 5), // "paste"
QT_MOC_LITERAL(7, 35, 4), // "find"
QT_MOC_LITERAL(8, 40, 13), // "undoAvailable"
QT_MOC_LITERAL(9, 54, 9), // "available"
QT_MOC_LITERAL(10, 64, 13), // "redoAvailable"
QT_MOC_LITERAL(11, 78, 13) // "copyAvailable"

    },
    "EditMenu\0undo\0\0redo\0cut\0copy\0paste\0"
    "find\0undoAvailable\0available\0redoAvailable\0"
    "copyAvailable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   65,    2, 0x0a /* Public */,
      10,    1,   68,    2, 0x0a /* Public */,
      11,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void EditMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditMenu *_t = static_cast<EditMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->undo(); break;
        case 1: _t->redo(); break;
        case 2: _t->cut(); break;
        case 3: _t->copy(); break;
        case 4: _t->paste(); break;
        case 5: _t->find(); break;
        case 6: _t->undoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->redoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->copyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EditMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMenu::undo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EditMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMenu::redo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EditMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMenu::cut)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EditMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMenu::copy)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EditMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMenu::paste)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EditMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMenu::find)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_EditMenu.data,
      qt_meta_data_EditMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EditMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int EditMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void EditMenu::undo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EditMenu::redo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EditMenu::cut()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EditMenu::copy()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void EditMenu::paste()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EditMenu::find()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
