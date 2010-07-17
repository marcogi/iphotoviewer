/*
 * IPhotoPhotosList.h
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#ifndef PHOTOMODEL_H_
#define PHOTOMODEL_H_

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include "model/Photo.h"

class PhotoModel : public QAbstractListModel {
public:
	PhotoModel();
	virtual ~PhotoModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole);

	bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
	bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

	void append(Photo photo);
	Photo get(QModelIndex index);
private:
	QList<Photo> list;

};

#endif /* PHOTOMODEL_H_ */
