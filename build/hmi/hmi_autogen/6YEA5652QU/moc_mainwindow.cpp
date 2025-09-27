/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ros2_ws/src/hmi/include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[653];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "onBackEndStopped"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "onBackEndCrashed"
QT_MOC_LITERAL(4, 46, 18), // "onHeartBeatMessage"
QT_MOC_LITERAL(5, 65, 32), // "std_msgs::msg::String::SharedPtr"
QT_MOC_LITERAL(6, 98, 3), // "msg"
QT_MOC_LITERAL(7, 102, 30), // "on_settings_pushButton_clicked"
QT_MOC_LITERAL(8, 133, 30), // "on_add_box_push_button_clicked"
QT_MOC_LITERAL(9, 164, 25), // "on_arm_pushButton_clicked"
QT_MOC_LITERAL(10, 190, 29), // "on_takeoff_pushButton_clicked"
QT_MOC_LITERAL(11, 220, 33), // "on_return_home_pushButton_cli..."
QT_MOC_LITERAL(12, 254, 26), // "on_land_pushButton_clicked"
QT_MOC_LITERAL(13, 281, 36), // "on_request_status_pushButton_..."
QT_MOC_LITERAL(14, 318, 33), // "on_upload_path_pushButton_cli..."
QT_MOC_LITERAL(15, 352, 29), // "on_zoom_in_pushButton_clicked"
QT_MOC_LITERAL(16, 382, 30), // "on_zoom_out_pushButton_clicked"
QT_MOC_LITERAL(17, 413, 34), // "on_assign_drone_pushButton_cl..."
QT_MOC_LITERAL(18, 448, 33), // "on_removedrone_pushButton_cli..."
QT_MOC_LITERAL(19, 482, 33), // "on_changedrone_pushButton_cli..."
QT_MOC_LITERAL(20, 516, 32), // "on_remove_box_pushButton_clicked"
QT_MOC_LITERAL(21, 549, 33), // "on_path_upload_pushButton_cli..."
QT_MOC_LITERAL(22, 583, 34), // "on_boxComboBox_currentIndexCh..."
QT_MOC_LITERAL(23, 618, 34) // "on_zoom_in_out_slider_valueCh..."

    },
    "MainWindow\0onBackEndStopped\0\0"
    "onBackEndCrashed\0onHeartBeatMessage\0"
    "std_msgs::msg::String::SharedPtr\0msg\0"
    "on_settings_pushButton_clicked\0"
    "on_add_box_push_button_clicked\0"
    "on_arm_pushButton_clicked\0"
    "on_takeoff_pushButton_clicked\0"
    "on_return_home_pushButton_clicked\0"
    "on_land_pushButton_clicked\0"
    "on_request_status_pushButton_clicked\0"
    "on_upload_path_pushButton_clicked\0"
    "on_zoom_in_pushButton_clicked\0"
    "on_zoom_out_pushButton_clicked\0"
    "on_assign_drone_pushButton_clicked\0"
    "on_removedrone_pushButton_clicked\0"
    "on_changedrone_pushButton_clicked\0"
    "on_remove_box_pushButton_clicked\0"
    "on_path_upload_pushButton_clicked\0"
    "on_boxComboBox_currentIndexChanged\0"
    "on_zoom_in_out_slider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    1,  116,    2, 0x08 /* Private */,
       7,    1,  119,    2, 0x08 /* Private */,
       8,    0,  122,    2, 0x08 /* Private */,
       9,    0,  123,    2, 0x08 /* Private */,
      10,    0,  124,    2, 0x08 /* Private */,
      11,    0,  125,    2, 0x08 /* Private */,
      12,    0,  126,    2, 0x08 /* Private */,
      13,    0,  127,    2, 0x08 /* Private */,
      14,    0,  128,    2, 0x08 /* Private */,
      15,    0,  129,    2, 0x08 /* Private */,
      16,    0,  130,    2, 0x08 /* Private */,
      17,    0,  131,    2, 0x08 /* Private */,
      18,    0,  132,    2, 0x08 /* Private */,
      19,    0,  133,    2, 0x08 /* Private */,
      20,    0,  134,    2, 0x08 /* Private */,
      21,    0,  135,    2, 0x08 /* Private */,
      22,    1,  136,    2, 0x08 /* Private */,
      23,    1,  139,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onBackEndStopped(); break;
        case 1: _t->onBackEndCrashed(); break;
        case 2: _t->onHeartBeatMessage((*reinterpret_cast< const std_msgs::msg::String::SharedPtr(*)>(_a[1]))); break;
        case 3: _t->on_settings_pushButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_add_box_push_button_clicked(); break;
        case 5: _t->on_arm_pushButton_clicked(); break;
        case 6: _t->on_takeoff_pushButton_clicked(); break;
        case 7: _t->on_return_home_pushButton_clicked(); break;
        case 8: _t->on_land_pushButton_clicked(); break;
        case 9: _t->on_request_status_pushButton_clicked(); break;
        case 10: _t->on_upload_path_pushButton_clicked(); break;
        case 11: _t->on_zoom_in_pushButton_clicked(); break;
        case 12: _t->on_zoom_out_pushButton_clicked(); break;
        case 13: _t->on_assign_drone_pushButton_clicked(); break;
        case 14: _t->on_removedrone_pushButton_clicked(); break;
        case 15: _t->on_changedrone_pushButton_clicked(); break;
        case 16: _t->on_remove_box_pushButton_clicked(); break;
        case 17: _t->on_path_upload_pushButton_clicked(); break;
        case 18: _t->on_boxComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_zoom_in_out_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
