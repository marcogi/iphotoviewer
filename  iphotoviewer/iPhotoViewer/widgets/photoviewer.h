#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QtGui/QWidget>
#include <QScrollArea>
#include "ui_photoviewer.h"
#include "model/Photo.h"
#include "widgets/ClickLabel.h"

class PhotoViewer : public QWidget
{
    Q_OBJECT

public:
    PhotoViewer(QWidget *parent = 0);
    ~PhotoViewer();

    void setPhoto(Photo *p);

private:
    Ui::PhotoViewerClass ui;
    ClickLabel *photo;
public slots:
	void goBack();
};

#endif // PHOTOVIEWER_H
