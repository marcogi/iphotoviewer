/*
 * Roll.h
 *
 *  Created on: 20.07.2010
 *      Author: david
 */

#ifndef ROLL_H_
#define ROLL_H_

#include <QObject>
#include "BaseModel.h"
#include "BaseList.h"

class Roll : public BaseModel {
public:
	Roll();
	virtual ~Roll();

	void setRollName(QString rollName);
	QString getRollName();
	void setPhotos(BaseList *photos);
	BaseList* getPhotos();
	void setKeyPhoto(Photo* keyPhoto);
	Photo* getKeyPhoto();
	QString getDisplayString();
private:
	QString rollName;
	BaseList *photos;
	Photo *keyPhoto;
};

#endif /* ROLL_H_ */
