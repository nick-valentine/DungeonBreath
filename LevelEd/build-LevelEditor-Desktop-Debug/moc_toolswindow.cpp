/****************************************************************************
** Meta object code from reading C++ file 'toolswindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LevelEditor/toolswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ToolsWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x0a,
      43,   13,   12,   12, 0x0a,
      76,   68,   12,   12, 0x0a,
      91,   68,   12,   12, 0x0a,
     106,   68,   12,   12, 0x0a,
     122,   13,   12,   12, 0x0a,
     135,   13,   12,   12, 0x0a,
     147,   13,   12,   12, 0x0a,
     161,   13,   12,   12, 0x0a,
     176,   68,   12,   12, 0x0a,
     201,  195,   12,   12, 0x0a,
     215,   13,   12,   12, 0x0a,
     239,  235,   12,   12, 0x0a,
     262,  235,   12,   12, 0x0a,
     281,  235,   12,   12, 0x0a,
     304,  235,   12,   12, 0x0a,
     331,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ToolsWindow[] = {
    "ToolsWindow\0\0index\0TileSelectorChange(int)\0"
    "ActorSelectorChange(int)\0checked\0"
    "modeNone(bool)\0modeTile(bool)\0"
    "modeActor(bool)\0setLeft(int)\0setTop(int)\0"
    "setRight(int)\0setBottom(int)\0"
    "addToFactory(bool)\0group\0setGroup(int)\0"
    "setTriggerType(int)\0num\0setNumToKeepAlive(int)\0"
    "setNumToSpawn(int)\0setSpawnFrequency(int)\0"
    "setTriggerSensitivity(int)\0Saved()\0"
};

void ToolsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ToolsWindow *_t = static_cast<ToolsWindow *>(_o);
        switch (_id) {
        case 0: _t->TileSelectorChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ActorSelectorChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->modeNone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->modeTile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->modeActor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setTop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setRight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setBottom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->addToFactory((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setTriggerType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setNumToKeepAlive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setNumToSpawn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setSpawnFrequency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setTriggerSensitivity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->Saved(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ToolsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ToolsWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ToolsWindow,
      qt_meta_data_ToolsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ToolsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ToolsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ToolsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolsWindow))
        return static_cast<void*>(const_cast< ToolsWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ToolsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
