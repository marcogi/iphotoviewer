#ifndef IPHOTOVIEWER_H
#define IPHOTOVIEWER_H

#include <iostream>
#include <QtGui/QMainWindow>
#include "ui_iphotoviewer.h"
#include <QDomDocument>
#include <QFile>
#include <QMessageBox>

#include "model/BaseList.h"
#include "model/Photo.h"
#include "model/Album.h"

class iPhotoViewer : public QMainWindow
{
    Q_OBJECT

public:
    iPhotoViewer(QWidget *parent = 0);
    ~iPhotoViewer();

private:
    Ui::iPhotoViewerClass ui;

public slots:
	void pushButtonPressed();
	void lstSelectionChanged();
	void lstAlbumSelectionChanged();
};

#endif // IPHOTOVIEWER_H
