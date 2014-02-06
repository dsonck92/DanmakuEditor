#ifndef CLASSES_H
#define CLASSES_H

#include <QSharedPointer>

#define DECLARE_CLASS(a) class a;\
    typedef a * p##a; \
    typedef QSharedPointer<a> s##a;\
    typedef QWeakPointer<a> w##a;

#define DECLARE_SHARED(a,arg,arg2) private: \
w##a m_self; \
    void register_ref(s##a self){m_self = self;}\
    public:\
    static s##a create arg {s##a obj = s##a(new a arg2);obj->register_ref(obj);return obj;}

DECLARE_CLASS( Drawable )
DECLARE_CLASS( Action )
DECLARE_CLASS( BulletTemplate )
DECLARE_CLASS( Bullet )
DECLARE_CLASS( SpellCard )
DECLARE_CLASS( EnemyTemplate )
DECLARE_CLASS( Enemy )
DECLARE_CLASS( BossTemplate )
DECLARE_CLASS( Boss )
DECLARE_CLASS( SceneTemplate )
DECLARE_CLASS( Scene )

#endif // CLASSES_H
