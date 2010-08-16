#ifndef PHOTOPANEL_H
#define PHOTOPANEL_H

#include <QLabel>
#include <QModelIndex>
#include <QGridLayout>
#include <cmath>
#include <QDebug>
#include "model/Photo.h"
#include "model/Roll.h"
#include <QtGui/QWidget>
#include "ui_photopanel.h"
#include "model/BaseList.h"
#include "photoframe.h"

#define SPACING 5

class PhotoPanel : public QWidget
{
    Q_OBJECT

public:
    PhotoPanel(QWidget *parent = 0);
    ~PhotoPanel();

    void setModel(BaseList *list,int size,int mode);
    void resize(int size);
protected:
    void resizeEvent(QResizeEvent *event);
private:
    Ui::PhotoPanelClass ui;
    int size;
};

#endif // PHOTOPANEL_H
