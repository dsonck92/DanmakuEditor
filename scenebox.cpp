#include "scenebox.h"

#include <QTreeView>
#include <QPushButton>

#include <QGridLayout>

#include "scenemodel.h"

SceneBox::SceneBox(QWidget *parent) :
    QWidget(parent)
{
    m_mObjectChooser = new QMenu();
    m_typeMap.insert(m_mObjectChooser->addAction("Boss"),BossObject);
    m_typeMap.insert(m_mObjectChooser->addAction("SpellCard"),SpellCardObject);
    m_typeMap.insert(m_mObjectChooser->addAction("Pattern"),PatternObject);
    m_typeMap.insert(m_mObjectChooser->addAction("Bullet"),BulletObject);
    m_mObjectChooser->addSeparator();
    m_typeMap.insert(m_mObjectChooser->addAction("Drawable"),DrawableObject);
    setWindowTitle("Scene");
    QGridLayout *layout = new QGridLayout(this);

    QTreeView *tree = new QTreeView();
    layout->addWidget(tree,0,0,1,2);

    tree->setModel(new SceneModel);

    QPushButton *button;
    layout->addWidget(m_pbAdd = button = new QPushButton("Add"),1,0);
    connect(button,SIGNAL(clicked()),SLOT(addObject()));
    layout->addWidget(new QPushButton("Remove"),1,1);
}

void SceneBox::addObject()
{
    m_mObjectChooser->exec(m_pbAdd->mapToGlobal(QPoint(0,0)));
}
