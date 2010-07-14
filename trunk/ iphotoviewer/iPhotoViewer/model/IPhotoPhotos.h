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
	IPhotoPhotos();
	virtual ~IPhotoPhotos();
private:
	QString libraryPath;

};

#endif /* IPHOTOPHOTOS_H_ */
