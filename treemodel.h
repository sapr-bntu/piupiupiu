#ifndef TREEMODEL_H

#define TREEMODEL_H

#include <QAbstractListModel>
#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>


class TreeModelItem;

class TreeModel : public QAbstractListModel

{

    Q_OBJECT

public:

    explicit TreeModel(QObject *parent=0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

public slots:

    void openItem(int numIndex);

    void closeItem(int numIndex);

private:

    Q_DISABLE_COPY(TreeModel);

    QList<TreeModelItem *> items;

    enum ListMenuItemRoles

    {

        NameRole = Qt::UserRole+1,

        LevelRole,

        IsOpenedRole,

        HasChildrenRole

    };

};

#endif // TREEMODEL_H
