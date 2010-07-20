/*
 * BaseModel.h
 *
 *  Created on: 18.07.2010
 *      Author: david
 */

#ifndef BASELIST_H_
#define BASELIST_H_

#include <iostream>
#include <QAbstractListModel>
#include <QObject>
#include <QVariant>
#include <QHash>
#include <QList>
#include "BaseModel.h"
#include "Photo.h"

class BaseList : public QAbstractListModel {
public:
	BaseList();
	virtual ~BaseList();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole);

	bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
	bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

	void append(BaseModel* model);
	BaseModel* get(QModelIndex index);
	BaseModel* get(int key);
private:
	QHash<int,int> list2;
	QList<BaseModel*> list;

};

#endif /* BASELIST_H_ */
