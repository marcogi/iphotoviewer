/*
 * BaseModel.cpp
 *
 *  Created on: 18.07.2010
 *      Author: david
 */

#include "BaseList.h"

BaseList::BaseList() {
	// TODO Auto-generated constructor stub
	//list=new QList<BaseModel*>();
	//idMap=new QMap<int,int>();
}

BaseList::~BaseList() {
	// TODO Auto-generated destructor stub
}

QVariant BaseList::data(const QModelIndex &index, int role) const {
	if (!index.isValid())
		return QVariant();

	if (index.row() >= list.size())
		return QVariant();

	if (role == Qt::DisplayRole)
	{
		BaseModel *model=list.at(index.row());
		return model->getDisplayString();
	}
	else if(role == Qt::UserRole)
	{
		BaseModel *model=list.at(index.row());
		QVariant qv;
		qv.setValue(model);
		return qv;
	}
	else
		return QVariant();
}

int BaseList::rowCount(const QModelIndex &parent) const {
	parent.isValid();
	return list.count();
}

QVariant BaseList::headerData(int section, Qt::Orientation orientation,
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

Qt::ItemFlags BaseList::flags(const QModelIndex &index) const {
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

bool BaseList::setData(const QModelIndex &index, const QVariant &value,
		int role) {
	if (index.isValid() && role == Qt::EditRole) {

		list.replace(index.row(), value.value<BaseModel*>());
		emit dataChanged(index, index);
		return true;
	}

	return false;
}

/*!
 Inserts a number of rows into the model at the specified position.
 */

bool BaseList::insertRows(int position, int rows,
		const QModelIndex &parent) {
	beginInsertRows(QModelIndex(), position, position + rows - 1);

	for (int row = 0; row < rows; ++row) {
		BaseModel *model;
		list.insert(position, model);
	}

	endInsertRows();
	return true;

}

/*!
 Removes a number of rows from the model at the specified position.
 */

bool BaseList::removeRows(int position, int rows,
		const QModelIndex &parent) {
	beginRemoveRows(QModelIndex(), position, position + rows - 1);

	for (int row = 0; row < rows; ++row) {
		list.removeAt(position);
	}

	endRemoveRows();
	return true;

}

void BaseList::append(BaseModel *model)
{
	int row=this->rowCount(QModelIndex());
	this->insertRow(row,QModelIndex());
	QModelIndex index = this->index(row, 0, QModelIndex());

	QVariant qv;
	qv.setValue(model);
	this->setData(index, qv);

	// we store the index mapped to a key, for fast access to objects, referenced by their id.
	//std::cout << model->getId() << "---" << index.row() << std::endl;
	int id=model->getId();
	int idx=index.row();
	list2.insert(id,idx);
}

BaseModel* BaseList::get(QModelIndex index)
{
	QVariant qv=this->data(index,Qt::UserRole);
	return qv.value<BaseModel*>();
}

BaseModel* BaseList::get(int key)
{
	int index=list2.value(key);
	Photo *p=(Photo*)list.at(index);
	return p;
}
