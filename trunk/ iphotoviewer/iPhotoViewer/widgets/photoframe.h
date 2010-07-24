#ifndef PHOTOFRAME_H
#define PHOTOFRAME_H

#include <QtGui/QWidget>
#include <QPixmap>
#include "ui_photoframe.h"
#include "model/Photo.h"

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
private:
    Ui::PhotoFrameClass ui;
};

#endif // PHOTOFRAME_H
