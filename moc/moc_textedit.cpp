/****************************************************************************
** Meta object code from reading C++ file 'textedit.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/textedit.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Textedit_t {
    QByteArrayData data[12];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Textedit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Textedit_t qt_meta_stringdata_Textedit = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Textedit"
QT_MOC_LITERAL(1, 9, 13), // "tabtextchange"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "Textedit*"
QT_MOC_LITERAL(4, 34, 8), // "textedit"
QT_MOC_LITERAL(5, 43, 7), // "newtext"
QT_MOC_LITERAL(6, 51, 6), // "edited"
QT_MOC_LITERAL(7, 58, 8), // "onchange"
QT_MOC_LITERAL(8, 67, 7), // "setUndo"
QT_MOC_LITERAL(9, 75, 9), // "available"
QT_MOC_LITERAL(10, 85, 7), // "setRedo"
QT_MOC_LITERAL(11, 93, 7) // "setCopy"

    },
    "Textedit\0tabtextchange\0\0Textedit*\0"
    "textedit\0newtext\0edited\0onchange\0"
    "setUndo\0available\0setRedo\0setCopy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Textedit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   46,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,
      10,    1,   50,    2, 0x08 /* Private */,
      11,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Bool,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void Textedit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Textedit *_t = static_cast<Textedit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tabtextchange((*reinterpret_cast< Textedit*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->onchange(); break;
        case 2: _t->setUndo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setRedo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setCopy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Textedit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Textedit::*)(Textedit * , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Textedit::tabtextchange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Textedit::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_Textedit.data,
      qt_meta_data_Textedit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Textedit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Textedit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Textedit.stringdata0))
        return static_cast<void*>(this);
    return QPlainTextEdit::qt_metacast(_clname);
}

int Textedit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Textedit::tabtextchange(Textedit * _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
