/*
 * ClickLabel.cpp
 *
 *  Created on: 24.07.2010
 *      Author: david
 */

#include "ClickLabel.h"

ClickLabel::ClickLabel( const QString & text, QWidget * parent )
:QLabel(parent)
{
}

void ClickLabel::mousePressEvent ( QMouseEvent * event )
{
	emit clicked();
}
