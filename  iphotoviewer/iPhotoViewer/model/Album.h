/*
 * Album.h
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include <QObject>
//#include <model/PhotoModel.h>

class Album {
public:
	Album();
	virtual ~Album();

	int getId();
	QString getAlbumName();
	//PhotoModel getList();

	void setId(int value);
	void setAlbumName(QString value);
	//void setList(PhotoModel value);
private:
	int id;
	QString albumName;
	//PhotoModel list;
};

#endif /* ALBUM_H_ */
