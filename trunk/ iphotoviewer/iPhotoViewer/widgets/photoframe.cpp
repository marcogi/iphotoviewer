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
	this->p=p;
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
	this->setFixedHeight(width+20);
	this->setFixedWidth(width);

	ui.defaultBorder->setToolTip(p->getCaption());
	ui.selectedBorder->setToolTip(p->getCaption());

	ui.caption->setGeometry(0,y+h+5,width,15);
	ui.caption->setText(p->getCaption());
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

	QPalette palette;
	QBrush brush(QColor(255, 255, 0, 255));
	brush.setStyle(Qt::SolidPattern);
	palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
	palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
	ui.caption->setPalette(palette);
}

void PhotoFrame::focusOutEvent(QFocusEvent *focus)
{
	ui.defaultBorder->show();
	ui.selectedBorder->hide();

	QPalette palette;
	QBrush brush(QColor(0xDD, 0xDD, 0xDD, 255));
	brush.setStyle(Qt::SolidPattern);
	palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
	palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
	ui.caption->setPalette(palette);
}

void PhotoFrame::mouseDoubleClickEvent(QMouseEvent *event)
{
	// viewport -> scrollArea -> Widget
	QWidget *parent=this->parentWidget()->parentWidget()->parentWidget();
	QVBoxLayout *qvb=(QVBoxLayout*)parent->parentWidget()->layout();//->addWidget(pv);

	PhotoViewer *pv=new PhotoViewer(parent);

	// slider+scrollArea
	int count=qvb->count();
	int i=0;

	for(i=0;i<count;i++)
	{
		QWidget *w1=qvb->itemAt(0)->widget();
		pv->addRestoreWidget(w1);
		w1->hide();
		qvb->removeWidget(w1);
	}

	pv->addRestoreLayout(qvb);

	qvb->addWidget(pv);

	pv->setPhoto(this->p);
	pv->show();
}
