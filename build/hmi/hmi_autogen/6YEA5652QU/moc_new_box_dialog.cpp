/****************************************************************************
** Meta object code from reading C++ file 'new_box_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ros2_ws/src/hmi/include/new_box_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_box_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewBoxDialog_t {
    QByteArrayData data[9];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewBoxDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewBoxDialog_t qt_meta_stringdata_NewBoxDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "NewBoxDialog"
QT_MOC_LITERAL(1, 13, 28), // "on_cancle_pushButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 25), // "on_add_pushButton_clicked"
QT_MOC_LITERAL(4, 69, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(5, 101, 32), // "on_boxIdLineEdit_editingFinished"
QT_MOC_LITERAL(6, 134, 33), // "on_boxLatLineEdit_editingFini..."
QT_MOC_LITERAL(7, 168, 33), // "on_boxLonLineEdit_editingFini..."
QT_MOC_LITERAL(8, 202, 33) // "on_boxAltLineEdit_editingFini..."

    },
    "NewBoxDialog\0on_cancle_pushButton_clicked\0"
    "\0on_add_pushButton_clicked\0"
    "on_comboBox_currentIndexChanged\0"
    "on_boxIdLineEdit_editingFinished\0"
    "on_boxLatLineEdit_editingFinished\0"
    "on_boxLonLineEdit_editingFinished\0"
    "on_boxAltLineEdit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewBoxDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x0a /* Public */,
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewBoxDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewBoxDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_cancle_pushButton_clicked(); break;
        case 1: _t->on_add_pushButton_clicked(); break;
        case 2: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_boxIdLineEdit_editingFinished(); break;
        case 4: _t->on_boxLatLineEdit_editingFinished(); break;
        case 5: _t->on_boxLonLineEdit_editingFinished(); break;
        case 6: _t->on_boxAltLineEdit_editingFinished(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NewBoxDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_NewBoxDialog.data,
    qt_meta_data_NewBoxDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewBoxDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewBoxDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewBoxDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NewBoxDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
