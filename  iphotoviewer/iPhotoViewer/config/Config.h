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

#define MIN_SLIDER 30
#define MAX_SLIDER 100
#define BASE_SIZE 2

class Config {
public:
	Config();
	virtual ~Config();
	static QString getLibraryPath();
};

#endif /* CONFIG_H_ */
