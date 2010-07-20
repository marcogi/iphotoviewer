/*
 * BaseModel.h
 *
 *  Created on: 18.07.2010
 *      Author: david
 */

#ifndef BASEMODEL_H_
#define BASEMODEL_H_

#include <QObject>
#include <QMetaType>

class BaseModel {
public:
	virtual ~BaseModel() {};
	virtual QString getDisplayString()=0;
	void setId(int value);
	int getId();
private:
	int id;
};
Q_DECLARE_METATYPE(BaseModel*)

#endif /* BASEMODEL_H_ */
