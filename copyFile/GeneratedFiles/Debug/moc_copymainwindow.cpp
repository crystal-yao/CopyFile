/****************************************************************************
** Meta object code from reading C++ file 'copymainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../copymainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'copymainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CopyMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      29,   15,   15,   15, 0x08,
      47,   15,   15,   15, 0x08,
      58,   15,   15,   15, 0x08,
      81,   15,   15,   15, 0x08,
      98,   15,   15,   15, 0x08,
     111,   15,   15,   15, 0x08,
     118,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CopyMainWindow[] = {
    "CopyMainWindow\0\0choosefile()\0"
    "chooseDirectory()\0copyFile()\0"
    "changeThreadCount(int)\0setText(QString)\0"
    "unableCopy()\0quit()\0cancel()\0"
};

void CopyMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CopyMainWindow *_t = static_cast<CopyMainWindow *>(_o);
        switch (_id) {
        case 0: _t->choosefile(); break;
        case 1: _t->chooseDirectory(); break;
        case 2: _t->copyFile(); break;
        case 3: _t->changeThreadCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->unableCopy(); break;
        case 6: _t->quit(); break;
        case 7: _t->cancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CopyMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CopyMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CopyMainWindow,
      qt_meta_data_CopyMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CopyMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CopyMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CopyMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CopyMainWindow))
        return static_cast<void*>(const_cast< CopyMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CopyMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
