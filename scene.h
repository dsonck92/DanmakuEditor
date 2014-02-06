#ifndef SCENE_H
#define SCENE_H

#include "classes.h"
#include <QList>

class SceneTemplate
{
    friend class Scene;
    friend class DanmakuView;

    DECLARE_SHARED(SceneTemplate,(),)

protected:
    QList<sBossTemplate> m_lbtBossTemplates;

public:

    sBossTemplate createBoss();
    sScene run();

};

class Scene
{
    friend class DanmakuView;

    DECLARE_SHARED(Scene, ( sSceneTemplate t ) , ( t ) )

protected:
    sSceneTemplate m_sTemplate;
    QList<sBoss> m_lbBosses;
public:
    Scene(sSceneTemplate t);
};

#endif // SCENE_H
