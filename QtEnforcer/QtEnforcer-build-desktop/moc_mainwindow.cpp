/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Mar 20 01:43:00 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtEnforcer/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      37,   12,   11,   11, 0x05,
      62,   11,   11,   11, 0x05,
      79,   74,   11,   11, 0x05,
     113,  111,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     145,   11,   11,   11, 0x0a,
     161,   11,   11,   11, 0x0a,
     179,   11,   11,   11, 0x0a,
     193,   11,   11,   11, 0x0a,
     220,   11,   11,   11, 0x0a,
     255,   11,   11,   11, 0x0a,
     282,   11,   11,   11, 0x0a,
     325,  317,   11,   11, 0x0a,
     361,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0s\0setTargetFile(QString)\0"
    "setSnowballFile(QString)\0startScan()\0"
    "cols\0setComparedColumns(QList<int>&)\0"
    "i\0setRequiredMatchingColumns(int)\0"
    "onTargetClick()\0onSnowballClick()\0"
    "onStartScan()\0onComparedColumnsEnabled()\0"
    "onRequiredMatchingColumnsEnabled()\0"
    "onComparedColumnsChanged()\0"
    "onRequiredMatchingColumnsChanged()\0"
    "results\0slot_onComparisonDone(QStringList*)\0"
    "enableScanButton()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setTargetFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: setSnowballFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: startScan(); break;
        case 3: setComparedColumns((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 4: setRequiredMatchingColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: onTargetClick(); break;
        case 6: onSnowballClick(); break;
        case 7: onStartScan(); break;
        case 8: onComparedColumnsEnabled(); break;
        case 9: onRequiredMatchingColumnsEnabled(); break;
        case 10: onComparedColumnsChanged(); break;
        case 11: onRequiredMatchingColumnsChanged(); break;
        case 12: slot_onComparisonDone((*reinterpret_cast< QStringList*(*)>(_a[1]))); break;
        case 13: enableScanButton(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::setTargetFile(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setSnowballFile(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::startScan()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::setComparedColumns(QList<int> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::setRequiredMatchingColumns(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
