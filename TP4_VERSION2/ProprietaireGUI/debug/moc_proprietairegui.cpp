/****************************************************************************
** Meta object code from reading C++ file 'proprietairegui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../proprietairegui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proprietairegui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProprietaireGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      43,   16,   16,   16, 0x08,
      58,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ProprietaireGUI[] = {
    "ProprietaireGUI\0\0dialogVehiculePromenade()\0"
    "dialogCamion()\0dialogSupprimerVehicule()\0"
};

void ProprietaireGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProprietaireGUI *_t = static_cast<ProprietaireGUI *>(_o);
        switch (_id) {
        case 0: _t->dialogVehiculePromenade(); break;
        case 1: _t->dialogCamion(); break;
        case 2: _t->dialogSupprimerVehicule(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ProprietaireGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProprietaireGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ProprietaireGUI,
      qt_meta_data_ProprietaireGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProprietaireGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProprietaireGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProprietaireGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProprietaireGUI))
        return static_cast<void*>(const_cast< ProprietaireGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ProprietaireGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
