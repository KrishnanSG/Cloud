/****************************************************************************
** Meta object code from reading C++ file 'notifications_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OOP Package/Cloud/notifications_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notifications_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Notifications_Page_t {
    QByteArrayData data[9];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Notifications_Page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Notifications_Page_t qt_meta_stringdata_Notifications_Page = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Notifications_Page"
QT_MOC_LITERAL(1, 19, 15), // "on_home_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "on_search_clicked"
QT_MOC_LITERAL(4, 54, 16), // "on_cloud_clicked"
QT_MOC_LITERAL(5, 71, 23), // "on_notification_clicked"
QT_MOC_LITERAL(6, 95, 15), // "on_user_clicked"
QT_MOC_LITERAL(7, 111, 32), // "on_Accept_Request_Button_clicked"
QT_MOC_LITERAL(8, 144, 25) // "on_Delete_Request_clicked"

    },
    "Notifications_Page\0on_home_clicked\0\0"
    "on_search_clicked\0on_cloud_clicked\0"
    "on_notification_clicked\0on_user_clicked\0"
    "on_Accept_Request_Button_clicked\0"
    "on_Delete_Request_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notifications_Page[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Notifications_Page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notifications_Page *_t = static_cast<Notifications_Page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_home_clicked(); break;
        case 1: _t->on_search_clicked(); break;
        case 2: _t->on_cloud_clicked(); break;
        case 3: _t->on_notification_clicked(); break;
        case 4: _t->on_user_clicked(); break;
        case 5: _t->on_Accept_Request_Button_clicked(); break;
        case 6: _t->on_Delete_Request_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Notifications_Page::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Notifications_Page.data,
    qt_meta_data_Notifications_Page,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Notifications_Page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notifications_Page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Notifications_Page.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Notifications_Page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
