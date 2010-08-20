#include "navigationbar.h"

NavigationBar::NavigationBar(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.btnRolls,SIGNAL(pressed()),this,SLOT(btnRollsPressed()));
}

NavigationBar::~NavigationBar()
{

}

void NavigationBar::setRoll(Roll *roll)
{
	ui.lblCaption->setText(roll->getRollName());
}

void NavigationBar::btnRollsPressed()
{

}

void NavigationBar::btnPreviousRoll()
{

}

void NavigationBar::btnNextRoll()
{

}
