/*
 * Config.cpp
 *
 *  Created on: 24.07.2010
 *      Author: david
 */

#include "Config.h"

Config::Config() {
	// TODO Auto-generated constructor stub

}

Config::~Config() {
	// TODO Auto-generated destructor stub
}

QString Config::getLibraryPath()
{
	//QString libraryPath;
	QDomDocument doc("config");
	QFile file("config.xml");
	if( !file.open( QIODevice::ReadOnly ) ){
		QMessageBox::information( 0, "Info", "IOReadonly" );
		return "-1";}
	if( !doc.setContent( &file ) )
	{
		file.close();
		QMessageBox::information( 0, "Info", "setContent" );
		return "-2";
	}
	file.close();

	QDomElement root = doc.documentElement();
	return root.firstChild().toElement().text();
}
