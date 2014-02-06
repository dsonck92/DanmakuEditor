#ifndef SCENEBOX_H
#define SCENEBOX_H

#include <QWidget>
#include <QMenu>
#include <QMap>

class QPushButton;

enum ObjectTypes {
    NoObject = 0,
    BossObject,
    SpellCardObject,
    PatternObject,
    BulletObject,
    DrawableObject
};

class SceneBox : public QWidget
{
    Q_OBJECT
    QMenu *m_mObjectChooser;
    QMap<QAction*,ObjectTypes> m_typeMap;
    QPushButton *m_pbAdd;
public:
    explicit SceneBox(QWidget *parent = 0);

signals:

public slots:
    void addObject();

};

#endif // SCENEBOX_H
