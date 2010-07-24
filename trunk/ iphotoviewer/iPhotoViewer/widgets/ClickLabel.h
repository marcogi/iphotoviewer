/*
 * ClickLabel.h
 *
 *  Created on: 24.07.2010
 *      Author: david
 */

#ifndef CLICKLABEL_H_
#define CLICKLABEL_H_

#include <QLabel>

class ClickLabel : public QLabel
{
	Q_OBJECT
public:
	ClickLabel( const QString & text, QWidget * parent = 0 );
	~ClickLabel(){}

signals:
	void clicked();

protected:
	void mousePressEvent ( QMouseEvent * event ) ;

};

#endif /* CLICKLABEL_H_ */
