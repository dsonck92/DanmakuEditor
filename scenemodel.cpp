#include "scenemodel.h"

SceneModel::SceneModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    m_slObject << "Bosses" << "Spellcards" << "Patterns" << "Bullets" << "Drawables";
}

QModelIndex SceneModel::index(int row, int column, const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return QModelIndex();
    }
    else
    {
      return createIndex(row,column,0);
    }
}

QModelIndex SceneModel::parent(const QModelIndex &child) const
{
    if(!child.internalPointer())
    {
        return QModelIndex();
    }
}

int SceneModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
    {
        return m_slObject.count();
    }
    else
    {
        return 0;
    }
}

int SceneModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 1;
}

QVariant SceneModel::data(const QModelIndex &index, int role) const
{
    if(!index.parent().isValid())
    {
        switch(role)
        {
        case Qt::DisplayRole:
            return m_slObject[index.row()];
        }
    }
    return QVariant();
}
