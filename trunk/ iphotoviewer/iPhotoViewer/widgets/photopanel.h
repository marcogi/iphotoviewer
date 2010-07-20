#ifndef PHOTOPANEL_H
#define PHOTOPANEL_H

#include <QLabel>
#include <QModelIndex>
#include <QVBoxLayout>
#include "model/Photo.h"
#include <QtGui/QWidget>
#include "ui_photopanel.h"
#include "model/BaseList.h"

class PhotoPanel : public QWidget
{
    Q_OBJECT

public:
    PhotoPanel(QWidget *parent = 0);
    ~PhotoPanel();

    void setModel(BaseList *list,int width);

private:
    Ui::PhotoPanelClass ui;
};

#endif // PHOTOPANEL_H
