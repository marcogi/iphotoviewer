/*
 * IPhotoPhotos.cpp
 *
 *  Created on: 14.07.2010
 *      Author: david
 */

#include "IPhotoPhotos.h"

IPhotoPhotos::IPhotoPhotos() {
	this->id=0;
	this->imagePath="";
	this->thumbPath="";
	this->caption="";
	this->mediaType="";
	this->comment="";
	this->roll=0;
	this->rating=0;
}

IPhotoPhotos::IPhotoPhotos(int id,QString imagePath,QString thumbPath,QString caption,QString mediaType,QString comment,int roll,int rating)
{
	this->id=id;
	this->imagePath=imagePath;
	this->thumbPath=thumbPath;
	this->caption=caption;
	this->mediaType=mediaType;
	this->comment=comment;
	this->roll=roll;
	this->rating=rating;
}

IPhotoPhotos::~IPhotoPhotos() {
	// TODO Auto-generated destructor stub
}

QString IPhotoPhotos::getCaption()
{
	return caption;
}

QString IPhotoPhotos::getComment()
{
	return comment;
}

int IPhotoPhotos::getId()
{
	return id;
}

QString IPhotoPhotos::getImagePath()
{
	return imagePath;
}

QString IPhotoPhotos::getMediaType()
{
	return mediaType;
}

int IPhotoPhotos::getRating()
{
	return rating;
}

int IPhotoPhotos::getRoll()
{
	return roll;
}

QString IPhotoPhotos::getThumbPath()
{
	return thumbPath;
}

void IPhotoPhotos::setCaption(QString value)
{
	caption=value;
}

void IPhotoPhotos::setComment(QString value)
{
	comment=value;
}

void IPhotoPhotos::setId(int value)
{
	id=value;
}

void IPhotoPhotos::setImagePath(QString value)
{
	imagePath=value;
}

void IPhotoPhotos::setMediaType(QString value)
{
	mediaType=value;
}

void IPhotoPhotos::setRating(int value)
{
	rating=value;
}

void IPhotoPhotos::setRoll(int value)
{
	roll=value;
}

void IPhotoPhotos::setThumbPath(QString value)
{
	thumbPath=value;
}
