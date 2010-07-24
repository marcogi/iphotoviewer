#include "photoviewer.h"

PhotoViewer::PhotoViewer(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	this->photo=new ClickLabel("",this);
	QRect outerGeo=parent->geometry();
	this->setGeometry(0,0,outerGeo.width(),outerGeo.height());

	this->photo->setGeometry(10,50,outerGeo.width()-20,outerGeo.height()-60);
	this->photo->show();

	connect(this->photo, SIGNAL(clicked()), this, SLOT(goBack()));
	connect(ui.goBack, SIGNAL(pressed()), this, SLOT(goBack()));
}

PhotoViewer::~PhotoViewer()
{

}

void PhotoViewer::setPhoto(Photo *p)
{
	int x,y,h,w,width;
	QPixmap *qp=new QPixmap(p->getImagePath());

	if(this->photo->width()>this->photo->height())
		width=this->photo->height();
	else
		width=this->photo->width();

	w=qp->width();
	h=qp->height();

	if(w>h)
	{
		h=(h*width)/w;
		w=width;
		x=10;
		y=(width-h)/2;
	}
	else
	{
		w=(w*width)/h;
		h=width;
		y=50;
		x=(width-w)/2;
	}

	this->photo->setGeometry(x,y,w,h);
	this->photo->setPixmap(qp->scaled(w,h));
}

void PhotoViewer::goBack()
{
	this->hide();
	delete this;
}
