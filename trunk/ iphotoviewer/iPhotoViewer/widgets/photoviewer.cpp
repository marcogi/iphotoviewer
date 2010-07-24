#include "photoviewer.h"

PhotoViewer::PhotoViewer(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	this->setGeometry(0,0,parent->width(),parent->height());
	QRect geo;
	geo=ui.photo->geometry();
	geo.setWidth(parent->width()-20);
	geo.setHeight(parent->height()-60);
}

PhotoViewer::~PhotoViewer()
{

}

void PhotoViewer::setPhoto(Photo *p)
{
	int x,y,h,w,width;
	QPixmap *qp=new QPixmap(p->getImagePath());

	if(ui.photo->width()>ui.photo->height())
		width=ui.photo->height();
	else
		width=ui.photo->width();

	w=qp->width();
	h=qp->height();

	if(w>h)
	{
		h=(h*width)/w;
		w=width;
		x=0;
		y=(width-h)/2;
	}
	else
	{
		w=(w*width)/h;
		h=width;
		y=0;
		x=(width-w)/2;
	}

	ui.photo->setPixmap(qp->scaled(w,h));
}
