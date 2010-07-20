/*
 * IPhotoPhotos.h
 *
 *  Created on: 14.07.2010
 *      Author: david
 */

#ifndef PHOTO_H_
#define PHOTO_H_

//#include <QDom>
#include <QFile>
#include <QMetaType>
#include <model/BaseModel.h>

class Photo : public BaseModel {
public:
	Photo(int id,QString imagePath,QString thumbPath,QString caption,QString mediaType,QString comment,int roll,int rating);
	Photo();
	virtual ~Photo();

	QString getThumbPath();
	QString getImagePath();
	int getId2();
	QString getMediaType();
	QString getCaption();
	QString getComment();
	int getRoll();
	int getRating();

	void setThumbPath(QString value);
	void setImagePath(QString value);
	void setId2(int value);
	void setMediaType(QString value);
	void setCaption(QString value);
	void setComment(QString value);
	void setRoll(int value);
	void setRating(int value);

	QString getDisplayString();
private:
	QString thumbPath;
	QString imagePath;
	int id2;
	QString mediaType;
	QString caption;
	QString comment;
	int roll;
	int rating;

};
Q_DECLARE_METATYPE(Photo)

#endif /* PHOTO_H_ */
