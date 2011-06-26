/****************************************************************************
** Meta object code from reading C++ file 'simplemergerwindow.h'
**
** Created: Sat Jun 18 22:54:45 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SimpleMerger/simplemergerwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simplemergerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimpleMergerWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      44,   42,   19,   19, 0x05,
      73,   19,   19,   19, 0x05,
     100,   42,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     139,   19,   19,   19, 0x0a,
     152,   19,   19,   19, 0x0a,
     171,   19,   19,   19, 0x0a,
     190,   42,   19,   19, 0x0a,
     219,   19,   19,   19, 0x0a,
     241,   19,   19,   19, 0x0a,
     281,   19,   19,   19, 0x0a,
     321,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SimpleMergerWindow[] = {
    "SimpleMergerWindow\0\0signal_StartProcess()\0"
    ",\0signal_OpenFile(int,QString)\0"
    "signal_SetMatchColumn(int)\0"
    "signal_SetFileColumns(QStringList,int)\0"
    "slot_Merge()\0slot_OpenFileOne()\0"
    "slot_OpenFileTwo()\0slot_FileOpened(int,QString)\0"
    "slot_SelectSaveFile()\0"
    "slot_FileOneColumnsEditChanged(QString)\0"
    "slot_FileTwoColumnsEditChanged(QString)\0"
    "slot_MatchColumnEditChanged(QString)\0"
};

const QMetaObject SimpleMergerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SimpleMergerWindow,
      qt_meta_data_SimpleMergerWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimpleMergerWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimpleMergerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimpleMergerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleMergerWindow))
        return static_cast<void*>(const_cast< SimpleMergerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SimpleMergerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signal_StartProcess(); break;
        case 1: signal_OpenFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: signal_SetMatchColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: signal_SetFileColumns((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: slot_Merge(); break;
        case 5: slot_OpenFileOne(); break;
        case 6: slot_OpenFileTwo(); break;
        case 7: slot_FileOpened((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: slot_SelectSaveFile(); break;
        case 9: slot_FileOneColumnsEditChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: slot_FileTwoColumnsEditChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: slot_MatchColumnEditChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SimpleMergerWindow::signal_StartProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SimpleMergerWindow::signal_OpenFile(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SimpleMergerWindow::signal_SetMatchColumn(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SimpleMergerWindow::signal_SetFileColumns(QStringList _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
