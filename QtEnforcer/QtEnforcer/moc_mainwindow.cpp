/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun May 15 22:36:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
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
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      37,   12,   11,   11, 0x05,
      62,   11,   11,   11, 0x05,
      90,   11,   11,   11, 0x05,
     107,  102,   11,   11, 0x05,
     140,  138,   11,   11, 0x05,
     172,   11,   11,   11, 0x05,
     193,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     219,   11,   11,   11, 0x0a,
     240,   11,   11,   11, 0x0a,
     263,   11,   11,   11, 0x0a,
     282,   11,   11,   11, 0x0a,
     311,   11,   11,   11, 0x0a,
     343,   11,   11,   11, 0x0a,
     383,   11,   11,   11, 0x0a,
     415,   11,   11,   11, 0x0a,
     455,   11,   11,   11, 0x0a,
     479,   11,   11,   11, 0x08,
     503,   11,   11,   11, 0x08,
     527,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0s\0setTargetFile(QString)\0"
    "setSnowballFile(QString)\0"
    "signal_setSaveFile(QString)\0startScan()\0"
    "cols\0setComparedColumns(QList<int>)\0"
    "i\0setRequiredMatchingColumns(int)\0"
    "signal_viewResults()\0signal_enableViewButton()\0"
    "slot_onTargetClick()\0slot_onSnowballClick()\0"
    "slot_onStartScan()\0slot_onSelectSaveFileClick()\0"
    "slot_onComparedColumnsEnabled()\0"
    "slot_onRequiredMatchingColumnsEnabled()\0"
    "slot_onComparedColumnsChanged()\0"
    "slot_onRequiredMatchingColumnsChanged()\0"
    "slot_onComparisonDone()\0slot_enableScanButton()\0"
    "slot_enableViewButton()\0slot_onViewClick()\0"
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
        case 2: signal_setSaveFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: startScan(); break;
        case 4: setComparedColumns((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 5: setRequiredMatchingColumns((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: signal_viewResults(); break;
        case 7: signal_enableViewButton(); break;
        case 8: slot_onTargetClick(); break;
        case 9: slot_onSnowballClick(); break;
        case 10: slot_onStartScan(); break;
        case 11: slot_onSelectSaveFileClick(); break;
        case 12: slot_onComparedColumnsEnabled(); break;
        case 13: slot_onRequiredMatchingColumnsEnabled(); break;
        case 14: slot_onComparedColumnsChanged(); break;
        case 15: slot_onRequiredMatchingColumnsChanged(); break;
        case 16: slot_onComparisonDone(); break;
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
void MainWindow::signal_setSaveFile(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::startScan()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::setComparedColumns(const QList<int> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::setRequiredMatchingColumns(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::signal_viewResults()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainWindow::signal_enableViewButton()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
