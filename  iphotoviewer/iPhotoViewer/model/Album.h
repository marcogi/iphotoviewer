/*
 * Album.h
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include <QObject>
#include <QMetaType>
#include <model/BaseModel.h>
#include <model/BaseList.h>

class Album : public BaseModel {
public:
	Album();
	virtual ~Album();

	int getId2();
	QString getAlbumName();
	BaseList* getList();

	void setId2(int value);
	void setAlbumName(QString value);
	void setList(BaseList *value);
	QString getDisplayString();
private:
	int id2;
	QString albumName;
	BaseList *list;
};
Q_DECLARE_METATYPE(Album)

#endif /* ALBUM_H_ */
