/*
 * Album.cpp
 *
 *  Created on: 17.07.2010
 *      Author: david
 */

#include "Album.h"

Album::Album() {
	this->id2=0;
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

int Album::getId2()
{
	return id2;
}

QString Album::getAlbumName()
{
	return albumName;
}

void Album::setList(BaseList *value)
{
	list=value;
}

void Album::setId2(int value)
{
	id2=value;
}

void Album::setAlbumName(QString value)
{
	albumName=value;
}

QString Album::getDisplayString()
{
	return this->getAlbumName();
}
