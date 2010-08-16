#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QtGui/QWidget>
#include <QScrollArea>
#include <QLayout>
#include <QDebug>
#include "ui_photoviewer.h"
#include "model/Photo.h"
#include "widgets/ClickLabel.h"

#define SIDE_BORDER 0

class PhotoViewer : public QWidget
{
    Q_OBJECT

public:
    PhotoViewer(QWidget *parent = 0);
    ~PhotoViewer();

    void setPhoto(Photo *photo,QPixmap *thumbnail);
    void addRestoreWidget(QWidget *restoreWidget);
protected:
    void resizeEvent (QResizeEvent *event);
private:
    Ui::PhotoViewerClass ui;
    void setSize();

    ClickLabel *lblPhoto;
    QList<QWidget*> *list;
public slots:
	void goBack();
};

#endif // PHOTOVIEWER_H
