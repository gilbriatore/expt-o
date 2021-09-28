/****************************************************************************
** Meta object code from reading C++ file 'KinectWriter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Kinect/KinectWriter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KinectWriter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KinectWriter_t {
    QByteArrayData data[6];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KinectWriter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KinectWriter_t qt_meta_stringdata_KinectWriter = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KinectWriter"
QT_MOC_LITERAL(1, 13, 13), // "iniciarSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "processadoSignal"
QT_MOC_LITERAL(4, 45, 5), // "value"
QT_MOC_LITERAL(5, 51, 15) // "concluidoSignal"

    },
    "KinectWriter\0iniciarSignal\0\0"
    "processadoSignal\0value\0concluidoSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KinectWriter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       5,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void KinectWriter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KinectWriter *_t = static_cast<KinectWriter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iniciarSignal(); break;
        case 1: _t->processadoSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->concluidoSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (KinectWriter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KinectWriter::iniciarSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KinectWriter::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KinectWriter::processadoSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KinectWriter::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KinectWriter::concluidoSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject KinectWriter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_KinectWriter.data,
      qt_meta_data_KinectWriter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KinectWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KinectWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KinectWriter.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int KinectWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void KinectWriter::iniciarSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void KinectWriter::processadoSignal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KinectWriter::concluidoSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
