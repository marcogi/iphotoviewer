#ifndef PHOTOFRAME_H
#define PHOTOFRAME_H

#define CSS_ROUND "QLabel#photoWidget { border-width: 3px; border-style: solid; border-color: #000000; border-radius: 10px; color: #000000;}"
#define CSS_EDGE "QLabel#photoWidget { border-left-width:0px; border-top-width:0px;border-bottom-width:2px;border-right-width: 2px; border-style: solid; border-color: #000000; border-radius: 0px; color: #000000;}"

#define MODE_ROLL 0
#define MODE_PHOTO 1

#include <QtGui/QWidget>
#include <QTextStream>
#include <QPixmap>
#include "ui_photoframe.h"
#include "model/Photo.h"
#include "model/Roll.h"
#include "widgets/photopanel.h"
#include "widgets/photoviewer.h"

class PhotoFrame : public QWidget
{
    Q_OBJECT
public:
    PhotoFrame(QWidget *parent = 0);
    ~PhotoFrame();

    void setPhoto(Photo *p,int width,QString caption,int mode,Roll *r);
    void resize(int value);
protected:
    void focusInEvent(QFocusEvent *focus);
    void focusOutEvent(QFocusEvent *focus);
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    void setGeo(int width);
    Ui::PhotoFrameClass ui;
    Photo *p;
    QPixmap *thumb;
    int x,y,w,h,wOrig,hOrig,mode,width;
    Roll *r;
};

#endif // PHOTOFRAME_H
