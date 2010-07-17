/*
 * Album.cpp
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#include "Album.h"

Album::Album() {
	this->id=0;
	this->albumName="";
}

Album::~Album() {
	// TODO Auto-generated destructor stub
}

/*PhotoModel Album::getList()
{
	return list;
}*/

int Album::getId()
{
	return id;
}

QString Album::getAlbumName()
{
	return albumName;
}

/*void Album::setList(PhotoModel value)
{
	list=value;
}*/

void Album::setId(int value)
{
	id=value;
}

void Album::setAlbumName(QString value)
{
	albumName=value;
}
