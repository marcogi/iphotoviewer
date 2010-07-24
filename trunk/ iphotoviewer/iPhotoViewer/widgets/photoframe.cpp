#include "photoframe.h"

PhotoFrame::PhotoFrame(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	this->setFocusPolicy(Qt::StrongFocus);
}

PhotoFrame::~PhotoFrame()
{

}

void PhotoFrame::setPhoto(Photo *p,int width)
{
	this->setGeometry(0,0,width,width);

	int x,y,w,h;

	QPixmap *qp=new QPixmap(p->getThumbPath());

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

	this->setGeometry(0,0,width,width);
	this->setFixedHeight(width);
	this->setFixedWidth(width);
	ui.photoWidget->setGeometry(x,y,w,h);
	ui.defaultBorder->setGeometry(x,y,w,h);
	ui.selectedBorder->setGeometry(x,y,w,h);

	ui.selectedBorder->hide();

	ui.photoWidget->setPixmap(qp->scaled(w,h));
}

void PhotoFrame::focusInEvent(QFocusEvent *focus)
{
	ui.selectedBorder->show();
	ui.defaultBorder->hide();
}

void PhotoFrame::focusOutEvent(QFocusEvent *focus)
{
	ui.defaultBorder->show();
	ui.selectedBorder->hide();
}
