#ifndef PHOTOFRAME_H
#define PHOTOFRAME_H

#include <QtGui/QWidget>
#include <QTextStream>
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
    void resize(int value);
protected:
    void focusInEvent(QFocusEvent *focus);
    void focusOutEvent(QFocusEvent *focus);
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    void setGeo(int width);
    Ui::PhotoFrameClass ui;
    Photo *p;
    int x,y,w,h;
};

#endif // PHOTOFRAME_H
