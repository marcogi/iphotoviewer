/*
 * Album.h
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include <QObject>
#include <model/BaseModel.h>
#include <model/BaseList.h>

class Album : public BaseModel {
public:
	Album();
	virtual ~Album();

	QString getAlbumName();
	BaseList* getList();

	void setAlbumName(QString value);
	void setList(BaseList *value);
	QString getDisplayString();
private:
	QString albumName;
	BaseList *list;
};

#endif /* ALBUM_H_ */
