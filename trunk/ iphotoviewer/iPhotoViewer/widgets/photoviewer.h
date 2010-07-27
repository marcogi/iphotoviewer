#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QtGui/QWidget>
#include <QScrollArea>
#include <QLayout>
#include <QDebug>
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
    void addRestoreLayout(QLayout *ql);
    void addRestoreWidget(QWidget *qw);
protected:
    void resizeEvent (QResizeEvent *event);
private:
    Ui::PhotoViewerClass ui;
    ClickLabel *photo;
    Photo *tmp;
    QList<QWidget*> *restoreQWidgetList;
    QLayout *restoreLayout;
public slots:
	void goBack();
};

#endif // PHOTOVIEWER_H
