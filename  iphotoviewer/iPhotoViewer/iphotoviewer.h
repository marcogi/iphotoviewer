#ifndef IPHOTOVIEWER_H
#define IPHOTOVIEWER_H

#include <iostream>
#include <QtGui/QMainWindow>
#include "ui_iphotoviewer.h"
#include <QDomDocument>
#include <QFile>
#include <QMessageBox>

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
};

#endif // IPHOTOVIEWER_H
