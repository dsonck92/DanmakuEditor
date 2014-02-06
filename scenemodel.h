#ifndef SCENEMODEL_H
#define SCENEMODEL_H

#include <QAbstractItemModel>
#include <QStringList>

class SceneModel : public QAbstractItemModel
{
    Q_OBJECT

    QStringList m_slObject;
public:
    explicit SceneModel(QObject *parent = 0);

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;


signals:

public slots:

};

#endif // SCENEMODEL_H
