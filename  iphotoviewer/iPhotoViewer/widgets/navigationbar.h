#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QtGui/QWidget>
#include "ui_navigationbar.h"

class NavigationBar : public QWidget
{
    Q_OBJECT

public:
    NavigationBar(QWidget *parent = 0);
    ~NavigationBar();

private:
    Ui::NavigationBarClass ui;
};

#endif // NAVIGATIONBAR_H
