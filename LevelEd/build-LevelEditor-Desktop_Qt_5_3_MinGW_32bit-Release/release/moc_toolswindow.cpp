/****************************************************************************
** Meta object code from reading C++ file 'toolswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LevelEditor/toolswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ToolsWindow_t {
    QByteArrayData data[23];
    char stringdata[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolsWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolsWindow_t qt_meta_stringdata_ToolsWindow = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 18),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 5),
QT_MOC_LITERAL(4, 38, 19),
QT_MOC_LITERAL(5, 58, 8),
QT_MOC_LITERAL(6, 67, 7),
QT_MOC_LITERAL(7, 75, 8),
QT_MOC_LITERAL(8, 84, 9),
QT_MOC_LITERAL(9, 94, 7),
QT_MOC_LITERAL(10, 102, 6),
QT_MOC_LITERAL(11, 109, 8),
QT_MOC_LITERAL(12, 118, 9),
QT_MOC_LITERAL(13, 128, 12),
QT_MOC_LITERAL(14, 141, 8),
QT_MOC_LITERAL(15, 150, 5),
QT_MOC_LITERAL(16, 156, 14),
QT_MOC_LITERAL(17, 171, 17),
QT_MOC_LITERAL(18, 189, 3),
QT_MOC_LITERAL(19, 193, 13),
QT_MOC_LITERAL(20, 207, 17),
QT_MOC_LITERAL(21, 225, 21),
QT_MOC_LITERAL(22, 247, 5)
    },
    "ToolsWindow\0TileSelectorChange\0\0index\0"
    "ActorSelectorChange\0modeNone\0checked\0"
    "modeTile\0modeActor\0setLeft\0setTop\0"
    "setRight\0setBottom\0addToFactory\0"
    "setGroup\0group\0setTriggerType\0"
    "setNumToKeepAlive\0num\0setNumToSpawn\0"
    "setSpawnFrequency\0setTriggerSensitivity\0"
    "Saved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolsWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x0a /* Public */,
       4,    1,  102,    2, 0x0a /* Public */,
       5,    1,  105,    2, 0x0a /* Public */,
       7,    1,  108,    2, 0x0a /* Public */,
       8,    1,  111,    2, 0x0a /* Public */,
       9,    1,  114,    2, 0x0a /* Public */,
      10,    1,  117,    2, 0x0a /* Public */,
      11,    1,  120,    2, 0x0a /* Public */,
      12,    1,  123,    2, 0x0a /* Public */,
      13,    1,  126,    2, 0x0a /* Public */,
      14,    1,  129,    2, 0x0a /* Public */,
      16,    1,  132,    2, 0x0a /* Public */,
      17,    1,  135,    2, 0x0a /* Public */,
      19,    1,  138,    2, 0x0a /* Public */,
      20,    1,  141,    2, 0x0a /* Public */,
      21,    1,  144,    2, 0x0a /* Public */,
      22,    0,  147,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,

       0        // eod
};

void ToolsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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

const QMetaObject ToolsWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ToolsWindow.data,
      qt_meta_data_ToolsWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ToolsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolsWindow.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
