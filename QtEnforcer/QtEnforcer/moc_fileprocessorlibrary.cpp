/****************************************************************************
** Meta object code from reading C++ file 'fileprocessorlibrary.h'
**
** Created: Sat Jun 18 21:49:02 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FileProcessorLibrary/FileProcessorLibrary/fileprocessorlibrary.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileprocessorlibrary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileProcessorLibrary[] = {

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
      26,   22,   21,   21, 0x05,
      57,   21,   21,   21, 0x05,
      81,   21,   21,   21, 0x05,
     108,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     134,  132,   21,   21, 0x0a,
     186,   21,   21,   21, 0x0a,
     201,   21,   21,   21, 0x0a,
     227,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FileProcessorLibrary[] = {
    "FileProcessorLibrary\0\0id,\0"
    "signal_FileOpened(int,QString)\0"
    "signal_MatchColumnSet()\0"
    "signal_FileColumnsSet(int)\0"
    "signal_ProcessingDone()\0,\0"
    "slot_OpenFile(FileProcessorLibrary::FileId,QString)\0"
    "slot_Process()\0slot_SetMatchColumns(int)\0"
    "slot_SetMatchColumns(QList<int>)\0"
};

const QMetaObject FileProcessorLibrary::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileProcessorLibrary,
      qt_meta_data_FileProcessorLibrary, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileProcessorLibrary::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileProcessorLibrary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileProcessorLibrary::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileProcessorLibrary))
        return static_cast<void*>(const_cast< FileProcessorLibrary*>(this));
    return QObject::qt_metacast(_clname);
}

int FileProcessorLibrary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: slot_OpenFile((*reinterpret_cast< FileProcessorLibrary::FileId(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
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
void FileProcessorLibrary::signal_FileOpened(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileProcessorLibrary::signal_MatchColumnSet()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FileProcessorLibrary::signal_FileColumnsSet(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileProcessorLibrary::signal_ProcessingDone()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
