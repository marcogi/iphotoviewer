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

/**
 * resizes a photoframe (e.g. when using the slider to set the thumbnail-size.
 */
void PhotoFrame::setSize(int size)
{
	int x,y,width,height;
	width=this->thumb->width();
	height=this->thumb->height();

	if(width>height)
	{
		// scale height and width to size...
		height=(height*size)/width;
		width=size;
		x=0;
		y=(size-height)/2;
	}
	else
	{
		width=(width*size)/height;
		height=size;
		y=0;
		x=(size-width)/2;
	}

	this->setGeometry(0,0,size,size);
	this->setFixedHeight(size+LABEL_DIST+LABEL_HEIGHT);
	this->setFixedWidth(size);

	ui.caption->setGeometry(0,y+height+LABEL_DIST,size,LABEL_HEIGHT);
	ui.photoWidget->setGeometry(x,y,width,height);
	ui.defaultBorder->setGeometry(x,y,width,height);
	ui.selectedBorder->setGeometry(x,y,width,height);
}

/**
 * Sets the photo, size and caption of the current PhotoFrame according
 * to the given mode.
 */
void PhotoFrame::setModel(Photo *model,int size,QString caption,int mode)
{
	// persist the given parameters
	this->model=model;
	this->mode=mode;
	this->size=size;

	QPixmap *tmpPixmap;

	// when in roll mode, we want square thumbs...
	if(mode==MODE_ROLL)
	{
		// in roll mode we get the pre-loaded thumb from the roll...
		tmpPixmap=this->roll->getKeyThumb();
		int x,y,w,h;
		if(tmpPixmap->width()>tmpPixmap->height())
		{
			y=0;
			w=tmpPixmap->height();
			h=w;
			x=(tmpPixmap->width()-h)/2;
		}
		else
		{
			x=0;
			w=tmpPixmap->width();
			h=w;
			y=(tmpPixmap->height()-w)/2;
		}
		*tmpPixmap=tmpPixmap->copy(x,y,w,h);
	}
	else if(mode==MODE_PHOTO)
	{
		tmpPixmap=new QPixmap(model->getThumbPath());
	}

	// now we also persist the pixmap...
	this->thumb=tmpPixmap;

	// set the size of this widget...
	this->setSize(size);

	ui.defaultBorder->setToolTip(caption);
	ui.selectedBorder->setToolTip(caption);
	ui.caption->setText(caption);

	// we hide the borders as the widget originally is not selected...
	ui.defaultBorder->hide();
	ui.selectedBorder->hide();

	ui.photoWidget->setStyleSheet(CSS_EDGE);
	ui.photoWidget->setScaledContents(true);
	ui.photoWidget->setPixmap(*tmpPixmap);
}

/**
 * Sets a roll as the model for this widget.
 */
void PhotoFrame::setRoll(Roll *model,int size)
{
	this->roll=model;

	// we store the thumb Pixmap for later reuse
	if(this->roll->getKeyThumb()==0)
		this->roll->setKeyThumb(new QPixmap(model->getKeyPhoto()->getThumbPath()));

	this->setModel(model->getKeyPhoto(),size,model->getRollName(),MODE_ROLL);
}

/**
 * Sets a photo as the model for this widget.
 */
void PhotoFrame::setPhoto(Photo *model,int size)
{
	this->setModel(model,size,model->getCaption(),MODE_PHOTO);
}

/**
 * Invoked when getting the focus. Makes the borders visible and colors
 * the caption yellow.
 */
void PhotoFrame::focusInEvent(QFocusEvent* /*focus*/)
{

	ui.selectedBorder->show();
	ui.defaultBorder->show();

	// selected PhotoFrames have round corners.
	ui.photoWidget->setStyleSheet(CSS_ROUND);

	QPalette palette;
	QBrush brush(QColor(255, 255, 0, 255));
	brush.setStyle(Qt::SolidPattern);
	palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
	palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
	ui.caption->setPalette(palette);
}

/**
 * Invoked when the widget loses focus. Hides the borders and colors
 * the caption gray.
 */
void PhotoFrame::focusOutEvent(QFocusEvent* /*focus*/)
{
	ui.defaultBorder->hide();
	ui.selectedBorder->hide();
	ui.photoWidget->setStyleSheet(CSS_EDGE);

	QPalette palette;
	QBrush brush(QColor(0xDD, 0xDD, 0xDD, 255));
	brush.setStyle(Qt::SolidPattern);
	palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
	palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
	ui.caption->setPalette(palette);
}

/**
 * Invoked when the photoframe is double-clicked. Loads the clicked photo
 * when in photo mode or loads the selected roll when in roll mode.
 */
void PhotoFrame::mouseDoubleClickEvent(QMouseEvent* /*event*/)
{
	if(this->mode==MODE_PHOTO)
	{

		QWidget *scrollArea=this->parentWidget()->parentWidget()->parentWidget();
		QVBoxLayout *contentLayout=(QVBoxLayout*)scrollArea->parentWidget()->layout();
		PhotoViewer *photoViewer=new PhotoViewer(scrollArea);

		int count=contentLayout->count();

		// hide all widgets in the content layout (slider+photopanel)
		// and store them in the photo viewer for restore when closing the
		// the photo viewer widget.
		for(int i=0;i<count;i++)
		{
			QWidget *tmpWidget=contentLayout->itemAt(0)->widget();
			photoViewer->addRestoreWidget(tmpWidget);
			tmpWidget->hide();
			contentLayout->removeWidget(tmpWidget);
		}

		// now we add the photo viewer...
		contentLayout->addWidget(photoViewer);

		photoViewer->setPhoto(this->model,this->thumb);
		photoViewer->show();
	}
	else if(this->mode==MODE_ROLL)
	{
		// if we are in roll mode...we switch the photo frame into photo mode
		// and load the photos from the roll...

		PhotoPanel *photoPanel=(PhotoPanel*)this->parentWidget();
		QGridLayout *gridLayout=(QGridLayout*)photoPanel->layout();

		// now we remove all rolls from the photo-panel...
		int count=gridLayout->count();

		for(int i=0;i<count;i++)
		{
			QWidget *tmpWidget=gridLayout->itemAt(0)->widget();
			tmpWidget->hide();
			gridLayout->removeWidget(tmpWidget);
		}

		photoPanel->setModel(this->roll->getPhotos(),this->size,MODE_PHOTO);
		photoPanel->show();
	}
}

/**
 * Invoked when the slider is used to resize the roll or photo thumbs.
 */
void PhotoFrame::resize(int size)
{
	this->setSize(size);
}
