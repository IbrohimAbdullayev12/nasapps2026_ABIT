/****************************************************************************
** Meta object code from reading C++ file 'FeaturePages.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/FeaturePages.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FeaturePages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11ReactionPadE_t {};
} // unnamed namespace

template <> constexpr inline auto ReactionPad::qt_create_metaobjectdata<qt_meta_tag_ZN11ReactionPadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ReactionPad",
        "finished",
        "",
        "QList<int>",
        "reactionMs",
        "falseStarts",
        "progress",
        "done",
        "total"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'finished'
        QtMocHelpers::SignalData<void(QVector<int>, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'progress'
        QtMocHelpers::SignalData<void(int, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { QMetaType::Int, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ReactionPad, qt_meta_tag_ZN11ReactionPadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ReactionPad::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ReactionPadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ReactionPadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11ReactionPadE_t>.metaTypes,
    nullptr
} };

void ReactionPad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ReactionPad *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast<std::add_pointer_t<QList<int>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->progress((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ReactionPad::*)(QVector<int> , int )>(_a, &ReactionPad::finished, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ReactionPad::*)(int , int )>(_a, &ReactionPad::progress, 1))
            return;
    }
}

const QMetaObject *ReactionPad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReactionPad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ReactionPadE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ReactionPad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ReactionPad::finished(QVector<int> _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void ReactionPad::progress(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}
namespace {
struct qt_meta_tag_ZN14CrewHealthPageE_t {};
} // unnamed namespace

template <> constexpr inline auto CrewHealthPage::qt_create_metaobjectdata<qt_meta_tag_ZN14CrewHealthPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "CrewHealthPage"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<CrewHealthPage, qt_meta_tag_ZN14CrewHealthPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject CrewHealthPage::staticMetaObject = { {
    QMetaObject::SuperData::link<ScrollPage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14CrewHealthPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14CrewHealthPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14CrewHealthPageE_t>.metaTypes,
    nullptr
} };

void CrewHealthPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CrewHealthPage *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *CrewHealthPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CrewHealthPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14CrewHealthPageE_t>.strings))
        return static_cast<void*>(this);
    return ScrollPage::qt_metacast(_clname);
}

int CrewHealthPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScrollPage::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN16BiotelemetryPageE_t {};
} // unnamed namespace

template <> constexpr inline auto BiotelemetryPage::qt_create_metaobjectdata<qt_meta_tag_ZN16BiotelemetryPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BiotelemetryPage"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BiotelemetryPage, qt_meta_tag_ZN16BiotelemetryPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject BiotelemetryPage::staticMetaObject = { {
    QMetaObject::SuperData::link<ScrollPage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16BiotelemetryPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16BiotelemetryPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16BiotelemetryPageE_t>.metaTypes,
    nullptr
} };

void BiotelemetryPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BiotelemetryPage *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *BiotelemetryPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BiotelemetryPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16BiotelemetryPageE_t>.strings))
        return static_cast<void*>(this);
    return ScrollPage::qt_metacast(_clname);
}

int BiotelemetryPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScrollPage::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN15EnvironmentPageE_t {};
} // unnamed namespace

template <> constexpr inline auto EnvironmentPage::qt_create_metaobjectdata<qt_meta_tag_ZN15EnvironmentPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "EnvironmentPage"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<EnvironmentPage, qt_meta_tag_ZN15EnvironmentPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject EnvironmentPage::staticMetaObject = { {
    QMetaObject::SuperData::link<ScrollPage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15EnvironmentPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15EnvironmentPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15EnvironmentPageE_t>.metaTypes,
    nullptr
} };

void EnvironmentPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EnvironmentPage *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *EnvironmentPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnvironmentPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15EnvironmentPageE_t>.strings))
        return static_cast<void*>(this);
    return ScrollPage::qt_metacast(_clname);
}

int EnvironmentPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScrollPage::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN10AlertsPageE_t {};
} // unnamed namespace

template <> constexpr inline auto AlertsPage::qt_create_metaobjectdata<qt_meta_tag_ZN10AlertsPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AlertsPage"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AlertsPage, qt_meta_tag_ZN10AlertsPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AlertsPage::staticMetaObject = { {
    QMetaObject::SuperData::link<ScrollPage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10AlertsPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10AlertsPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10AlertsPageE_t>.metaTypes,
    nullptr
} };

void AlertsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AlertsPage *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *AlertsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlertsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10AlertsPageE_t>.strings))
        return static_cast<void*>(this);
    return ScrollPage::qt_metacast(_clname);
}

int AlertsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScrollPage::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN8SansPageE_t {};
} // unnamed namespace

template <> constexpr inline auto SansPage::qt_create_metaobjectdata<qt_meta_tag_ZN8SansPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SansPage"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SansPage, qt_meta_tag_ZN8SansPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SansPage::staticMetaObject = { {
    QMetaObject::SuperData::link<ScrollPage::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8SansPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8SansPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8SansPageE_t>.metaTypes,
    nullptr
} };

void SansPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SansPage *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *SansPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SansPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8SansPageE_t>.strings))
        return static_cast<void*>(this);
    return ScrollPage::qt_metacast(_clname);
}

int SansPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScrollPage::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
