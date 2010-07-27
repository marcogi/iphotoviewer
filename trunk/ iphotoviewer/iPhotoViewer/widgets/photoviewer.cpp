#include "photoviewer.h"

PhotoViewer::PhotoViewer(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	this->photo=new ClickLabel("",this);
	QRect outerGeo=parent->geometry();
	this->setGeometry(0,0,outerGeo.width(),outerGeo.height());

	//this->photo->setGeometry(10,50,outerGeo.width()-20,outerGeo.height()-60);
	//this->photo->show();

	restoreQWidgetList=new QList<QWidget*>();

	connect(this->photo, SIGNAL(clicked()), this, SLOT(goBack()));
	connect(ui.goBack, SIGNAL(pressed()), this, SLOT(goBack()));
}

PhotoViewer::~PhotoViewer()
{

}

void PhotoViewer::setPhoto(Photo *p)
{
	tmp=p;
	int sideBorder=0;
	int minTop=50;
	int maxWidth=this->width()-sideBorder*2;
	int maxHeight=this->height()-minTop-sideBorder;

	QPixmap *qp=new QPixmap(p->getImagePath());
	int origWidth=qp->width();
	int origHeight=qp->height();

	int width,height,x,y;

	float factor=(float)maxWidth/(float)origWidth;
	if((int)(origHeight*factor)>maxHeight)
	{
		factor=(float)maxHeight/(float)origHeight;
		width=(int)(origWidth*factor);
		height=maxHeight;
		x=(maxWidth-width)/2+sideBorder;
		y=minTop+sideBorder;

	}
	else
	{
		width=maxWidth;
		height=(int)(origHeight*factor);
		x=sideBorder;
		y=(maxHeight-height)/2+minTop+sideBorder;
	}

	this->photo->setGeometry(x,y,width,height);
	this->photo->setPixmap(qp->scaled(width,height));
	this->photo->show();
}

void PhotoViewer::goBack()
{
	// remove the PhotoViewer from the Layout...
	this->restoreLayout->removeWidget(this);
	this->hide();

	int i;
	for(i=0;i<this->restoreQWidgetList->count();i++)
	{
		QWidget *w1=this->restoreQWidgetList->at(i);
		w1->show();
		this->restoreLayout->addWidget(w1);
	}


	delete this;
}

void PhotoViewer::resizeEvent (QResizeEvent *event)
{
	//qDebug() << "Xresize";
	this->setPhoto(this->tmp);
}

void PhotoViewer::addRestoreLayout(QLayout *ql)
{
	this->restoreLayout=ql;
}

void PhotoViewer::addRestoreWidget(QWidget *qw)
{
	this->restoreQWidgetList->append(qw);
}
