/****************************************************************************
** Meta object code from reading C++ file 'iphotoviewer.h'
**
** Created: Thu Jul 29 21:46:37 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../iphotoviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iphotoviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_iPhotoViewer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      34,   13,   13,   13, 0x0a,
      56,   13,   13,   13, 0x0a,
      83,   13,   13,   13, 0x0a,
     115,  109,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_iPhotoViewer[] = {
    "iPhotoViewer\0\0pushButtonPressed()\0"
    "lstSelectionChanged()\0lstAlbumSelectionChanged()\0"
    "lstRollSelectionChanged()\0value\0"
    "sliderValueChanged(int)\0"
};

const QMetaObject iPhotoViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_iPhotoViewer,
      qt_meta_data_iPhotoViewer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &iPhotoViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *iPhotoViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *iPhotoViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_iPhotoViewer))
        return static_cast<void*>(const_cast< iPhotoViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int iPhotoViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pushButtonPressed(); break;
        case 1: lstSelectionChanged(); break;
        case 2: lstAlbumSelectionChanged(); break;
        case 3: lstRollSelectionChanged(); break;
        case 4: sliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
