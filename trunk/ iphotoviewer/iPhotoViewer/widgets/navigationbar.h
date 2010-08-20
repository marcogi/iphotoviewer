#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QtGui/QWidget>
#include "ui_navigationbar.h"

#include "model/Roll.h"
//#include "photopanel.h"

class NavigationBar : public QWidget
{
    Q_OBJECT

public:
    NavigationBar(QWidget *parent = 0);
    ~NavigationBar();
    void setRoll(Roll *roll);
public slots:
	void btnRollsPressed();
	void btnPreviousRoll();
	void btnNextRoll();

private:
    Ui::NavigationBarClass ui;
};

#endif // NAVIGATIONBAR_H
