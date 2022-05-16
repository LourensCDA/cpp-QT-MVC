#ifndef MUSICMOD_H
#define MUSICMOD_H

#include <QAbstractTableModel>
#include <QList>
#include <QSortFilterProxyModel>
#include "cd.h"

class musicMod: public QAbstractTableModel
{
public:
    musicMod(QObject *parent=0);
    ~musicMod();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void addNewCD(cd *cd);
    void removeCD(int rw);


private:
    QList<cd *> cdList;
};

#endif // MUSICMOD_H
