#ifndef PHOTOFRAME_H
#define PHOTOFRAME_H

#include <QtGui/QWidget>
#include <QTextStream>
#include <QPixmap>
#include "ui_photoframe.h"
#include "model/Photo.h"
#include "model/Roll.h"
#include "widgets/photopanel.h"
#include "widgets/photoviewer.h"

// css styles for a frame with round corners and edges.
#define CSS_ROUND "QLabel#photoWidget { border-width: 3px; border-style: solid; border-color: #000000; border-radius: 10px; color: #000000;}"
#define CSS_EDGE "QLabel#photoWidget { border-left-width:0px; border-top-width:0px;border-bottom-width:2px;border-right-width: 2px; border-style: solid; border-color: #000000; border-radius: 0px; color: #000000;}"

#define MODE_ROLL 0
#define MODE_PHOTO 1

#define LABEL_HEIGHT 15
#define LABEL_DIST 5

class PhotoFrame : public QWidget
{
    Q_OBJECT
public:
    PhotoFrame(QWidget *parent = 0);
    ~PhotoFrame();

    void setPhoto(Photo *model,int size);
    void setRoll(Roll *model,int size);
    void resize(int size);
protected:
    void focusInEvent(QFocusEvent *focus);
    void focusOutEvent(QFocusEvent *focus);
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    Ui::PhotoFrameClass ui;
    void setModel(Photo *model,int size,QString caption,int mode);
    void setSize(int size);

    Photo *model;
    Roll *roll;
    QPixmap *thumb;

    int mode,size;
};

#endif // PHOTOFRAME_H
