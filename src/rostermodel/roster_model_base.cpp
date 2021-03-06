#include "roster_model_base.h"

#include <QIcon>

#include "rostermodel/roster_index.h"
#include "utils/icon_decorator.h"
#include "skinengine/qqskinengine.h"

__RosterModelBase::__RosterModelBase(QObject *parent) : QAbstractItemModel(parent), proxy_(NULL)
{
	root_ = new RosterIndex(RIT_Root);
}
__RosterModelBase::~__RosterModelBase()
{
	if ( root_ )
		delete root_;
	root_ = NULL;
}

QModelIndex __RosterModelBase::parent(const QModelIndex &child) const
{
	RosterIndex *child_index = rosterIndexByModelIndex(child);
	return modelIndexByRosterIndex(child_index->parent());
}

QModelIndex __RosterModelBase::index(int row, int column, const QModelIndex &parent) const
{
	RosterIndex *child = rosterIndexByModelIndex(parent)->child(row);
	if ( child )
		return createIndex(row, column, child);

	return QModelIndex();
}

QVariant __RosterModelBase::data(const QModelIndex &index, int role) const
{
	RosterIndex *roster_index = rosterIndexByModelIndex(index);
	if ( roster_index == root_ )
		return QVariant();

	QVariant data = roster_index->data(role);
	if ( role == Qt::DecorationRole ) 
	{
		if ( roster_index->type() == RIT_Contact )
		{
			if ( data.isValid() )
			{
				QPixmap pix = data.value<QPixmap>();
				IconDecorator::decorateIcon(roster_index->data(TDR_Status).value<ContactStatus>(), pix);	
				return pix;
			}
			else
				return QPixmap(QQSkinEngine::instance()->skinRes("default_friend_avatar"));
		}
		else if ( roster_index->type() == RIT_Group )
		{
			if ( data.isValid() )
			{
				return data;
			}
			else
				return QPixmap(QQSkinEngine::instance()->skinRes("default_group_avatar"));
		}
	}

	return data;
}

int __RosterModelBase::rowCount(const QModelIndex &parent) const
{
	return rosterIndexByModelIndex(parent)->childCount();
}

int __RosterModelBase::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent)
	return 1;
}

RosterIndex *__RosterModelBase::rosterIndexByModelIndex(const QModelIndex &index) const
{
	return index.isValid() ? static_cast<RosterIndex *>(index.internalPointer()) : root_;
}

QModelIndex __RosterModelBase::modelIndexByRosterIndex(const RosterIndex *index) const
{
	if ( index && index != root_ )
		return createIndex(index->row(), 0, (RosterIndex *const)index);

	return QModelIndex();
}

/*
void __RosterModelBase::getDefaultPixmap(const QQItem *item, QPixmap &pix) const
{
    if (item->type() == QQItem::kFriend)
    {
        QIcon icon(QQSkinEngine::instance()->getSkinRes("default_friend_avatar"));

        if (item->status() == CS_Offline)
        {
            pix = icon.pixmap(QSize(icon_size_), QIcon::Disabled, QIcon::On);
        }
        else
            pix = icon.pixmap(QSize(icon_size_));
    }

    if (item->type() == QQItem::kGroup)
    {
        QIcon icon(QQSkinEngine::instance()->getSkinRes("default_group_avatar"));
        pix = icon.pixmap(QSize(icon_size_));
    }
}
*/

void __RosterModelBase::setProxyModel(QAbstractProxyModel *proxy)
{
	proxy_ = proxy;
}

QAbstractProxyModel *__RosterModelBase::proxyModel() const
{
	return proxy_;
}
