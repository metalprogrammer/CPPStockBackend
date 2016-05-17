/****************************************************************************
** Meta object code from reading C++ file 'webservice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WebService/webservice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebService_t {
    QByteArrayData data[7];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebService_t qt_meta_stringdata_WebService = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WebService"
QT_MOC_LITERAL(1, 11, 13), // "handleRequest"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "QHttpRequest*"
QT_MOC_LITERAL(4, 40, 3), // "req"
QT_MOC_LITERAL(5, 44, 14), // "QHttpResponse*"
QT_MOC_LITERAL(6, 59, 4) // "resp"

    },
    "WebService\0handleRequest\0\0QHttpRequest*\0"
    "req\0QHttpResponse*\0resp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebService[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void WebService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebService *_t = static_cast<WebService *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleRequest((*reinterpret_cast< QHttpRequest*(*)>(_a[1])),(*reinterpret_cast< QHttpResponse*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject WebService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebService.data,
      qt_meta_data_WebService,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebService::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebService.stringdata0))
        return static_cast<void*>(const_cast< WebService*>(this));
    return QObject::qt_metacast(_clname);
}

int WebService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
