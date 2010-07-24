/*
 * Config.h
 *
 *  Created on: 24.07.2010
 *      Author: david
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <QDomDocument>
#include <QFile>
#include <QMessageBox>

class Config {
public:
	Config();
	virtual ~Config();
	static QString getLibraryPath();
};

#endif /* CONFIG_H_ */
