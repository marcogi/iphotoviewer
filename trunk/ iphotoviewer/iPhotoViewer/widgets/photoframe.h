#ifndef PHOTOFRAME_H
#define PHOTOFRAME_H

#include <QtGui/QWidget>
#include <QPixmap>
#include "ui_photoframe.h"
#include "model/Photo.h"
#include "widgets/photoviewer.h"

class PhotoFrame : public QWidget
{
    Q_OBJECT
public:
    PhotoFrame(QWidget *parent = 0);
    ~PhotoFrame();

    void setPhoto(Photo *p,int width);
protected:
    void focusInEvent(QFocusEvent *focus);
    void focusOutEvent(QFocusEvent *focus);
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    Ui::PhotoFrameClass ui;
    Photo *p;
};

#endif // PHOTOFRAME_H
