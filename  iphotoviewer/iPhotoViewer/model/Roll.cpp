/*
 * Roll.cpp
 *
 *  Created on: 20.07.2010
 *      Author: david
 */

#include "Roll.h"

Roll::Roll() {
	// TODO Auto-generated constructor stub
	this->rollName="";
	this->photos=new BaseList();
	this->keyThumb=0;
}

Roll::~Roll() {
	// TODO Auto-generated destructor stub
}

void Roll::setRollName(QString rollName)
{
	this->rollName=rollName;
}

QString Roll::getRollName()
{
	return this->rollName;
}

void Roll::setPhotos(BaseList *photos)
{
	this->photos=photos;
}

BaseList* Roll::getPhotos()
{
	return this->photos;
}

void Roll::setKeyPhoto(Photo *keyPhoto)
{
	this->keyPhoto=keyPhoto;
}

Photo* Roll::getKeyPhoto()
{
	return this->keyPhoto;
}

QString Roll::getDisplayString()
{
	return this->getRollName();
}

void Roll::setKeyThumb(QPixmap *keyThumb)
{
	this->keyThumb=keyThumb;
}

QPixmap* Roll::getKeyThumb()
{
	return this->keyThumb;
}
