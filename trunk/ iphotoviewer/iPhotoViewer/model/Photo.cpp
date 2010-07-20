/*
 * IPhotoPhotos.cpp
 *
 *  Created on: 14.07.2010
 *      Author: david
 */

#include "Photo.h"

Photo::Photo() {
	this->imagePath="";
	this->thumbPath="";
	this->caption="";
	this->mediaType="";
	this->comment="";
	this->roll=0;
	this->rating=0;
}

Photo::~Photo() {
	// TODO Auto-generated destructor stub
}

QString Photo::getCaption()
{
	return caption;
}

QString Photo::getComment()
{
	return comment;
}

QString Photo::getImagePath()
{
	return imagePath;
}

QString Photo::getMediaType()
{
	return mediaType;
}

int Photo::getRating()
{
	return rating;
}

int Photo::getRoll()
{
	return roll;
}

QString Photo::getThumbPath()
{
	return thumbPath;
}

void Photo::setCaption(QString value)
{
	caption=value;
}

void Photo::setComment(QString value)
{
	comment=value;
}

void Photo::setImagePath(QString value)
{
	imagePath=value;
}

void Photo::setMediaType(QString value)
{
	mediaType=value;
}

void Photo::setRating(int value)
{
	rating=value;
}

void Photo::setRoll(int value)
{
	roll=value;
}

void Photo::setThumbPath(QString value)
{
	thumbPath=value;
}

QString Photo::getDisplayString()
{
	return caption;
}
