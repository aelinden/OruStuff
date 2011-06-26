/****************************************************************************
** Meta object code from reading C++ file 'fileprocessor.h'
**
** Created: Sat Jun 18 22:06:53 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FileProcessor/fileprocessor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileProcessor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   15,   14,   14, 0x05,
      50,   14,   14,   14, 0x05,
      74,   14,   14,   14, 0x05,
     101,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     127,  125,   14,   14, 0x0a,
     157,   14,   14,   14, 0x0a,
     172,   14,   14,   14, 0x0a,
     198,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FileProcessor[] = {
    "FileProcessor\0\0id,\0signal_FileOpened(int,QString)\0"
    "signal_MatchColumnSet()\0"
    "signal_FileColumnsSet(int)\0"
    "signal_ProcessingDone()\0,\0"
    "slot_OpenFile(FILEID,QString)\0"
    "slot_Process()\0slot_SetMatchColumns(int)\0"
    "slot_SetMatchColumns(QList<int>)\0"
};

const QMetaObject FileProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileProcessor,
      qt_meta_data_FileProcessor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileProcessor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileProcessor))
        return static_cast<void*>(const_cast< FileProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int FileProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signal_FileOpened((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: signal_MatchColumnSet(); break;
        case 2: signal_FileColumnsSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: signal_ProcessingDone(); break;
        case 4: slot_OpenFile((*reinterpret_cast< FILEID(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: slot_Process(); break;
        case 6: slot_SetMatchColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: slot_SetMatchColumns((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FileProcessor::signal_FileOpened(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileProcessor::signal_MatchColumnSet()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FileProcessor::signal_FileColumnsSet(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileProcessor::signal_ProcessingDone()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
