#include "photoviewer.h"

PhotoViewer::PhotoViewer(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	this->lblPhoto=new ClickLabel("",this);

	// set the geometry of the photo viewer...
	QRect outerGeo=parent->geometry();
	this->setGeometry(0,0,outerGeo.width(),outerGeo.height());

	// initialize the restore list...
	list=new QList<QWidget*>();

	// register the click event of the click label...
	connect(this->lblPhoto, SIGNAL(clicked()), this, SLOT(goBack()));
}

PhotoViewer::~PhotoViewer()
{

}

/**
 * Set the size of the photo when a resize event occured.
 */
void PhotoViewer::setSize()
{
	int maxWidth=this->width()-SIDE_BORDER*2;
	int maxHeight=this->height()-SIDE_BORDER*2;

	int originalWidth=this->lblPhoto->pixmap()->width();
	int originalHeight=this->lblPhoto->pixmap()->height();

	int width,height,x,y;

	float factor=(float)maxWidth/(float)originalWidth;
	// now we calc the new dimensions...
	if((int)(originalHeight*factor)>maxHeight)
	{
		factor=(float)maxHeight/(float)originalHeight;
		width=(int)(originalWidth*factor);
		height=maxHeight;
		x=(maxWidth-width)/2+SIDE_BORDER;
		y=SIDE_BORDER;

	}
	else
	{
		width=maxWidth;
		height=(int)(originalHeight*factor);
		x=SIDE_BORDER;
		y=(maxHeight-height)/2+SIDE_BORDER;
	}

	this->lblPhoto->setGeometry(x,y,width,height);
}

/**
 * Set the photo for this photo viewer.
 */
void PhotoViewer::setPhoto(Photo *photo,QPixmap *thumbnail)
{
	this->lblPhoto->setScaledContents(true);
	this->lblPhoto->setPixmap(*thumbnail);
	this->lblPhoto->show();
	QApplication::processEvents();
	// now set the real image for performance...
	QPixmap *pixmap=new QPixmap(photo->getImagePath());
	this->lblPhoto->setPixmap(*pixmap);
	// set the size...
	this->setSize();
}

/**
 * Removes the PhotoViewer before restoring the previous items to the layout.
 */
void PhotoViewer::goBack()
{
	QLayout *contentLayout=this->parentWidget()->layout();
	contentLayout->removeWidget(this);
	this->hide();

	for(int i=0;i<this->list->count();i++)
	{
		QWidget *widget=this->list->at(i);
		widget->show();
		contentLayout->addWidget(widget);
	}

	delete this;
}

/**
 * Resizes the PhotoViewer.
 */
void PhotoViewer::resizeEvent (QResizeEvent* /*event*/)
{
	this->setSize();
}

/**
 * Saves a widget which is going to be restored, when the photoviewer gets
 * closed.
 */
void PhotoViewer::addRestoreWidget(QWidget *restoreWidget)
{
	this->list->append(restoreWidget);
}
