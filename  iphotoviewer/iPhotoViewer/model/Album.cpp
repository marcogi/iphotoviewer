/*
 * Album.cpp
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#include "Album.h"

Album::Album() {
	this->albumName="";
	this->list=new BaseList();
}

Album::~Album() {
	// TODO Auto-generated destructor stub
}

BaseList* Album::getList()
{
	return list;
}

QString Album::getAlbumName()
{
	return albumName;
}

void Album::setList(BaseList *value)
{
	list=value;
}

void Album::setAlbumName(QString value)
{
	albumName=value;
}

QString Album::getDisplayString()
{
	return this->getAlbumName();
}
