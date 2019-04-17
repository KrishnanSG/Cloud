/****************************************************************************
** Meta object code from reading C++ file 'search_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OOP Package/Cloud/search_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'search_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Search_Page_t {
    QByteArrayData data[10];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Search_Page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Search_Page_t qt_meta_stringdata_Search_Page = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Search_Page"
QT_MOC_LITERAL(1, 12, 15), // "on_home_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "on_search_clicked"
QT_MOC_LITERAL(4, 47, 16), // "on_cloud_clicked"
QT_MOC_LITERAL(5, 64, 23), // "on_notification_clicked"
QT_MOC_LITERAL(6, 88, 15), // "on_user_clicked"
QT_MOC_LITERAL(7, 104, 24), // "on_search_button_clicked"
QT_MOC_LITERAL(8, 129, 29), // "on_make_friend_button_clicked"
QT_MOC_LITERAL(9, 159, 30) // "on_view_profile_button_clicked"

    },
    "Search_Page\0on_home_clicked\0\0"
    "on_search_clicked\0on_cloud_clicked\0"
    "on_notification_clicked\0on_user_clicked\0"
    "on_search_button_clicked\0"
    "on_make_friend_button_clicked\0"
    "on_view_profile_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Search_Page[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Search_Page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Search_Page *_t = static_cast<Search_Page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_home_clicked(); break;
        case 1: _t->on_search_clicked(); break;
        case 2: _t->on_cloud_clicked(); break;
        case 3: _t->on_notification_clicked(); break;
        case 4: _t->on_user_clicked(); break;
        case 5: _t->on_search_button_clicked(); break;
        case 6: _t->on_make_friend_button_clicked(); break;
        case 7: _t->on_view_profile_button_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Search_Page::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Search_Page.data,
    qt_meta_data_Search_Page,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Search_Page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Search_Page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Search_Page.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Search_Page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
