/*
 * IPhotoPhotos.h
 *
 *  Created on: 14.07.2010
 *      Author: david
 */

#ifndef IPHOTOPHOTOS_H_
#define IPHOTOPHOTOS_H_

#include <qdom.h>
#include <qfile.h>

class IPhotoPhotos {
public:
	IPhotoPhotos(int id,QString imagePath,QString thumbPath,QString caption,QString mediaType,QString comment,int roll,int rating);
	IPhotoPhotos();
	virtual ~IPhotoPhotos();

	QString getThumbPath();
	QString getImagePath();
	int getId();
	QString getMediaType();
	QString getCaption();
	QString getComment();
	int getRoll();
	int getRating();

	void setThumbPath(QString value);
	void setImagePath(QString value);
	void setId(int value);
	void setMediaType(QString value);
	void setCaption(QString value);
	void setComment(QString value);
	void setRoll(int value);
	void setRating(int value);
private:
	QString thumbPath;
	QString imagePath;
	int id;
	QString mediaType;
	QString caption;
	QString comment;
	int roll;
	int rating;

};

#endif /* IPHOTOPHOTOS_H_ */
