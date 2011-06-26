/****************************************************************************
** Meta object code from reading C++ file 'comparer.h'
**
** Created: Tue Jun 14 22:38:03 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "comparer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comparer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Comparer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      38,    9,    9,    9, 0x05,
      74,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     103,   98,    9,    9, 0x0a,
     155,  139,    9,    9, 0x0a,
     186,  184,    9,    9, 0x0a,
     215,  184,    9,    9, 0x0a,
     246,    9,    9,    9, 0x0a,
     261,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Comparer[] = {
    "Comparer\0\0signal_ComparedColumnsSet()\0"
    "signal_RequiredMatchingColumnsSet()\0"
    "signal_ComparisonDone()\0cols\0"
    "slot_SetComparedColumns(QList<int>)\0"
    "numberOfMatches\0slot_SetRequiredMatches(int)\0"
    "f\0slot_OpenTargetFile(QString)\0"
    "slot_OpenSnowballFile(QString)\0"
    "slot_Compare()\0slot_SetSaveFile(QString)\0"
};

const QMetaObject Comparer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Comparer,
      qt_meta_data_Comparer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Comparer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Comparer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Comparer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Comparer))
        return static_cast<void*>(const_cast< Comparer*>(this));
    return QObject::qt_metacast(_clname);
}

int Comparer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signal_ComparedColumnsSet(); break;
        case 1: signal_RequiredMatchingColumnsSet(); break;
        case 2: signal_ComparisonDone(); break;
        case 3: slot_SetComparedColumns((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 4: slot_SetRequiredMatches((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: slot_OpenTargetFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: slot_OpenSnowballFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: slot_Compare(); break;
        case 8: slot_SetSaveFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Comparer::signal_ComparedColumnsSet()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Comparer::signal_RequiredMatchingColumnsSet()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Comparer::signal_ComparisonDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
