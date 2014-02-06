#include "scene.h"

sScene SceneTemplate::run()
{
    return Scene::create(m_self);
}

Scene::Scene(sSceneTemplate t)
{
    m_sTemplate = t;
}
