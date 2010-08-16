/*
 * ClickLabel.cpp
 *
 * Wrapper to an QLabel which emits a clicked-event, when a mousePress event
 * occurs on the label.
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
