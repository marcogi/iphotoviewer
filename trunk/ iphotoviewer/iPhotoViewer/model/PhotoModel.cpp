/*
 * IPhotoPhotosList.cpp
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#include "PhotoModel.h"

PhotoModel::PhotoModel() {
	// TODO Auto-generated constructor stub

}

PhotoModel::~PhotoModel() {
	// TODO Auto-generated destructor stub
}

QVariant PhotoModel::data(const QModelIndex &index, int role) const {
	if (!index.isValid())
		return QVariant();

	if (index.row() >= list.size())
		return QVariant();

	if (role == Qt::DisplayRole)
	{
		Photo photo=list.at(index.row());
		return photo.getCaption();
	}
	else if(role == Qt::UserRole)
	{
		Photo photo=list.at(index.row());
		QVariant qv;
		qv.setValue(photo);
		return qv;//.getThumbPath();
	}
	else
		return QVariant();
}

int PhotoModel::rowCount(const QModelIndex &parent) const {
	parent.isValid();
	return list.count();
}

QVariant PhotoModel::headerData(int section, Qt::Orientation orientation,
		int role) const {
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Horizontal)
		return QString("Column %1").arg(section);
	else
		return QString("Row %1").arg(section);
}

/*!
 Returns an appropriate value for the item's flags. Valid items are
 enabled, selectable, and editable.
 */

Qt::ItemFlags PhotoModel::flags(const QModelIndex &index) const {
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

/*!
 Changes an item in the string list, but only if the following conditions
 are met:

 * The index supplied is valid.
 * The index corresponds to an item to be shown in a view.
 * The role associated with editing text is specified.

 The dataChanged() signal is emitted if the item is changed.
 */

bool PhotoModel::setData(const QModelIndex &index, const QVariant &value,
		int role) {
	if (index.isValid() && role == Qt::EditRole) {

		list.replace(index.row(), value.value<Photo>());
		emit dataChanged(index, index);
		return true;
	}

	return false;
}

/*!
 Inserts a number of rows into the model at the specified position.
 */

bool PhotoModel::insertRows(int position, int rows,
		const QModelIndex &parent) {
	beginInsertRows(QModelIndex(), position, position + rows - 1);

	for (int row = 0; row < rows; ++row) {
		Photo photo;
		list.insert(position, photo);
	}

	endInsertRows();
	return true;

}

/*!
 Removes a number of rows from the model at the specified position.
 */

bool PhotoModel::removeRows(int position, int rows,
		const QModelIndex &parent) {
	beginRemoveRows(QModelIndex(), position, position + rows - 1);

	for (int row = 0; row < rows; ++row) {
		list.removeAt(position);
	}

	endRemoveRows();
	return true;

}

void PhotoModel::append(Photo photo)
{
	int row=this->rowCount(QModelIndex());
	this->insertRow(row,QModelIndex());
	QModelIndex index = this->index(row, 0, QModelIndex());

	QVariant qv;
	qv.setValue(photo);
	this->setData(index, qv);
}

Photo PhotoModel::get(QModelIndex index)
{
	QVariant qv=this->data(index,Qt::UserRole);
	return qv.value<Photo>();
}
