#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QtGui/QWidget>
#include "ui_photoviewer.h"
#include "model/Photo.h"

class PhotoViewer : public QWidget
{
    Q_OBJECT

public:
    PhotoViewer(QWidget *parent = 0);
    ~PhotoViewer();

    void setPhoto(Photo *p);

private:
    Ui::PhotoViewerClass ui;
};

#endif // PHOTOVIEWER_H
