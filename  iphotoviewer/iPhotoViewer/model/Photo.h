/*
 * IPhotoPhotos.h
 *
 *  Created on: 14.07.2010
 *      Author: david
 */

#ifndef PHOTO_H_
#define PHOTO_H_

#include <QFile>
#include <model/BaseModel.h>

class Photo : public BaseModel {
public:
	Photo();
	virtual ~Photo();

	QString getThumbPath();
	QString getImagePath();
	QString getMediaType();
	QString getCaption();
	QString getComment();
	int getRoll();
	int getRating();

	void setThumbPath(QString value);
	void setImagePath(QString value);
	void setMediaType(QString value);
	void setCaption(QString value);
	void setComment(QString value);
	void setRoll(int value);
	void setRating(int value);

	QString getDisplayString();
private:
	QString thumbPath;
	QString imagePath;
	QString mediaType;
	QString caption;
	QString comment;
	int roll;
	int rating;

};

#endif /* PHOTO_H_ */
