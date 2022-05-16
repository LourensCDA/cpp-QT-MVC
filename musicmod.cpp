#include "musicmod.h"
#include <QString>
#include <QBrush>

musicMod::musicMod(QObject *parent): QAbstractTableModel(parent){}

musicMod::~musicMod()
{
    qDeleteAll(cdList);
};

int musicMod::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    // using header row with 4 columns
    return 4;
};

int musicMod::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return cdList.size();
};

QVariant musicMod::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignCenter | Qt::AlignVCenter);
    }

    int col = index.column();
    int row = index.row();


    if(role == Qt::BackgroundRole)
    {
        if (cdList.at(row)->getCost() >= 350)
        {
            Qt::GlobalColor color = Qt::red;
            QBrush background(color);
            return background;
        }
        if (cdList.at(row)->getCost() >= 250)
        {
            Qt::GlobalColor color = Qt::yellow;
            QBrush background(color);
            return background;
        }
    }

    if (role == Qt::DisplayRole)
    {

        if (col == 0)
        {
            return cdList.at(row)->getComposer();
        }

        if (col == 1)
        {
            return cdList.at(row)->getAlbum();
        }

        if (col == 2)
        {
            return QString("R %1").arg(cdList.at(row)->getCost(), 0, 'f', 2);
        }

        return cdList.at(row)->getRating();
    }

    return QVariant();
};

QVariant musicMod::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
        case 0:
            return QString("Composer");
            break;
        case 1:
            return QString("Album");
            break;
        case 2:
            return QString("Cost(Replace)");
            break;
        case 3:
            return QString("Rating");
            break;
        default:
            return QVariant();
    }

    return QVariant();
};

bool musicMod::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role==Qt::EditRole)
    {
        int col = index.column();
        int row = index.row();
        switch (col)
        {
            case 0:
                cdList.at(row)->setComposer(value.toString());
                break;
            case 1:
                cdList.at(row)->setAlbum(value.toString());
                break;
            case 2:
                cdList.at(row)->setCost(value.toFloat());
                break;
            case 3:
                cdList.at(row)->setRating(value.toInt());
                break;
            default:
                return false;
        }

        emit dataChanged(index, index);
        return true;
    }
    return false;
};

Qt::ItemFlags musicMod::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    else
        return Qt::NoItemFlags;
};

void musicMod::addNewCD(cd *cd)
{
    int rw = cdList.size();
    beginInsertRows(QModelIndex(), rw+1, rw+1);
    cdList.append(cd);
    endInsertRows();
};

void musicMod::removeCD(int rw)
{
    beginRemoveRows(QModelIndex(), rw, rw);
    cdList.removeAt(rw);
    endRemoveRows();
};



