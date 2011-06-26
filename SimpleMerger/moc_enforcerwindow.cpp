/****************************************************************************
** Meta object code from reading C++ file 'enforcerwindow.h'
**
** Created: Sat Jun 18 22:27:37 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtEnforcer/QtEnforcer/enforcerwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enforcerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EnforcerWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,
      47,   15,   15,   15, 0x05,
      75,   15,   15,   15, 0x05,
      99,   94,   15,   15, 0x05,
     139,  137,   15,   15, 0x05,
     178,   15,   15,   15, 0x05,
     199,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     237,  225,   15,   15, 0x0a,
     266,   15,   15,   15, 0x0a,
     291,   15,   15,   15, 0x0a,
     318,   15,   15,   15, 0x0a,
     341,   15,   15,   15, 0x0a,
     360,   15,   15,   15, 0x0a,
     392,   15,   15,   15, 0x0a,
     432,   15,   15,   15, 0x0a,
     464,   15,   15,   15, 0x0a,
     504,   15,   15,   15, 0x0a,
     528,   15,   15,   15, 0x08,
     552,   15,   15,   15, 0x08,
     576,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EnforcerWindow[] = {
    "EnforcerWindow\0\0,\0signal_OpenFile(int,QString)\0"
    "signal_SetSaveFile(QString)\0"
    "signal_StartScan()\0cols\0"
    "signal_SetComparedColumns(QList<int>)\0"
    "i\0signal_SetRequiredMatchingColumns(int)\0"
    "signal_ViewResults()\0signal_EnableViewButton()\0"
    "id,fileName\0slot_FileOpened(int,QString)\0"
    "slot_onTargetFileClick()\0"
    "slot_onSnowballFileClick()\0"
    "slot_onSaveFileClick()\0slot_onStartScan()\0"
    "slot_onComparedColumnsEnabled()\0"
    "slot_onRequiredMatchingColumnsEnabled()\0"
    "slot_onComparedColumnsChanged()\0"
    "slot_onRequiredMatchingColumnsChanged()\0"
    "slot_onProcessingDone()\0slot_enableScanButton()\0"
    "slot_enableViewButton()\0slot_onViewClick()\0"
};

const QMetaObject EnforcerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EnforcerWindow,
      qt_meta_data_EnforcerWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EnforcerWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EnforcerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EnforcerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EnforcerWindow))
        return static_cast<void*>(const_cast< EnforcerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int EnforcerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signal_OpenFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: signal_SetSaveFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: signal_StartScan(); break;
        case 3: signal_SetComparedColumns((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 4: signal_SetRequiredMatchingColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: signal_ViewResults(); break;
        case 6: signal_EnableViewButton(); break;
        case 7: slot_FileOpened((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: slot_onTargetFileClick(); break;
        case 9: slot_onSnowballFileClick(); break;
        case 10: slot_onSaveFileClick(); break;
        case 11: slot_onStartScan(); break;
        case 12: slot_onComparedColumnsEnabled(); break;
        case 13: slot_onRequiredMatchingColumnsEnabled(); break;
        case 14: slot_onComparedColumnsChanged(); break;
        case 15: slot_onRequiredMatchingColumnsChanged(); break;
        case 16: slot_onProcessingDone(); break;
        case 17: slot_enableScanButton(); break;
        case 18: slot_enableViewButton(); break;
        case 19: slot_onViewClick(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void EnforcerWindow::signal_OpenFile(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EnforcerWindow::signal_SetSaveFile(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EnforcerWindow::signal_StartScan()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void EnforcerWindow::signal_SetComparedColumns(const QList<int> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EnforcerWindow::signal_SetRequiredMatchingColumns(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void EnforcerWindow::signal_ViewResults()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void EnforcerWindow::signal_EnableViewButton()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
