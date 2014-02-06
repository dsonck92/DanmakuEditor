#ifndef BOSSTEMPLATE_H
#define BOSSTEMPLATE_H

#include "classes.h"
#include "gameobjects.h"
#include "QList"

class BossTemplate
{
    friend class Boss;
    friend class DanmakuView;

    DECLARE_SHARED(BossTemplate,(),)
protected:
    sDrawable m_dImage;

    QList<sSpellCard> m_lscCards;

public:
    BossTemplate();
};

class Boss : public Movable
{
    friend class DanmakuView;

    DECLARE_SHARED(Boss,(sBossTemplate t), (t))
protected:
    sBossTemplate m_btTemplate;
public:
    Boss(sBossTemplate t);

};

#endif // BOSSTEMPLATE_H
