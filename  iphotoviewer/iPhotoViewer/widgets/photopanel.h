#ifndef PHOTOPANEL_H
#define PHOTOPANEL_H

#include <QLabel>
#include <QModelIndex>
#include <QGridLayout>
#include <cmath>
#include <QDebug>
#include "model/Photo.h"
#include <QtGui/QWidget>
#include "ui_photopanel.h"
#include "model/BaseList.h"
#include "photoframe.h"

class PhotoPanel : public QWidget
{
    Q_OBJECT

public:
    PhotoPanel(QWidget *parent = 0);
    ~PhotoPanel();

    void setModel(BaseList *list,int width);
protected:
    void resizeEvent(QResizeEvent *event);
private:
    Ui::PhotoPanelClass ui;
    QGridLayout *grid;
    int thumbWidth;
    int count;
};

#endif // PHOTOPANEL_H
