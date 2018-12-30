/****************************************************************************
** Meta object code from reading C++ file 'na_qt_test1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../na_qt_test1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'na_qt_test1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NA_Qt_test1_t {
    QByteArrayData data[7];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NA_Qt_test1_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NA_Qt_test1_t qt_meta_stringdata_NA_Qt_test1 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NA_Qt_test1"
QT_MOC_LITERAL(1, 12, 22), // "on_AdapterList_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "index"
QT_MOC_LITERAL(4, 42, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(5, 65, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(6, 87, 11) // "ongetPcaket"

    },
    "NA_Qt_test1\0on_AdapterList_clicked\0\0"
    "index\0on_startButton_clicked\0"
    "on_stopButton_clicked\0ongetPcaket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NA_Qt_test1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void NA_Qt_test1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NA_Qt_test1 *_t = static_cast<NA_Qt_test1 *>(_o);
        switch (_id) {
        case 0: _t->on_AdapterList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_startButton_clicked(); break;
        case 2: _t->on_stopButton_clicked(); break;
        case 3: _t->ongetPcaket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NA_Qt_test1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NA_Qt_test1.data,
      qt_meta_data_NA_Qt_test1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NA_Qt_test1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NA_Qt_test1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NA_Qt_test1.stringdata))
        return static_cast<void*>(const_cast< NA_Qt_test1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NA_Qt_test1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
